#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>
#include <vector>
using namespace std;

#define PI 3.1415926
#pragma pack(1)                     //to make the storage of struct consecutive, instead of align in 4bytes(DWORD)

enum{
    TRANSLATION,
    ROTATION,
    MIRROR,
    SHEAR,
    SCALE
}OPERATION_TYPE;

typedef unsigned short WORD;        //2 bytes
typedef unsigned char BYTE;         //1 bytes
typedef unsigned int DWORD;         //4 bytes unsigned
typedef int LONG;                   //4 bytes
const double matrix1[3][3]={0.299, 0.587, 0.114, -0.147, -0.289, 0.435, 0.615, -0.515, -0.100};//rgb_to_yuv

struct Coord{
    int x, y;
};

typedef struct tagBITMAPFILEHEADER{
    WORD bfType;                    //type of file, should be 0X4D42
    DWORD bfSize;                   //size of whole BMP file
    WORD bfReserved1;               //0
    WORD bfReserved2;               //0
    DWORD bfOffBits;                //offbits from start of BMP file to data part
}BMFH;

typedef struct tagBITMAPINFOHEADER{
    DWORD biSize;               //size of BMIH, 40
    LONG biWidth;               //width of image
    LONG biHeight;              //height of image
    WORD biPlanes;              //planes, 1
    WORD biBitCount;            //bits per pixel 1/2/4/8/16/24/32
    DWORD biCompression;        //way of compression
    DWORD biSizeImage;          //size of image part
    LONG biXPelsPerMeter;
    LONG biYPelsPerMeter;
    DWORD biClrUsed;
    DWORD biClrImportant;

}BMIH;

typedef struct {
    BYTE rgbBlue;
    BYTE rgbGreen;
    BYTE rbgRed;
    BYTE rgbReserved;
}RGBQUAD;

typedef struct{
    BMFH bmfh;
    BMIH bmih;
    RGBQUAD rgbquad[256];
    BYTE *data;
    int LineBytes, WidthBMP, HeightBMP, SizeImageBMP;   
    //LineBytes is to compliment the width given that bytes mod 4 == 0 
    //size of image part, instead of whole bmp
}IMAGE;

IMAGE input, gray, translation, rotation, scale, shear, mirror, steps;

int ReadBMP(FILE *fp, IMAGE *input);
int calc_pos(Coord *initial_coord, int linebytes, int resize_x, int resize_y, int bits);
void update_boundary(Coord *new_coord, vector<int> *boundary);
void resize(IMAGE *initial, vector<double> *parameter, int *resize_x, int *resize_y);
void copyBMP(IMAGE *base, IMAGE *copy);
void WriteBMP(FILE *fp, IMAGE *input);
void color_to_gray(IMAGE *input, IMAGE *gray);
void do_translation(IMAGE *input, IMAGE *translation, int dx, int dy);
void do_rotation(IMAGE *input, IMAGE *rotation, double angle);
void do_mirror(IMAGE *input, IMAGE *mirror, int mx, int my);
void do_shear(IMAGE *input, IMAGE *shear, double tx, double ty);
void do_scale(IMAGE *input, IMAGE *scale, double cx, double cy);

void coord_translation(Coord *initial_coord, int dx, int dy);
void coord_rotation_back(Coord *initial_coord, double angle);
void coord_rotation(Coord *initial_coord, double angle);
void coord_mirror(Coord *initial_coord, int mx, int my);
void coord_shear(Coord *initial_coord, double tx, double ty);
void coord_scale(Coord *initial_coord, double cx, double cy);

