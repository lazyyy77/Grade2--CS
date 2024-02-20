#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;

/*Course_Score is a struct that contain students' score of a specific course.
this struct is contained in struct Course.
*/
struct Course_Score{
    int score, number;
    Course_Score *next;
};

/*Student is a struct that contain each students' name,
the num of the courses they took,
and the sum of the score.
*/
struct Student{
    int number, total, num;
    string name, data;
    Student *next;
    
};

/*Course is a struct that contain each courses' name,
the num of the students that chose this course,
the mininum and the maxinum score,
and the sum of the score.
plus, it contains a Course_Score struct pointer,
which help to remind the information of the relation of
the student and their score in this specific course. 
*/
struct Course{
    string cname;
    int total, num, min, max;
    Course *next;
    Course_Score *cscore;    
};

int main(int argc, char *argv[]){

	if(argc!=2)
		cout << "invalid input\n";
	int num=0;                                          //the number of the student(no.)
    string line;                                        //it save a line's information
    Student *stu=NULL;                                  //the pointer of struct Student
    Student *head=stu;
    Course *course=NULL;                                //the pointer of struct Course
    Course *chead=course;
    ifstream fin(argv[1]);

    while(getline(fin, line)){                          //read in a line
        num++;                                          
        istringstream nowline(line);                    //save the information in a stream buffer
        
        Student *nowstu=new Student;
        nowstu->next=NULL;
        nowstu->number=num;
        nowstu->num=nowstu->total=0;
        std::getline(nowline, nowstu->name, ' ');
        if(head==NULL){
            stu=nowstu;
            head=nowstu;
        }else{
            head->next=nowstu;
            head=head->next;
        }
        string coursename, score;
        int coursenum=0;

        /*this part save the score of each course in this course's
        Course_Score pointer. plus, this part accumulate the information
        of student.total and student.num
        */
        while(std::getline(nowline, coursename, ' ')){          //read course name
            chead=course;
            int flag=0;
            while(chead!=NULL){                                 //find the course in course list
                if(chead->cname==coursename){
                    flag=1;
                    break;
                }
                chead=chead->next;
            }
            /*this part deal with the situation that,
            if this course is a new one,
            then create the course, fill in the information,
            and then add it into the course list.
            */
            if(flag==0){
                Course *newcourse=new Course;
                newcourse->cname.assign(coursename);
                newcourse->total=newcourse->num=newcourse->max=0;
                newcourse->min=5;
                newcourse->next=NULL;
                newcourse->cscore=NULL;                             //initialize information
                if(course==NULL){
                    chead=newcourse;
                    course=newcourse;
                }else{
                    chead=course;
                    while(chead->next!=NULL)
                        chead=chead->next;
                    chead->next=newcourse;
                    chead=chead->next;
                }                                                   //add it to the course list
            }
            /*the part below deal with the score of the read-in course.
            includes: update min, max.
                    accumulate num, sum(total).
                    update the information in Course_Score.
            */              
			std::getline(nowline, score, ' ');
            head->num++;
            head->total+=score[0]-'0';
            chead->total+=score[0]-'0';
            chead->num++;            
            if(chead->max<score[0]-'0')
                chead->max=score[0]-'0';
            if(chead->min>score[0]-'0')
                chead->min=score[0]-'0';                //update min, max, num, total
            
            Course_Score *newscore=new Course_Score;
            newscore->number=num;
            newscore->score=score[0]-'0';
            newscore->next=NULL;
            if(chead->cscore==NULL){
                chead->cscore=newscore;
            }else{
                Course_Score *shead=chead->cscore;
                while(shead->next!=NULL)
                    shead=shead->next;
                shead->next=newscore;
            }                                           //create a new struct Student_Course
        }                                               //fill in the information and add it to the list
        cout << nowstu->data << endl;
    }

    //first print the course list
    chead=course;
    cout << left << setw(8) << "no" << left << setw(8) << "name";
    while(chead!=NULL){
        cout << left << setw(8) << chead->cname;
        chead=chead->next;
    }
    cout << left << setw(8) << "average" << endl;

    //second print the students' score
    head=stu;
    while(head!=NULL){
        cout << left << setw(8) << head->number << left << setw(8)  << head->name;  //print no. and name.
        chead=course;
        while(chead!=NULL){                                                         //read the course's Course_Score
            int flag=0;
            Course_Score *shead=chead->cscore;
            while(shead!=NULL){
                if(shead->number > head->number)
                    break;
                if(shead->number==head->number){                                    //if student indeed took this course
                	flag=1;                                                         //print the score and update flag
                    cout << left << setw(8) << shead->score;
                    break;
                }
                shead=shead->next;
            }
            if(flag==0)                                                             //if student didn't take this course
            	cout << left << setw(8) << "";                                      //print blank to maintain the form
            chead=chead->next;
        }       
        cout << left << setw(8) << ((float)head->total)/head->num << endl;          //print the average
        head=head->next;
    }
    
    //third print the analyzing information
    cout << left << setw(8) << "" << left << setw(8) << "average";
    chead=course;
    while(chead!=NULL){
        cout << left << setw(8) << ((float)chead->total)/chead->num;
        chead=chead->next;
    }
    cout << endl << left << setw(8) << "" << left << setw(8) << "min";
    chead=course;    
    while(chead!=NULL){
        cout << left << setw(8) << chead->min;
        chead=chead->next;
    }
    cout << endl << left << setw(8) << "" << left << setw(8) << "max";
    chead=course;
    while(chead!=NULL){
        cout << left << setw(8) << chead->max;
        chead=chead->next;
    }
    cout << endl;
    
    return 0;
}