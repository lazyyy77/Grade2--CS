#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main(){

    
    int data[10][3], max_s[3]={1,1,1}, min_s[3]={5,5,5};    //data save the socres1, scores2, scores3
                                                            //max_s save the maximum num of the scores above
                                                            //min_s save the minimum num of the scores above
    float average_p[10], average_s[3];                      //average_p and average_s calculate the average num of each person and each scores
    string no[13], name[13];                                //no help to print the no. while name help to save and print the name

    for(int i=0;i<10;i++){                                  //there's 10 groups of data
        cin >> name[i] >> data[i][0] >> data[i][1] >> data[i][2];   //cin the name and the data of the scores
        average_p[i]=(data[i][0]+data[i][1]+data[i][2])/3.0;        //calculate the average num of the number i student
        average_s[0]+=data[i][0];
        average_s[1]+=data[i][1];
        average_s[2]+=data[i][2];                           //accumulate the sum of the score1/2/3 
        if(data[i][0]>max_s[0])
            max_s[0]=data[i][0];
        if(data[i][1]>max_s[1])
            max_s[1]=data[i][1];
        if(data[i][2]>max_s[2])
            max_s[2]=data[i][2];
        if(data[i][0]<min_s[0])
            min_s[0]=data[i][0];
        if(data[i][1]<min_s[1])
            min_s[1]=data[i][1];
        if(data[i][2]<min_s[2])
            min_s[2]=data[i][2];                            //update the max/min num of each score
    }

    for(int i=0;i<10;i++)
        no[i]= to_string(i+1);
    name[10]="average";
    name[11]="min";
    name[12]="max";

    cout << left << setw(8) << "no" << left << setw(8) << "name" << left << setw(8) << "score1" << left << setw(8) << "score2" << left << setw(8) << "score3" << left << setw(8) << "average" << endl;
    //use left and setw(8) to make sure that each output is print from the left and use blank to fill in the 8 space
    //the line above print the title

    for(int i=0;i<10;i++)
        cout << left << setw(8) << no[i] << left << setw(8) << name[i] << left << setw(8) << data[i][0] << left << setw(8) << data[i][1] << left << setw(8) << data[i][2] << left << setw(8) << average_p[i] << endl;
        //each for loop print the data of student number i.

    cout << left << setw(8) << no[10] << left << setw(8) << name[10] << left << setw(8) << average_s[0]/10.0 << left << setw(8) << average_s[1]/10.0 << left << setw(8) << average_s[2]/10.0 << endl;
    cout << left << setw(8) << no[11] << left << setw(8) << name[11] << left << setw(8) << min_s[0] << left << setw(8) << min_s[1] << left << setw(8) << min_s[2] << endl;
    cout << left << setw(8) << no[12] << left << setw(8) << name[12] << left << setw(8) << max_s[0] << left << setw(8) << max_s[1] << left << setw(8) << max_s[2] << endl;
    //the line above print the average num of each score and the min and max num of each score.

    return 0;
}