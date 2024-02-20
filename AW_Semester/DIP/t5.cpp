#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>
#include <vector>
using namespace std;

#pragma pack(1)                     //to make the storage of struct consecutive, instead of align in 4bytes(DWORD)

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

typedef struct{
    int size=5, coef_sum=0, filter_num;
    vector<int> coef[5]={
        {1,1,1,  1,1,1,  1,1,1}, //only for size=3*3
        {1,5,1,  5,1,5,  1,5,1}, //only for size=3*3
        {1,1,1,1,1,  1,1,1,1,1,  1,1,1,1,1,  1,1,1,1,1,  1,1,1,1,1}, //only for size=5*5
        {1,5,1,5,1,  5,1,5,1,5,  1,5,1,5,1,  5,1,5,1,5,  1,5,1,5,1}, //only for size=5*5
        {1,1,1,1,1,1,1, 1,1,1,1,1,1,1, 1,1,1,1,1,1,1, 1,1,1,1,1,1,1, 1,1,1,1,1,1,1, 1,1,1,1,1,1,1, 1,1,1,1,1,1,1}
    };
    Coord* pos;
}Filter_spatial;

typedef struct{
    int size=3, filter_num;
    vector<int> coef[4]={{0,1,0,  1,-4,1,  0,1,0}, {0,-1,0,  -1,4,-1,  0,-1,0}, {1,1,1,  1,-8,1,  1,1,1}, {-1,-1,-1,  -1,8,-1,  -1,-1,-1}};
    Coord* pos;
}Filter_laplacian;

IMAGE input, gray, spatial_filtering, laplacian_filtering;

int ReadBMP(FILE *fp, IMAGE *input);
void WriteBMP(FILE *fp, IMAGE *input);
void CopyGray(IMAGE *base, IMAGE *copy);
void CopyColor(IMAGE *base, IMAGE *copy);
void color_to_gray(IMAGE *input, IMAGE *gray);
int  calc_pos(Coord *initial_coord, int resize_x, int resize_y, int bits, int linebytes);

void Do_spatial_filtering1(IMAGE *input, IMAGE *spatial_filtering);
void Do_spatial_filtering2(IMAGE *input, IMAGE *spatial_filtering);
void Do_laplacian_filtering(IMAGE *input, IMAGE *laplacian_filtering);

int main(){

    //read in the bmp
    FILE *fp;
    fp=fopen("./pic/vio.bmp", "rb");
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

    Do_spatial_filtering2(&input, &spatial_filtering);
    //write spatial_filteringscale
    FILE *fp_spatial_filtering;
    fp_spatial_filtering=fopen("./pic/spatial_filtering.bmp", "wb");
    if(fp_spatial_filtering==NULL){
    	printf("failed to open the output bmp");
		return 0;  	
	}
    WriteBMP(fp_spatial_filtering, &spatial_filtering);
    fclose(fp_spatial_filtering);


    Do_laplacian_filtering(&input, &laplacian_filtering);
    //write laplacian_filteringscale
    FILE *fp_laplacian_filtering;
    fp_laplacian_filtering=fopen("./pic/laplacian_filtering.bmp", "wb");
    if(fp_laplacian_filtering==NULL){
    	printf("failed to open the output bmp");
		return 0;  	
	}
    WriteBMP(fp_laplacian_filtering, &laplacian_filtering);
    fclose(fp_laplacian_filtering); 
    

    cout << "success!" << endl;

}