int main(){

    //read in the bmp
    FILE *fp;
    fp=fopen("./pic/spike.bmp", "rb");
    if(fp==NULL){
        printf("failed to open the bmp\n");
        return 0;
    }
    if(ReadBMP(fp, &input)==1){
        printf("the file is not a BMP\n");
        return 0;
    }

    color_to_gray(&input, &gray);
    //write grayscale
    FILE *fp_gray;
    fp_gray=fopen("./pic/gray.bmp", "wb");
    if(fp_gray==NULL){
    	printf("failed to open the output bmp");
		return 0;  	
	}
    WriteBMP(fp_gray, &gray);
    fclose(fp_gray); 
    
    int dx=-100, dy=-100;
    do_translation(&input, &translation, dx, dy);
    FILE *fp_translation;
    fp_translation=fopen("./pic/translation.bmp", "wb");
    if(fp_translation==NULL){
    	printf("failed to open the output bmp");
		return 0;  	
	}
    WriteBMP(fp_translation, &translation);
    fclose(fp_translation);

    double angle=210;
    angle = angle / 360 * 2 * PI;
    do_rotation(&input, &rotation, angle);
    FILE *fp_rotation;
    fp_rotation=fopen("./pic/rotation.bmp", "wb");
    if(fp_rotation==NULL){
    	printf("failed to open the output bmp");
		return 0;  	
	}
    WriteBMP(fp_rotation, &rotation);
    fclose(fp_rotation);

    int mx=-1, my=1;
    do_mirror(&input, &mirror, mx, my);
    FILE *fp_mirror;
    fp_mirror=fopen("./pic/mirror.bmp", "wb");
    if(fp_mirror==NULL){
    	printf("failed to open the output bmp");
		return 0;  	
	}
    WriteBMP(fp_mirror, &mirror);
    fclose(fp_mirror); 

    double cx=1, cy=0.5;
    if(cx<=0)    cx=1;
    if(cy<=0)    cy=1;
    do_scale(&input, &scale, cx, cy);
    FILE *fp_scale;
    fp_scale=fopen("./pic/scale.bmp", "wb");
    if(fp_scale==NULL){
    	printf("failed to open the output bmp");
		return 0;  	
	}
    WriteBMP(fp_scale, &scale);
    fclose(fp_scale); 

    double tx=30, ty=0;
    tx = tx / 360 * 2 * PI;
    ty = ty / 360 * 2 * PI;
    do_shear(&input, &shear, tx, ty);
    FILE *fp_shear;
    fp_shear=fopen("./pic/shear.bmp", "wb");
    if(fp_shear==NULL){
    	printf("failed to open the output bmp");
		return 0;  	
	}
    WriteBMP(fp_shear, &shear);
    fclose(fp_shear);


    cout << "success!" << endl;

}

int ReadBMP(FILE *fp, IMAGE *input){

    //read bmfh
    fread(&(input->bmfh), sizeof(BMFH), 1, fp);
    if(input->bmfh.bfType!=0X4D42)
        return 1;
    //read bmih
    fread(&(input->bmih), sizeof(BMIH), 1, fp);
    input->WidthBMP=input->bmih.biWidth;                    //get width, while complement to 4 bytes
    input->HeightBMP=input->bmih.biHeight;                  //get height
    // usually useless. only be used when BMIH is not complete
    int ori_offbit=input->bmfh.bfOffBits;
    if(input->bmih.biSizeImage==0)                          //get the size of the image if there's no direct size
        input->bmih.biSizeImage=input->bmfh.bfSize-input->bmfh.bfOffBits;
    input->SizeImageBMP=input->bmih.biSizeImage;
    if(input->bmih.biBitCount==8){
        input->bmih.biSize=40;
        input->bmfh.bfOffBits=54+1024;
        input->bmfh.bfSize=input->bmfh.bfOffBits+input->SizeImageBMP;
    }else{
        input->bmih.biSize=40;
        input->bmfh.bfOffBits=54;
        input->bmfh.bfSize=input->bmfh.bfOffBits+input->SizeImageBMP;
    }


    input->LineBytes=(input->bmih.biWidth*(input->bmih.biBitCount/8)+3)/4*4;
    //cout << input->bmih.biBitCount << endl << input->WidthBMP << endl << input->LineBytes << endl;
    
    if(input->bmih.biBitCount==8){
        cout << input->bmih.biBitCount << endl;
        fread(input->rgbquad, sizeof(RGBQUAD), 256, fp);    //read rgbquad
    }                           //only when biBitCount=1/2/4/8 does the image has a rgbquad
    fseek(fp, ori_offbit, SEEK_SET);
    printf("%d %d %d %d %d %d %d\n", input->bmfh.bfOffBits, input->bmfh.bfSize, input->bmih.biBitCount, input->bmih.biHeight, input->bmih.biWidth, input->bmih.biSizeImage, input->bmih.biSize);

    //read data
    input->data=new BYTE[input->SizeImageBMP];
    fread(input->data, sizeof(BYTE), input->SizeImageBMP, fp);
    fclose(fp);

    return 0;
}

