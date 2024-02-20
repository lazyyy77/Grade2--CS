#include <stdio.h>
#include <string.h>
#include <cmath>
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


IMAGE input, gray, log_gray, log_color, equalize_gray, equalize_color;

int ReadBMP(FILE *fp, IMAGE *input);
void copyBMP(IMAGE *base, IMAGE *copy);
void WriteBMP(FILE *fp, IMAGE *input);
void color_to_gray(IMAGE *input, IMAGE *gray);
void do_log_gray(IMAGE *input, IMAGE *output);
void do_log_color(IMAGE *input, IMAGE *color);
void do_equalize_gray(IMAGE *input, IMAGE *output);
void do_equalize_color(IMAGE *input, IMAGE *output);

int main(){

    //read in the bmp
    FILE *fp;
    fp=fopen("./pic/dark.bmp", "rb");
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
    
    //do the log_gray operation
    int l_max;
    do_log_gray(&gray, &log_gray);
    //write log_gray
    FILE *fp_log_gray;
    fp_log_gray=fopen("./pic/log_gray.bmp", "wb");
    if(fp_log_gray==NULL){
    	printf("failed to open the output bmp");
		return 0;  	
	}
    WriteBMP(fp_log_gray, &log_gray);
    fclose(fp_log_gray); 


    //do the log_color operation
    do_log_color(&input, &log_color);
    //write log_color
    FILE *fp_log_color;
    fp_log_color=fopen("./pic/log_color.bmp", "wb");
    if(fp_log_color==NULL){
    	printf("failed to open the output bmp");
		return 0;  	
	}
    WriteBMP(fp_log_color, &log_color);
    fclose(fp_log_color); 

    //do the equalize_gray operation
    do_equalize_gray(&gray, &equalize_gray);
    //write equalize_gray
    FILE *fp_equalize_gray;
    fp_equalize_gray=fopen("./pic/equalize_gray.bmp", "wb");
    if(fp_equalize_gray==NULL){
    	printf("failed to open the output bmp");
		return 0;  	
	}
    WriteBMP(fp_equalize_gray, &equalize_gray);
    fclose(fp_equalize_gray); 
    
        //do the equalize_gray operation
    do_equalize_color(&input, &equalize_color);
    //write equalize_gray
    FILE *fp_equalize_color;
    fp_equalize_color=fopen("./pic/equalize_color.bmp", "wb");
    if(fp_equalize_color==NULL){
    	printf("failed to open the output bmp");
		return 0;  	
	}
    WriteBMP(fp_equalize_color, &equalize_color);
    fclose(fp_equalize_color); 

    cout << "success!" << endl;

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

void do_log_gray(IMAGE *input, IMAGE *output){

    int l_max=0;

    copyBMP(input, output);

    for(int i=0;i<output->HeightBMP;i++){
        for(int j=0;j<output->WidthBMP;j++){
            if(output->data[output->LineBytes*i+j]>l_max)
                l_max=output->data[output->LineBytes*i+j];
        }
    }
    for(int i=0;i<output->HeightBMP;i++){
        for(int j=0;j<output->WidthBMP;j++){
            double x=log(output->data[output->LineBytes*i+j]+1)/log(l_max+1);
            x*=255;
            if(x>255)   x=255;
            if(x<0)   x=0;
            output->data[output->LineBytes*i+j]=(int)x;
        }
    }

}

void do_log_color(IMAGE *rgb, IMAGE *output){

    memcpy(&(output->bmfh), &(rgb->bmfh), sizeof(BMFH));
    memcpy(&(output->bmih), &(rgb->bmih), sizeof(BMIH));
    output->WidthBMP=rgb->WidthBMP;
    output->HeightBMP=rgb->HeightBMP;
    output->LineBytes=rgb->LineBytes;
    output->SizeImageBMP=output->bmih.biSizeImage;
    output->data=new BYTE[output->bmih.biSizeImage];          //same as color_to_gray; copy information

    double l_max=0;
    for(int i=0;i<output->HeightBMP;i++){
        for(int j=0;j<output->WidthBMP;j++){
            double R, G, B, Y, U, V;
            B=rgb->data[rgb->LineBytes*i+j*3];                  //store in BGR order read B,G,R
            G=rgb->data[rgb->LineBytes*i+j*3+1];
            R=rgb->data[rgb->LineBytes*i+j*3+2];
            Y=0.299*R+0.587*G+0.114*B;                          //calculate Y,U,V
            if(Y>l_max)l_max=Y;
        }
    }

    for(int i=0;i<output->HeightBMP;i++){
        for(int j=0;j<output->WidthBMP;j++){
            double R, G, B, Y, U, V;
            B=rgb->data[rgb->LineBytes*i+j*3];                  //store in BGR order read B,G,R
            G=rgb->data[rgb->LineBytes*i+j*3+1];
            R=rgb->data[rgb->LineBytes*i+j*3+2];
            Y=0.299*R+0.587*G+0.114*B;                          //calculate Y,U,V
            U=-0.147*R-0.289*G+0.435*B;
            V=0.615*R-0.515*G-0.100*B;
            
            Y=(int)(log(Y+1)/log(l_max+1)*255);                                      //change luminance

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

    return;
}

void do_equalize_gray(IMAGE *input, IMAGE *output){

    copyBMP(input, output);

    int degree=256;
    int divide=256/degree;
    double prob[256];
    for(int i=0;i<degree;i++)   prob[i]=0;
    for(int i=0;i<output->HeightBMP;i++)
        for(int j=0;j<output->WidthBMP;j++)
            prob[output->data[output->LineBytes*i+j]/divide]++;
    for(int i=0;i<degree;i++)   prob[i]/=(output->HeightBMP*output->WidthBMP);
    for(int i=1;i<degree;i++)   prob[i]+=prob[i-1];
    for(int i=0;i<output->HeightBMP;i++){
        for(int j=0;j<output->WidthBMP;j++){
            int graynum=prob[output->data[output->LineBytes*i+j]/divide]*256;
            if(graynum>255) graynum=255;
            if(graynum<0)   graynum=0;
            output->data[output->LineBytes*i+j]=graynum;
        }
            
    }
}

void do_equalize_color(IMAGE *input, IMAGE *output){

    memcpy(&(output->bmfh), &(input->bmfh), sizeof(BMFH));
    memcpy(&(output->bmih), &(input->bmih), sizeof(BMIH));
    output->WidthBMP=input->WidthBMP;
    output->HeightBMP=input->HeightBMP;
    output->LineBytes=input->LineBytes;
    output->SizeImageBMP=output->bmih.biSizeImage;
    output->data=new BYTE[output->bmih.biSizeImage];          //same as color_to_gray; copy information

    int degree[3];                                            //in the order of B G R
    degree[0]=256;
    degree[1]=256;
    degree[2]=256;
    int divide[3];
    divide[0]=256/degree[0], divide[1]=256/degree[1], divide[2]=256/degree[2];
    double prob[3][256];
    for(int i=0;i<3;i++)
        for(int j=0;j<degree[i];j++)
            prob[i][j]=0;
    for(int i=0;i<input->HeightBMP;i++)
        for(int j=0;j<input->WidthBMP;j++)
            prob[0][input->data[input->LineBytes*i+j*3]/divide[0]]++,
            prob[1][input->data[input->LineBytes*i+j*3+1]/divide[1]]++,
            prob[2][input->data[input->LineBytes*i+j*3+2]/divide[2]]++;
    for(int i=0;i<3;i++)
        for(int j=0;j<degree[i];j++)
            prob[i][j]/=(output->HeightBMP*output->WidthBMP);
    for(int i=0;i<3;i++)
        for(int j=1;j<degree[i];j++)
            prob[i][j]+=prob[i][j-1];
    for(int i=0;i<output->HeightBMP;i++){
        for(int j=0;j<output->WidthBMP;j++){
            int B, G, R;
            B=prob[0][input->data[output->LineBytes*i+j*3]/divide[0]]*256;
            G=prob[1][input->data[output->LineBytes*i+j*3+1]/divide[1]]*256;
            R=prob[2][input->data[output->LineBytes*i+j*3+2]/divide[2]]*256;
            if(B>255)   B=255;  if(B<0) B=0;
            if(G>255)   G=255;  if(G<0) G=0;
            if(R>255)   R=255;  if(R<0) R=0;
            output->data[output->LineBytes*i+j*3]=B,
            output->data[output->LineBytes*i+j*3+1]=G,
            output->data[output->LineBytes*i+j*3+2]=R;
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