void Do_spatial_filtering1(IMAGE *input, IMAGE *output){

    IMAGE SFgray;

    if(input->bmih.biBitCount!=8)
        color_to_gray(input, &SFgray);
    else
        CopyGray(input, &SFgray);

    Filter_spatial SpatialFilter;
    SpatialFilter.size=5;
    SpatialFilter.filter_num=2;
    SpatialFilter.pos = new Coord[SpatialFilter.size*SpatialFilter.size]; 
    for(int i=0;i<SpatialFilter.size;i++)
        for(int j=0;j<SpatialFilter.size;j++){
            SpatialFilter.pos[i*SpatialFilter.size+j].x = i-SpatialFilter.size/2;
            SpatialFilter.pos[i*SpatialFilter.size+j].y = j-SpatialFilter.size/2;
        }

    for(int i=0;i<SpatialFilter.coef[SpatialFilter.filter_num].size();i++)
        SpatialFilter.coef_sum+=SpatialFilter.coef[SpatialFilter.filter_num][i];
    cout << SpatialFilter.coef_sum << endl;
    
    for(int i=0;i<SFgray.HeightBMP;i++){
        for(int j=0;j<SFgray.WidthBMP;j++){
            int ori_pixel, new_pixel=0;
            Coord temp;
            for(int k=0;k<SpatialFilter.size*SpatialFilter.size;k++){
                temp.x=i+SpatialFilter.pos[k].x;
                temp.y=j+SpatialFilter.pos[k].y;
                if(temp.x<0||temp.y<0||temp.x>=SFgray.HeightBMP||temp.y>=SFgray.WidthBMP) ori_pixel=0;
                else{
                    if(input->bmih.biBitCount==8)   ori_pixel=input->data[temp.x*SFgray.LineBytes+temp.y];
                    else    ori_pixel=input->data[temp.x*input->LineBytes+temp.y*3]*0.299+input->data[temp.x*input->LineBytes+temp.y*3+1]*0.587+input->data[temp.x*input->LineBytes+temp.y*3+2]*0.114;
                }    
                new_pixel+=SpatialFilter.coef[SpatialFilter.filter_num][k]*ori_pixel;
            }
            new_pixel/=SpatialFilter.coef_sum;
            if(new_pixel>255){
                cout << "emmbig" << endl;
                new_pixel=255;
            }
            if(new_pixel<0){
                cout << "emmsmall" << endl;
                new_pixel=0;
            }
            SFgray.data[i*SFgray.LineBytes+j]=new_pixel;
        }
    }

    if(input->bmih.biBitCount==8){
        CopyGray(&SFgray, output);
    }else{    
        CopyColor(input, output);
        for(int i=0;i<output->HeightBMP;i++){
            for(int j=0;j<output->WidthBMP;j++){
                double R, G, B, Y, U, V;
                B=input->data[input->LineBytes*i+j*3];                  //store in BGR order read B,G,R
                G=input->data[input->LineBytes*i+j*3+1];
                R=input->data[input->LineBytes*i+j*3+2];
                U=-0.147*R-0.289*G+0.435*B;
                V=0.615*R-0.515*G-0.100*B;
                Y=SFgray.data[SFgray.LineBytes*i+j];

                R=Y+1.4075*V;                                       //calculate R,G,B 
                G=Y-0.3455*U-0.7169*V;
                B=Y+1.779*U;
                
                if(R>255)R=255;
                if(R<0)R=0;
                if(G>255)G=255;
                if(G<0)G=0;
                if(B>255)B=255;
                if(B<0)B=0;

                output->data[output->LineBytes*i+j*3]=B;          //write in data
                output->data[output->LineBytes*i+j*3+1]=G;
                output->data[output->LineBytes*i+j*3+2]=R;
            }
        }
    }
}

