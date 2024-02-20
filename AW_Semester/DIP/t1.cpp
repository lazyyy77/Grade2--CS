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

IMAGE input, yuv, gray, changeY;

int ReadBMP(FILE *fp, IMAGE *input);
void WriteBMP(FILE *fp, IMAGE *input);
void RGBtoYUV(double R, double G, double B, double *Y, double *U, double *V);
void color_to_gray(IMAGE *input, IMAGE *gray);
void gray_to_color(IMAGE *input, IMAGE *changeY);

int main(){

    //read in the bmp
    FILE *fp;
    fp=fopen("./pic/lucy.bmp", "rb");
    if(fp==NULL){
        printf("failed to open the bmp\n");
        return 0;
    }
    if(ReadBMP(fp, &input)==1){
        printf("the file is not a BMP\n");
        return 0;
    }

    //write the bmp to confirm that bmp has been correctly read in
    FILE *fp_test;
    fp_test=fopen("./pic/output.bmp", "wb");
    if(fp_test==NULL){
    	printf("failed to open the output bmp");
		return 0;  	
	}
    WriteBMP(fp_test, &input);
    fclose(fp_test);

    //turn rgb to grayscale
    color_to_gray(&input, &gray);
    //write grayscale
    FILE *fp_gray;
    fp_gray=fopen("./pic/togray.bmp", "wb");
    if(fp_gray==NULL){
    	printf("failed to open the output bmp");
		return 0;  	
	}
    WriteBMP(fp_gray, &gray);
    fclose(fp_gray); 
    
    //change Y(luminance) and turn back to rgb
    gray_to_color(&input, &changeY);
    //write changeY_rgb
    FILE *fp_changeY;
    fp_changeY=fopen("./pic/changeY.bmp", "wb");
    if(fp_changeY==NULL){
    	printf("failed to open the output bmp");
		return 0;  	
	}
    WriteBMP(fp_changeY, &changeY);
    fclose(fp_changeY); 


    cout << "success!" << endl;

}


void RGBtoYUV(double R, double G, double B, double *Y, double *U, double *V){

    double RGBmatrix[3];
    RGBmatrix[0]=B, RGBmatrix[1]=G, RGBmatrix[2]=R;

    for(int i=0;i<3;i++){
        *Y+=matrix1[0][i]*RGBmatrix[i];
        *U+=matrix1[1][i]*RGBmatrix[i];
        *V+=matrix1[2][i]*RGBmatrix[i];
    }

    return;
}

void color_to_gray(IMAGE *rgb, IMAGE *gray){

    memcpy(&(gray->bmfh), &(rgb->bmfh), sizeof(BMFH));          //copy the bmp file header
    memcpy(&(gray->bmih), &(rgb->bmih), sizeof(BMIH));          //copy the bmp information header
    gray->bmfh.bfOffBits=14+40+256*4;                           //again calculate the offsit, given the rgbquad
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

void gray_to_color(IMAGE *rgb, IMAGE *changeY){

    memcpy(&(changeY->bmfh), &(rgb->bmfh), sizeof(BMFH));
    memcpy(&(changeY->bmih), &(rgb->bmih), sizeof(BMIH));
    changeY->WidthBMP=rgb->WidthBMP;
    changeY->HeightBMP=rgb->HeightBMP;
    changeY->LineBytes=rgb->LineBytes;
    changeY->SizeImageBMP=changeY->bmih.biSizeImage;
    changeY->data=new BYTE[changeY->bmih.biSizeImage];          //same as color_to_gray; copy information

    for(int i=0;i<changeY->HeightBMP;i++){
        for(int j=0;j<changeY->WidthBMP;j++){
            double R, G, B, Y, U, V;
            B=rgb->data[rgb->LineBytes*i+j*3];                  //store in BGR order read B,G,R
            G=rgb->data[rgb->LineBytes*i+j*3+1];
            R=rgb->data[rgb->LineBytes*i+j*3+2];
            Y=0.299*R+0.587*G+0.114*B;                          //calculate Y,U,V
            U=-0.147*R-0.289*G+0.435*B;
            V=0.615*R-0.515*G-0.100*B;
            
            Y=Y*2;                                            //change luminance

            R=Y+1.4075*V;                                       //calculate R,G,B 
            G=Y-0.3455*U-0.7169*V;
            B=Y+1.779*U;
            
            if(R>255)R=255;
            if(R<0)R=0;
            if(G>255)G=255;
            if(G<0)G=0;
            if(B>255)B=255;
            if(B<0)B=0;

            changeY->data[changeY->LineBytes*i+j*3]=B;          //write in data
            changeY->data[changeY->LineBytes*i+j*3+1]=G;
            changeY->data[changeY->LineBytes*i+j*3+2]=R;
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