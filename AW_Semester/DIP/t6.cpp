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



typedef struct{
    int size=3;
    double sigma=0.5;
    double* coef;
    Coord*  pos;
}Filter_Gaussian;

typedef struct{
    int size = 3;
    double sigma_s, sigma_r;
    Filter_Gaussian F_Gaussian;
}Filter_Bilateral;

IMAGE input, gray, gaussian_filtering, bilateral_filtering;

int ReadBMP(FILE *fp, IMAGE *input);
void WriteBMP(FILE *fp, IMAGE *input);
void CopyGray(IMAGE *base, IMAGE *copy);
void CopyColor(IMAGE *base, IMAGE *copy);
void color_to_gray(IMAGE *input, IMAGE *gray);
double calc_exp(double Ip, double Iq, double sigma_r);
void Do_bilateral_filtering(IMAGE *input, IMAGE *bilateral_filtering);

int main(){

    //read in the bmp
    FILE *fp;
    fp=fopen("./pic/wall.bmp", "rb");
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

    Do_bilateral_filtering(&input, &bilateral_filtering);
    //write bilateral_filteringscale
    FILE *fp_bilateral_filtering;
    fp_bilateral_filtering=fopen("./pic/bilateral_filtering.bmp", "wb");
    if(fp_bilateral_filtering==NULL){
    	printf("failed to open the output bmp");
		return 0;  	
	}
    WriteBMP(fp_bilateral_filtering, &bilateral_filtering);
    fclose(fp_bilateral_filtering);

    

    cout << "success!" << endl;

}

double calc_exp(double Ip, double Iq, double sigma){
    double expo=(Ip-Iq)*(Ip-Iq);
    return exp(-expo / (2*sigma*sigma));
}