void Do_spatial_filtering2(IMAGE *input, IMAGE *output){

    if(input->bmih.biBitCount!=8)   CopyColor(input, output);
    else    CopyGray(input, output);
    
    Filter_spatial SpatialFilter;
    SpatialFilter.size=7;
    SpatialFilter.filter_num=4;
    SpatialFilter.pos = new Coord[SpatialFilter.size*SpatialFilter.size]; 
    for(int i=0;i<SpatialFilter.size;i++)
        for(int j=0;j<SpatialFilter.size;j++){
            SpatialFilter.pos[i*SpatialFilter.size+j].x = i-SpatialFilter.size/2;
            SpatialFilter.pos[i*SpatialFilter.size+j].y = j-SpatialFilter.size/2;
        }

    for(int i=0;i<SpatialFilter.coef[SpatialFilter.filter_num].size();i++)
        SpatialFilter.coef_sum+=SpatialFilter.coef[SpatialFilter.filter_num][i];
    cout << SpatialFilter.coef_sum << endl;
    
    for(int i=0;i<output->HeightBMP;i++){
        for(int j=0;j<output->WidthBMP;j++){
            int ori_pixel, tempx, tempy;
            int B=0, G=0, R=0, Y=0;

            for(int k=0;k<SpatialFilter.size*SpatialFilter.size;k++){
                tempx=i+SpatialFilter.pos[k].x;
                tempy=j+SpatialFilter.pos[k].y;
                if(tempx<0||tempy<0||tempx>=output->HeightBMP||tempy>=output->WidthBMP) continue;
                if(input->bmih.biBitCount==8)
                    Y+=input->data[tempx*output->LineBytes+tempy]*SpatialFilter.coef[SpatialFilter.filter_num][k];
                else{
					//cout << SpatialFilter.coef[SpatialFilter.filter_num][k] << endl;
                    B+=input->data[tempx*output->LineBytes+tempy*3+0]*SpatialFilter.coef[SpatialFilter.filter_num][k];
                    G+=input->data[tempx*output->LineBytes+tempy*3+1]*SpatialFilter.coef[SpatialFilter.filter_num][k];
                    R+=input->data[tempx*output->LineBytes+tempy*3+2]*SpatialFilter.coef[SpatialFilter.filter_num][k];
                }
            }
			
            Y/=SpatialFilter.coef_sum;
            B/=SpatialFilter.coef_sum;
            G/=SpatialFilter.coef_sum;
            R/=SpatialFilter.coef_sum;
			if(Y<0)	Y=0;	if(B<0)	B=0;	if(G<0)	G=0;	if(R<0)	R=0;
			if(Y>255) Y=255;	if(B>255) B=255;	if(G>255) G=255;	if(R>255) R=255;

            if(input->bmih.biBitCount==8)
                output->data[i*input->LineBytes+j]=Y;
            else{
                output->data[i*input->LineBytes+j*3+0]=B;
                output->data[i*input->LineBytes+j*3+1]=G;
                output->data[i*input->LineBytes+j*3+2]=R;
            }
            
        }
    }

}