void copyBMP(IMAGE *base, IMAGE *copy){

    memcpy(&(copy->bmfh), &(base->bmfh), sizeof(BMFH));          //copy the bmp file header
    memcpy(&(copy->bmih), &(base->bmih), sizeof(BMIH));          //copy the bmp information header
    copy->bmih.biBitCount=8;
    copy->WidthBMP=base->WidthBMP;
    copy->HeightBMP=base->HeightBMP;
    copy->LineBytes=(copy->WidthBMP+3)/4*4;                     //bytes mod 4 = 0. compliment
	copy->bmih.biSizeImage=copy->LineBytes*copy->HeightBMP;     //calculate the size of the image data part
    copy->SizeImageBMP=copy->bmih.biSizeImage;
    copy->bmfh.bfSize=copy->bmfh.bfOffBits+copy->bmih.biSizeImage;//calculate the size of the whole bmp file
    copy->data=new BYTE[copy->bmih.biSizeImage];

	memset(copy->data, 0, sizeof(BYTE)*copy->SizeImageBMP);
	for(int i=0;i<256;i++){                                     //initialize the rgbquad
		copy->rgbquad[i].rgbBlue=i;
		copy->rgbquad[i].rgbGreen=i;
		copy->rgbquad[i].rbgRed=i;
	}
	for(int i=0;i<copy->HeightBMP;i++){
		for(int j=0;j<copy->WidthBMP;j++){
			copy->data[copy->LineBytes*i+j]=base->data[base->LineBytes*i+j];
		}
	}

}

int calc_pos(Coord *initial_coord, int resize_x, int resize_y, int bits, int linebytes){

    int x = initial_coord->x;
    int y = initial_coord->y;
    x -= resize_x;
    y -= resize_y;

    return x * linebytes + y*bits;
}

void update_boundary(Coord *new_coord, vector<int> *boundary){
        if(new_coord->x > boundary->at(2))  boundary->at(2)=new_coord->x;
        if(new_coord->x < boundary->at(0))  boundary->at(0)=new_coord->x;
        if(new_coord->y > boundary->at(3))  boundary->at(3)=new_coord->y;
        if(new_coord->y < boundary->at(1))  boundary->at(1)=new_coord->y;
}

