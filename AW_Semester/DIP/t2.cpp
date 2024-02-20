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

Coord struct_element_square[10]={{9,9}, {-1,-1},{0,-1},{1,-1},{-1,0},{0,0},{1,0},{-1,1},{0,1},{1,1}};
Coord struct_element_cross[6]={{5,5}, {0,-1},{-1,0},{0,0},{1,0},{0,1}};

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

IMAGE input, gray, binary, erosion, dilation, opening, closing;

int ReadBMP(FILE *fp, IMAGE *input);
void copyBMP(IMAGE *base, IMAGE *copy);
void WriteBMP(FILE *fp, IMAGE *input);
void color_to_gray(IMAGE *input, IMAGE *gray);
void gray_to_binary_ostu(IMAGE *gray, IMAGE *binary);
void gray_to_binary_sliding(IMAGE *gray, IMAGE *binary);
void do_dilation(IMAGE *input, IMAGE *output);
void do_erosion(IMAGE *input, IMAGE *output);
void do_opening(IMAGE *input, IMAGE *output);
void do_closing(IMAGE *input, IMAGE *output);

int main(){

    //read in the bmp
    FILE *fp;
    fp=fopen("./pic/flower.bmp", "rb");
    if(fp==NULL){
        printf("failed to open the bmp\n");
        return 0;
    }
    if(ReadBMP(fp, &input)==1){
        printf("the file is not a BMP\n");
        return 0;
    }

    // //write the bmp to confirm that bmp has been correctly read in
    // FILE *fp_test;
    // fp_test=fopen("flower_print.bmp", "wb");
    // if(fp_test==NULL){
    // 	printf("failed to open the output bmp");
	// 	return 0;  	
	// }
    // WriteBMP(fp_test, &input);
    // fclose(fp_test);

    //turn rgb to grayscale
    color_to_gray(&input, &gray);
    //write grayscale
    FILE *fp_gray;
    fp_gray=fopen("./pic/flower_gray.bmp", "wb");
    if(fp_gray==NULL){
    	printf("failed to open the output bmp");
		return 0;  	
	}
    WriteBMP(fp_gray, &gray);
    fclose(fp_gray); 
    
    //turn grayscale to binary
    gray_to_binary_ostu(&gray, &binary);
    //write binary
    FILE *fp_binary;
    fp_binary=fopen("./pic/flower_binary_ostu.bmp", "wb");
    if(fp_gray==NULL){
    	printf("failed to open the output bmp");
		return 0;  	
	}
    WriteBMP(fp_binary, &binary);
    fclose(fp_binary); 

    //do the dilation
    do_dilation(&binary, &dilation);
    //write grayscale
    FILE *fp_dilation;
    fp_dilation=fopen("./pic/flower_dilation.bmp", "wb");
    if(fp_dilation==NULL){
    	printf("failed to open the output bmp");
		return 0;  	
	}
    WriteBMP(fp_dilation, &dilation);
    fclose(fp_dilation);

    //do the erosion
    do_erosion(&binary, &erosion);
    //write erosion
    FILE *fp_erosion;
    fp_erosion=fopen("./pic/flower_erosion.bmp", "wb");
    if(fp_erosion==NULL){
    	printf("failed to open the output bmp");
		return 0;  	
	}
    WriteBMP(fp_erosion, &erosion);
    fclose(fp_erosion); 
    
    //do the opening
    do_erosion(&binary, &opening);
    //write opening
    FILE *fp_opening;
    fp_opening=fopen("./pic/flower_opening.bmp", "wb");
    if(fp_opening==NULL){
    	printf("failed to open the output bmp");
		return 0;  	
	}
    WriteBMP(fp_opening, &opening);
    fclose(fp_opening);

    //do the closing
    do_erosion(&binary, &closing);
    //write closing
    FILE *fp_closing;
    fp_closing=fopen("./pic/flower_closing.bmp", "wb");
    if(fp_closing==NULL){
    	printf("failed to open the output bmp");
		return 0;  	
	}
    WriteBMP(fp_closing, &closing);
    fclose(fp_closing);

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

void gray_to_binary_ostu(IMAGE *gray, IMAGE *binary){

    copyBMP(gray, binary);

    float prob[255]={}, sum_prob[255]={}, sum_i_prob[255]={}, variance[255]={};
    int PixelNum=gray->HeightBMP*gray->WidthBMP;
    double mean_front, mean_back, variance_max, threshold;

    for(int i=0;i<gray->HeightBMP;i++){
        for(int j=0;j<gray->WidthBMP;j++){
            int graynum=gray->data[gray->LineBytes*i+j];
            if(graynum>255)graynum=255;
            if(graynum<0)graynum=0;
            prob[graynum]++;
        }
    }
    for(int i=0;i<=255;i++)
        prob[i]=prob[i]/PixelNum;
    
    for(int i=0;i<=255;i++){
        if(i==0){
            sum_prob[i]=prob[i];
            sum_i_prob[i]=prob[i]*i;
        }else{
            sum_prob[i]=sum_prob[i-1]+prob[i];
            sum_i_prob[i]=sum_i_prob[i-1]+prob[i]*i;
        }
    }


    for(int i=0;i<=255;i++){
        if(sum_prob[i]==0||sum_prob[i]==1)
            continue;
        mean_front=(1.0)/sum_prob[i]*sum_i_prob[i];
        mean_back=(1.0)/(1-sum_prob[i])*(sum_i_prob[255]-sum_i_prob[i]);
        variance[i]=sum_prob[i]*(1-sum_prob[i])*pow((mean_front-mean_back), 2);
        if(variance[i]>=variance_max){
            variance_max=variance[i];
            threshold=i;
        }
    }
    cout << threshold << endl;

    for(int i=0;i<binary->HeightBMP;i++){                         //go through each pixel
		for(int j=0;j<binary->WidthBMP;j++){                      //grayscale only needs to calculate Y
            double Y=gray->data[gray->LineBytes*i+j];
			if(Y>=threshold) Y=255;
            else if(Y<threshold) Y=0;
			binary->data[binary->LineBytes*i+j]=Y;                  //double -> int to improve precision
		}
	}

}

void gray_to_binary_sliding(IMAGE *gray, IMAGE *binary){

    copyBMP(gray, binary);

    int window_size=100, stride=50, slide_height, slide_width;
    float prob[255]={}, sum_prob[255]={}, sum_i_prob[255]={};
    int PixelNum=gray->HeightBMP*gray->WidthBMP;
    double mean_front, mean_back, variance_max, threshold, variance;
    WORD *threshold_sum=new WORD[binary->HeightBMP*binary->WidthBMP];
    WORD *threshold_num=new WORD[binary->HeightBMP*binary->WidthBMP];
	for(int i=0;i<binary->HeightBMP*binary->WidthBMP;i++)
		threshold_sum[i]=threshold_num[i]=0;

    for(int i=0;i<binary->HeightBMP;i+=stride){

        if(binary->HeightBMP<i+window_size) slide_height=binary->HeightBMP-i;
        else slide_height=window_size;

        for(int j=0;j<binary->WidthBMP-stride;j+=stride){
            if(binary->WidthBMP<j+window_size) slide_width=binary->WidthBMP-j;
            else slide_width=window_size;

            memset(prob, 0, sizeof(prob));
            memset(sum_prob, 0, sizeof(sum_prob));
            memset(sum_i_prob, 0, sizeof(sum_i_prob));
            PixelNum=slide_height*slide_width;
            variance=variance_max=0;


            for(int ii=i;ii<i+slide_height;ii++){
                for(int jj=j;jj<j+slide_width;jj++){
                    int graynum=gray->data[gray->LineBytes*ii+jj];
                    if(graynum>255)graynum=255;
                    if(graynum<0)graynum=0;
                    prob[graynum]++;
                }
            }
            for(int k=0;k<=255;k++)
                prob[k]=prob[k]/PixelNum;
    
            for(int k=0;k<=255;k++){
                if(k==0){
                    sum_prob[k]=prob[k];
                    sum_i_prob[k]=prob[k]*k;
                }else{
                    sum_prob[k]=sum_prob[k-1]+prob[k];
                    sum_i_prob[k]=sum_i_prob[k-1]+prob[k]*k;
                }
            }

            for(int k=0;k<=255;k++){
                if(sum_prob[k]==0||sum_prob[k]==1)
                    continue;
                mean_front=(1.0)/sum_prob[k]*sum_i_prob[k];
                mean_back=(1.0)/(1-sum_prob[k])*(sum_i_prob[255]-sum_i_prob[k]);
                variance=sum_prob[k]*(1-sum_prob[k])*pow((mean_front-mean_back), 2);
                if(variance>=variance_max){
                    variance_max=variance;
                    threshold=k;
                }
            }

            // for(int ii=i;ii<i+slide_height;ii++){
            //     for(int jj=j;jj<j+slide_width;jj++){
            //         double Y=gray->data[gray->LineBytes*ii+jj];
			//         if(Y>=threshold) Y=255;
            //         else if(Y<threshold) Y=0;
			//         binary->data[binary->LineBytes*ii+jj]=Y;   
            //     }
            // }
            for(int ii=i;ii<i+slide_height;ii++){
                for(int jj=j;jj<j+slide_width;jj++){
                    threshold_sum[binary->WidthBMP*ii+jj]+=threshold;
                    threshold_num[binary->WidthBMP*ii+jj]+=1;
                    
                }
            }
            
        }
    }

    cout << "before print" << endl;

    for(int i=0;i<binary->HeightBMP;i++){                         //go through each pixel
		for(int j=0;j<binary->WidthBMP;j++){                      //grayscale only needs to calculate Y
            double Y=gray->data[gray->LineBytes*i+j];
            if(threshold_num[binary->WidthBMP*i+j]==0)
            	threshold_num[binary->WidthBMP*i+j]=1;
            double Z=threshold_sum[binary->WidthBMP*i+j]/threshold_num[binary->WidthBMP*i+j];
			if(Y>=Z) Y=255;
            else Y=0;
			binary->data[binary->LineBytes*i+j]=Y;                  //double -> int to improve precision
		}
	}
}

void do_dilation(IMAGE *input, IMAGE *output){

    copyBMP(input, output);

    for(int i=0;i<output->HeightBMP;i++){
        for(int j=0;j<output->WidthBMP;j++){
            int windowX, windowY;
            output->data[i*output->LineBytes+j]=0;
            for(int k=1;k<=struct_element_square[0].x;k++){
                windowX=i+struct_element_square[k].x;
                windowY=j+struct_element_square[k].y;
                if(windowX<0||windowY<0||windowX>=output->HeightBMP||windowY>=output->WidthBMP)
                    continue;
                if(input->data[windowX*input->LineBytes+windowY]==255){
                    output->data[i*output->LineBytes+j]=255;
                    break;
                }
            }
        }
    }
       
}

void do_erosion(IMAGE *input, IMAGE *output){

    copyBMP(input, output);
    int all=0, count0=0, count1=0;
    for(int i=0;i<output->HeightBMP;i++){
        for(int j=0;j<output->WidthBMP;j++){
            int windowX, windowY;
            output->data[i*output->LineBytes+j]=255;
            for(int k=1;k<=struct_element_square[0].x;k++){
                windowX=i+struct_element_square[k].x;
                windowY=j+struct_element_square[k].y;
                if(windowX<0||windowY<0||windowX>=output->HeightBMP||windowY>=output->WidthBMP){
                    // output->data[i*output->LineBytes+j]=0;
                    // break;
                    continue;
                }
                if(input->data[windowX*input->LineBytes+windowY]==0){
                    output->data[i*output->LineBytes+j]=0;
                    break;
                }
            }
        }
    }
}

void do_opening(IMAGE *input, IMAGE *output){

    do_erosion(input, output);
    do_dilation(output, output);

}

void do_closing(IMAGE *input, IMAGE *output){

    do_dilation(input, output);
    do_erosion(output, output);

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