void Do_laplacian_filtering(IMAGE *input, IMAGE *output){

    if(input->bmih.biBitCount!=8)   CopyColor(input, output);
    else    CopyGray(input, output);
    
    int c;
    Filter_laplacian LaplacianFilter;
    LaplacianFilter.size=3;
    LaplacianFilter.filter_num=3;
    LaplacianFilter.pos = new Coord[LaplacianFilter.size*LaplacianFilter.size]; 
    for(int i=0;i<LaplacianFilter.size;i++)
        for(int j=0;j<LaplacianFilter.size;j++){
            LaplacianFilter.pos[i*LaplacianFilter.size+j].x = i-LaplacianFilter.size/2;
            LaplacianFilter.pos[i*LaplacianFilter.size+j].y = j-LaplacianFilter.size/2;
        }
    if(LaplacianFilter.filter_num==0||LaplacianFilter.filter_num==2)    c=-1;
    else    c=1;

    for(int i=0;i<output->HeightBMP;i++){
        for(int j=0;j<output->WidthBMP;j++){
            int ori_pixel, tempx, tempy;
            int B=0, G=0, R=0, Y=0;

            for(int k=0;k<LaplacianFilter.size*LaplacianFilter.size;k++){
                tempx=i+LaplacianFilter.pos[k].x;
                tempy=j+LaplacianFilter.pos[k].y;
                if(tempx<0||tempy<0||tempx>=output->HeightBMP||tempy>=output->WidthBMP) continue;
                if(input->bmih.biBitCount==8)
                    Y+=input->data[tempx*output->LineBytes+tempy]*LaplacianFilter.coef[LaplacianFilter.filter_num][k];
                else{
					//cout << LaplacianFilter.coef[LaplacianFilter.filter_num][k] << endl;
                    B+=input->data[tempx*output->LineBytes+tempy*3+0]*LaplacianFilter.coef[LaplacianFilter.filter_num][k];
                    G+=input->data[tempx*output->LineBytes+tempy*3+1]*LaplacianFilter.coef[LaplacianFilter.filter_num][k];
                    R+=input->data[tempx*output->LineBytes+tempy*3+2]*LaplacianFilter.coef[LaplacianFilter.filter_num][k];
                }
            }
			
            if(input->bmih.biBitCount==8)
                output->data[i*input->LineBytes+j]=Y;
            else{
                output->data[i*input->LineBytes+j*3+0]=B;
                output->data[i*input->LineBytes+j*3+1]=G;
                output->data[i*input->LineBytes+j*3+2]=R;
            }
            
            Y+=c*input->data[i*input->LineBytes+j];
            B+=c*input->data[i*input->LineBytes+j*3+0];
            G+=c*input->data[i*input->LineBytes+j*3+1];
            R+=c*input->data[i*input->LineBytes+j*3+2];
            
			//if(Y<0)	Y*=-1;	if(B<0)	B*=-1;	if(G<0)	G*=-1;	if(R<0)	R*=-1;
            if(Y<0)	Y=0;	if(B<0)	B=0;	if(G<0)	G=0;	if(R<0)	R=0;
			if(Y>255) Y=255;	if(B>255) B=255;	if(G>255) G=255;	if(R>255) R=255;


            if(input->bmih.biBitCount==8)
                output->data[i*input->LineBytes+j]=Y;
            else{
                output->data[i*input->LineBytes+j*3+0]=B;
                output->data[i*input->LineBytes+j*3+1]=G;
                output->data[i*input->LineBytes+j*3+2]=R;
            }
        }
    }

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


void CopyGray(IMAGE *base, IMAGE *copy){

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

void CopyColor(IMAGE *base, IMAGE *copy){

    memcpy(&(copy->bmfh), &(base->bmfh), sizeof(BMFH));          //copy the bmp file header
    memcpy(&(copy->bmih), &(base->bmih), sizeof(BMIH));          //copy the bmp information header
    copy->bmih.biBitCount=24;
    copy->WidthBMP=base->WidthBMP;
    copy->HeightBMP=base->HeightBMP;
    copy->LineBytes=(copy->WidthBMP*(copy->bmih.biBitCount/8)+3)/4*4;                   //bytes mod 4 = 0. compliment
    //cout << "wrong in linebytes" << copy->LineBytes <<  " " << base->LineBytes << endl;
	copy->bmih.biSizeImage=copy->LineBytes*copy->HeightBMP;     //calculate the size of the image data part
    copy->SizeImageBMP=copy->bmih.biSizeImage;
    copy->bmfh.bfSize=copy->bmfh.bfOffBits+copy->bmih.biSizeImage;//calculate the size of the whole bmp file
    copy->data=new BYTE[copy->bmih.biSizeImage];
	memset(copy->data, 0, sizeof(BYTE)*copy->SizeImageBMP);
	for(int i=0;i<copy->HeightBMP;i++){
		for(int j=0;j<copy->WidthBMP;j++){
			copy->data[copy->LineBytes*i+j*3]=base->data[base->LineBytes*i+j*3];
            copy->data[copy->LineBytes*i+j*3+1]=base->data[base->LineBytes*i+j*3+1];
            copy->data[copy->LineBytes*i+j*3+2]=base->data[base->LineBytes*i+j*3+2];
		}
	}
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

void WriteBMP(FILE *fp, IMAGE *output){

    fwrite(&(output->bmfh), sizeof(BMFH), 1, fp);
    fwrite(&(output->bmih), sizeof(BMIH), 1, fp);
    if(output->bmih.biBitCount==8)                              //only write the rgbquad when biBitCount=1/2/4/8
        fwrite(output->rgbquad, sizeof(RGBQUAD), 256, fp);

    fwrite(output->data, sizeof(BYTE), output->SizeImageBMP, fp);

    return;
}