void resize(IMAGE *initial, vector<double> *parameter, int *resize_x, int *resize_y){

    // int minx=0, miny=0, maxx=initial->bmih.biHeight, maxy=initial->bmih.biWidth;
    vector<int> boundary={0,0,initial->bmih.biHeight,initial->bmih.biWidth};//minx,miny,maxx,maxy
    //in laptop:
	Coord new_vertices[4]={{0,0}, {0, boundary[3]}, {boundary[2], 0}, {boundary[2], boundary[3]}};//lu, ld, ru, rd
    switch(OPERATION_TYPE){
        case TRANSLATION:
            for(int i=0;i<4;i++)
                coord_translation(&new_vertices[i], parameter->at(0), parameter->at(1));
            break;
        case ROTATION:
            for(int i=0;i<4;i++)
            	coord_rotation(&new_vertices[i], parameter->at(0));
			break;
        case MIRROR:
            for(int i=0;i<4;i++)
                coord_mirror(&new_vertices[i], parameter->at(0), parameter->at(1));
			break;
        case SHEAR:
            for(int i=0;i<4;i++)
                coord_shear(&new_vertices[i], parameter->at(0), parameter->at(1));
        	break;
        case SCALE:
            for(int i=0;i<4;i++)
                coord_scale(&new_vertices[i], parameter->at(0), parameter->at(1));
			break;
        default:
            cout << "something went wrong in operation type." << endl; break;
    }
    //if(OPERATION_TYPE==SCALE)
    //	boundary[0]=boundary[1]=boundary[2]=boundary[3]=0;
    for(int i=0;i<4;i++)    
		update_boundary(&new_vertices[i], &boundary);
    initial->HeightBMP = initial->bmih.biHeight = boundary[2]-boundary[0];
    initial->WidthBMP  = initial->bmih.biWidth  = boundary[3]-boundary[1];
    initial->LineBytes = (initial->WidthBMP * (initial->bmih.biBitCount / 8) + 3) / 4 * 4;
    initial->SizeImageBMP = initial->bmih.biSizeImage = initial->HeightBMP * initial->LineBytes;
    initial->bmfh.bfSize = initial->bmfh.bfOffBits + initial->SizeImageBMP;

    *resize_x = boundary[0];
    *resize_y = boundary[1];

    return;
}

void color_to_gray(IMAGE *rgb, IMAGE *gray){

    memcpy(&(gray->bmfh), &(rgb->bmfh), sizeof(BMFH));          //copy the bmp file header
    memcpy(&(gray->bmih), &(rgb->bmih), sizeof(BMIH));          //copy the bmp information header
    gray->bmfh.bfOffBits+=1024;                                 //again calculate the offsit, given the rgbquad
    gray->bmih.biBitCount=8;
    gray->WidthBMP=rgb->WidthBMP;
    gray->HeightBMP=rgb->HeightBMP;
    gray->LineBytes=(gray->WidthBMP+3)/4*4;                     //bytes mod 4 = 0. compliment
	gray->bmih.biSizeImage=gray->LineBytes*gray->HeightBMP;     //calculate the size of the image data part
    gray->SizeImageBMP=gray->bmih.biSizeImage;
    gray->bmfh.bfSize=gray->bmfh.bfOffBits+gray->bmih.biSizeImage;//calculate the size of the whole bmp file
    gray->data=new BYTE[gray->bmih.biSizeImage];

	memset(gray->data, 0, sizeof(BYTE)*gray->SizeImageBMP);
	for(int i=0;i<256;i++){                                     //initialize the rgbquad
		gray->rgbquad[i].rgbBlue=i;
		gray->rgbquad[i].rgbGreen=i;
		gray->rgbquad[i].rbgRed=i;
	}
	
	for(int i=0;i<gray->HeightBMP;i++){                         //go through each pixel
		for(int j=0;j<gray->WidthBMP;j++){                      //grayscale only needs to calculate Y
            double Y=rgb->data[rgb->LineBytes*i+j*3]*0.299+rgb->data[rgb->LineBytes*i+j*3+1]*0.587+rgb->data[rgb->LineBytes*i+j*3+2]*0.114;
			if(Y>255)Y=255;
            if(Y<0)Y=0;
			gray->data[gray->LineBytes*i+j]=Y;                  //double -> int to improve precision
		}
	}


    return;
}

void coord_translation(Coord *initial_coord, int dx, int dy){
    initial_coord->x+=dx;
    initial_coord->y+=dy;
}

void coord_rotation(Coord *initial_coord, double angle){
    //cout << cos(angle) << " " << sin(angle) << endl;
    double x = initial_coord->x, y = initial_coord->y;
    initial_coord->x = x * cos(angle) - y * sin(angle);
    initial_coord->y = x * sin(angle) + y * cos(angle);
}

void coord_rotation_back(Coord *initial_coord, double angle){
    double x = initial_coord->x, y = initial_coord->y;
    initial_coord->x = x * cos(angle) + y * sin(angle);
    initial_coord->y = y * cos(angle) - x * sin(angle);
}

void coord_mirror(Coord *initial_coord, int mx, int my){
    initial_coord->x *= mx;
    initial_coord->y *= my;
}