void Do_bilateral_filtering(IMAGE *input, IMAGE *output){

    if(input->bmih.biBitCount!=8)   CopyColor(input, output);
    else    CopyGray(input, output);
    
    Filter_Bilateral BilateralFilter;
    BilateralFilter.size=15;
    BilateralFilter.sigma_s=0.02*sqrt(input->HeightBMP*input->HeightBMP+input->WidthBMP*input->WidthBMP);
    cout << BilateralFilter.sigma_s << endl;
    BilateralFilter.sigma_r=20;
    BilateralFilter.F_Gaussian.coef = new double[BilateralFilter.size*BilateralFilter.size];
    BilateralFilter.F_Gaussian.pos  = new Coord[BilateralFilter.size*BilateralFilter.size];
    int midx, midy;
    midx = midy = BilateralFilter.size/2;
    for(int i=0;i<BilateralFilter.size;i++)
        for(int j=0;j<BilateralFilter.size;j++){
            double expo=((i-midx)*(i-midx)+(j-midy)*(j-midy));
            expo=expo*(-1)/2/BilateralFilter.sigma_s/BilateralFilter.sigma_s;
            BilateralFilter.F_Gaussian.coef[i*BilateralFilter.size+j]=exp(expo);
            // different from the simple gaussian filtering by
            // ignoring the coef :/2.0/M_PI/BilateralFilter.sigma_s/BilateralFilter.sigma_s;
        }
    for(int i=0;i<BilateralFilter.size;i++)
        for(int j=0;j<BilateralFilter.size;j++){
            BilateralFilter.F_Gaussian.pos[i*BilateralFilter.size+j].x = i-BilateralFilter.size/2;
            BilateralFilter.F_Gaussian.pos[i*BilateralFilter.size+j].y = j-BilateralFilter.size/2;
        }

    //  for(int i=0;i<BilateralFilter.size;i++){
    //      for(int j=0;j<BilateralFilter.size;j++){
    //          cout << BilateralFilter.F_Gaussian.coef[i*BilateralFilter.size+j] << " ";
    //      }
    //      cout << endl;
    //  }
    //  for(int i=0;i<BilateralFilter.size;i++){
    //      for(int j=0;j<BilateralFilter.size;j++){
    //          cout << BilateralFilter.F_Gaussian.pos[i*BilateralFilter.size+j].x << " ";
    //          cout << BilateralFilter.F_Gaussian.pos[i*BilateralFilter.size+j].y << " ";
    //      }
    //      cout << endl;
    //  }

    for(int i=0;i<output->HeightBMP;i++){
        for(int j=0;j<output->WidthBMP;j++){
            int tempx, tempy;
            double ori_B, ori_G, ori_R, ori_Y;
            if(input->bmih.biBitCount==8){
                ori_Y=input->data[i*output->LineBytes+j];
            }else{
                ori_B=input->data[i*output->LineBytes+j*3+0];
                ori_G=input->data[i*output->LineBytes+j*3+1];
                ori_R=input->data[i*output->LineBytes+j*3+2];
            }

            double nB=0, nG=0, nR=0, nY=0;
            double gB=0, gG=0, gR=0, gY=0;
            double IB=0, IG=0, IR=0, IY=0;
            double WB=0, WG=0, WR=0, WY=0;

            for(int k=0;k<BilateralFilter.size*BilateralFilter.size;k++){
                tempx=i+BilateralFilter.F_Gaussian.pos[k].x;
                tempy=j+BilateralFilter.F_Gaussian.pos[k].y;
                if(tempx<0||tempy<0||tempx>=output->HeightBMP||tempy>=output->WidthBMP) continue;
                if(input->bmih.biBitCount==8){
                    IY=input->data[tempx*output->LineBytes+tempy];
                    gY=calc_exp(IY, ori_Y, BilateralFilter.sigma_r);
                    WY+=gY*BilateralFilter.F_Gaussian.coef[k];
                    nY+=gY*BilateralFilter.F_Gaussian.coef[k]*IY;
                }else{
					//cout << GaussianFilter.coef[GaussianFilter.filter_num][k] << endl;
                    IB=input->data[tempx*output->LineBytes+tempy*3+0];
                    gB=calc_exp(IB, ori_B, BilateralFilter.sigma_r);
                    WB+=gB*BilateralFilter.F_Gaussian.coef[k];
                    nB+=gB*BilateralFilter.F_Gaussian.coef[k]*IB;

                    IG=input->data[tempx*output->LineBytes+tempy*3+1];
                    gG=calc_exp(IG, ori_G, BilateralFilter.sigma_r);
                    WG+=gG*BilateralFilter.F_Gaussian.coef[k];
                    nG+=gG*BilateralFilter.F_Gaussian.coef[k]*IG;

                    IR=input->data[tempx*output->LineBytes+tempy*3+2];
                    gR=calc_exp(IR, ori_R, BilateralFilter.sigma_r);
                    WR+=gR*BilateralFilter.F_Gaussian.coef[k];
                    nR+=gR*BilateralFilter.F_Gaussian.coef[k]*IR;
                }
            }
			
            if(input->bmih.biBitCount==8)
                nY=nY/WY;
            else{
                nB=nB/WB;
                nG=nG/WG;
                nR=nR/WR;
            }
            
			//if(Y<0)	Y*=-1;	if(B<0)	B*=-1;	if(G<0)	G*=-1;	if(R<0)	R*=-1;
            if(nY<0)	nY=0;	if(nB<0)	nB=0;	if(nG<0)	nG=0;	if(nR<0)	nR=0;
			if(nY>255) nY=255;	if(nB>255) nB=255;	if(nG>255) nG=255;	if(nR>255) nR=255;

            if(input->bmih.biBitCount==8)
                output->data[i*input->LineBytes+j]=nY;
            else{
                output->data[i*input->LineBytes+j*3+0]=nB;
                output->data[i*input->LineBytes+j*3+1]=nG;
                output->data[i*input->LineBytes+j*3+2]=nR;
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