void coord_scale(Coord *initial_coord, double cx, double cy){
    if(cx<0)    cx = 1;
    if(cy<0)    cy = 1;
    initial_coord->x *= cx;
    initial_coord->y *= cy;
}

void coord_shear(Coord *initial_coord, double dx, double dy){
    double x = initial_coord->x, y = initial_coord->y;
    initial_coord->x = x + y * dx;
    initial_coord->y = x * dy + y;
}

void do_translation(IMAGE *input, IMAGE *output, int dx, int dy){

    memcpy(&(output->bmfh), &(input->bmfh), sizeof(BMFH));          //copy the bmp file header
    memcpy(&(output->bmih), &(input->bmih), sizeof(BMIH));
    vector<double> parameter;
    parameter.push_back(dx);
    parameter.push_back(dy);
    OPERATION_TYPE=TRANSLATION;
    int resize_x, resize_y;
    resize(output, &parameter, &resize_x, &resize_y);

    output->data = new BYTE[output->SizeImageBMP];
    // output->LineBytes = (input->WidthBMP * (input->bmih.biBitCount / 8) + 3) / 4 * 4;
    // cout << "offbits " << output->bmfh.bfOffBits << " totalsize " << output->bmfh.bfSize << " imgae size " << output->bmih.biSizeImage << " bits " << output->bmih.biBitCount << endl; 
    for(int i=0;i<output->bmih.biHeight;i++)
        for(int j=0;j<output->LineBytes;j++)
            output->data[i*output->LineBytes+j]=255;
    
   for(int i=0;i<input->HeightBMP;i++){
       for(int j=0;j<input->WidthBMP;j++){
            Coord now={i, j};
            int  in_pos=calc_pos(&now, 0, 0, input->bmih.biBitCount/8, input->LineBytes);
            coord_translation(&now, dx, dy);
            //if(i<10&&j<10)
            //    cout << now.x << " " << now.y << endl;

            int out_pos=calc_pos(&now, resize_x, resize_y, output->bmih.biBitCount/8, output->LineBytes);
//            if(i<10&&j<10)
//                cout << in_pos << " " << out_pos << endl;
            output->data[out_pos]=input->data[in_pos];
            output->data[out_pos+1]=input->data[in_pos+1];
            output->data[out_pos+2]=input->data[in_pos+2];
       }
   }

}

void do_rotation(IMAGE *input, IMAGE *output, double angle){    //wrong with interpolation!

    memcpy(&(output->bmfh), &(input->bmfh), sizeof(BMFH));          //copy the bmp file header
    memcpy(&(output->bmih), &(input->bmih), sizeof(BMIH));
    vector<double> parameter;
    parameter.push_back(angle);
    OPERATION_TYPE=ROTATION;
    int resize_x, resize_y;
    resize(output, &parameter, &resize_x, &resize_y);
	cout << input->HeightBMP << " " << input->WidthBMP << " " << output->HeightBMP << " " << output->WidthBMP << endl; 
    output->data = new BYTE[output->SizeImageBMP];
    // output->LineBytes = (input->WidthBMP * (input->bmih.biBitCount / 8) + 3) / 4 * 4;
    // cout << "offbits " << output->bmfh.bfOffBits << " totalsize " << output->bmfh.bfSize << " imgae size " << output->bmih.biSizeImage << " bits " << output->bmih.biBitCount << endl; 
    for(int i=0;i<output->bmih.biHeight;i++)
        for(int j=0;j<output->LineBytes;j++)
            output->data[i*output->LineBytes+j]=255;
    
   for(int i=0;i<input->HeightBMP;i++){
       for(int j=0;j<input->WidthBMP;j++){
            Coord now={i, j};
            int  in_pos=calc_pos(&now, 0, 0, input->bmih.biBitCount/8, input->LineBytes);
            coord_rotation(&now, angle);
            //if(i<10&&j<10)
            //    cout << now.x << " " << now.y << endl;
            int out_pos=calc_pos(&now, resize_x, resize_y, output->bmih.biBitCount/8, output->LineBytes);
            //if(i<10&&j<10)
            //    cout << in_pos << " " << out_pos << endl;
            output->data[out_pos]=input->data[in_pos];
            output->data[out_pos+1]=input->data[in_pos+1];
            output->data[out_pos+2]=input->data[in_pos+2];
       }
   }
    for(int i=0;i<output->HeightBMP;i++){
       for(int j=0;j<output->WidthBMP;j++){
			Coord back={i, j};
            int out_pos=calc_pos(&back, 0, 0, output->bmih.biBitCount/8, output->LineBytes);
            back.x+=resize_x;
            back.y+=resize_y;
            coord_rotation_back(&back, angle);
            if(back.x<0||back.y<0||back.x>=input->HeightBMP||back.y>=input->WidthBMP)
                continue;
            int in_pos=calc_pos(&back, 0, 0, input->bmih.biBitCount/8, input->LineBytes);
            output->data[out_pos]=input->data[in_pos];
            output->data[out_pos+1]=input->data[in_pos+1];
            output->data[out_pos+2]=input->data[in_pos+2];
       }
   }
    
}

void do_mirror(IMAGE *input, IMAGE *output, int mx, int my){
    
    memcpy(&(output->bmfh), &(input->bmfh), sizeof(BMFH));          //copy the bmp file header
    memcpy(&(output->bmih), &(input->bmih), sizeof(BMIH));
    vector<double> parameter;
    parameter.push_back(mx);
    parameter.push_back(my);
    OPERATION_TYPE=MIRROR;
    int resize_x, resize_y;
    resize(output, &parameter, &resize_x, &resize_y);

    output->data = new BYTE[output->SizeImageBMP];
    // output->LineBytes = (input->WidthBMP * (input->bmih.biBitCount / 8) + 3) / 4 * 4;
    // cout << "offbits " << output->bmfh.bfOffBits << " totalsize " << output->bmfh.bfSize << " imgae size " << output->bmih.biSizeImage << " bits " << output->bmih.biBitCount << endl; 
    for(int i=0;i<output->bmih.biHeight;i++) 
        for(int j=0;j<output->LineBytes;j++)
            output->data[i*output->LineBytes+j]=255;
    
   for(int i=0;i<input->HeightBMP;i++){
       for(int j=0;j<input->WidthBMP;j++){
            Coord now={i, j};
            int  in_pos=calc_pos(&now, 0, 0, input->bmih.biBitCount/8, input->LineBytes);
            coord_mirror(&now, mx, my);
            int out_pos=calc_pos(&now, resize_x, resize_y, output->bmih.biBitCount/8, output->LineBytes);
            output->data[out_pos]=input->data[in_pos];
            output->data[out_pos+1]=input->data[in_pos+1];
            output->data[out_pos+2]=input->data[in_pos+2];
       }
   }

}

void do_scale(IMAGE *input, IMAGE *output, double cx, double cy){
        
    memcpy(&(output->bmfh), &(input->bmfh), sizeof(BMFH));          //copy the bmp file header
    memcpy(&(output->bmih), &(input->bmih), sizeof(BMIH));
    vector<double> parameter;
    parameter.push_back(cx);
    parameter.push_back(cy);
    OPERATION_TYPE=SCALE;
    int resize_x, resize_y;
    resize(output, &parameter, &resize_x, &resize_y);

    output->data = new BYTE[output->SizeImageBMP];
    // output->LineBytes = (input->WidthBMP * (input->bmih.biBitCount / 8) + 3) / 4 * 4;
    // cout << "offbits " << output->bmfh.bfOffBits << " totalsize " << output->bmfh.bfSize << " imgae size " << output->bmih.biSizeImage << " bits " << output->bmih.biBitCount << endl; 
    for(int i=0;i<output->bmih.biHeight;i++) 
        for(int j=0;j<output->LineBytes;j++)
            output->data[i*output->LineBytes+j]=255;
    
//   for(int i=0;i<input->HeightBMP;i++){
//       for(int j=0;j<input->WidthBMP;j++){
//            Coord now={i, j};
//            int  in_pos=calc_pos(&now, 0, 0, input->bmih.biBitCount/8, input->LineBytes);
//            coord_scale(&now, cx, cy);
//            for(int ii=0;ii<cx;ii++){
//                for(int jj=0;jj<cy;jj++){
//                    Coord now_scale;
//                    now_scale.x=now.x+ii;
//                    now_scale.y=now.y+jj;
//                    int out_pos=calc_pos(&now_scale, resize_x, resize_y, output->bmih.biBitCount/8, output->LineBytes);
//                    output->data[out_pos]=input->data[in_pos];
//                    output->data[out_pos+1]=input->data[in_pos+1];
//                    output->data[out_pos+2]=input->data[in_pos+2];
//                }
//            }

//       }
//   }
    for(int i=0;i<output->HeightBMP;i++){
       for(int j=0;j<output->WidthBMP;j++){
            Coord now={i, j};
            int  in_pos=calc_pos(&now, 0, 0, output->bmih.biBitCount/8, output->LineBytes);
            // coord_scale(&now, cx, cy);
            double ix=now.x, iy=now.y;
            ix/=cx, iy/=cy;
            now.x=(int)ix, now.y=(int)iy;
            if(now.x<0||now.y<0||now.x>=input->HeightBMP||now.y>=input->WidthBMP) continue;
            int out_pos=calc_pos(&now, 0, 0, input->bmih.biBitCount/8, input->LineBytes);
            output->data[in_pos]=input->data[out_pos];
            output->data[in_pos+1]=input->data[out_pos+1];
            output->data[in_pos+2]=input->data[out_pos+2];
        }
    }
}

void do_shear(IMAGE *input, IMAGE *output, double dx, double dy){

    memcpy(&(output->bmfh), &(input->bmfh), sizeof(BMFH));          //copy the bmp file header
    memcpy(&(output->bmih), &(input->bmih), sizeof(BMIH));
    vector<double> parameter;
    parameter.push_back(dx);
    parameter.push_back(dy);
    OPERATION_TYPE=SHEAR;
    int resize_x, resize_y;
    resize(output, &parameter, &resize_x, &resize_y);

    output->data = new BYTE[output->SizeImageBMP];
    // output->LineBytes = (input->WidthBMP * (input->bmih.biBitCount / 8) + 3) / 4 * 4;
    // cout << "offbits " << output->bmfh.bfOffBits << " totalsize " << output->bmfh.bfSize << " imgae size " << output->bmih.biSizeImage << " bits " << output->bmih.biBitCount << endl; 
    for(int i=0;i<output->bmih.biHeight;i++) 
        for(int j=0;j<output->LineBytes;j++)
            output->data[i*output->LineBytes+j]=255;
    
   for(int i=0;i<input->HeightBMP;i++){
       for(int j=0;j<input->WidthBMP;j++){
            Coord now={i, j};
            int  in_pos=calc_pos(&now, 0, 0, input->bmih.biBitCount/8, input->LineBytes);
            coord_shear(&now, dx, dy);
            int out_pos=calc_pos(&now, resize_x, resize_y, output->bmih.biBitCount/8, output->LineBytes);
            output->data[out_pos]=input->data[in_pos];
            output->data[out_pos+1]=input->data[in_pos+1];
            output->data[out_pos+2]=input->data[in_pos+2];
       }
   }

}

void WriteBMP(FILE *fp, IMAGE *output){

    fwrite(&(output->bmfh), sizeof(BMFH), 1, fp);
    fwrite(&(output->bmih), sizeof(BMIH), 1, fp);
    if(output->bmih.biBitCount==8)                              //only write the rgbquad when biBitCount=1/2/4/8
        fwrite(output->rgbquad, sizeof(RGBQUAD), 256, fp);

    fwrite(output->data, sizeof(BYTE), output->SizeImageBMP, fp);

    return;
}
