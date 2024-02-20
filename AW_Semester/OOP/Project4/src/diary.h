#ifndef __DIARY_H__
#define __DIARY_H__
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class C_Diary{

public:
    friend class C_Folder;
    C_Diary();
    C_Diary(std::string temp_date, std::string temp_content);
    ~C_Diary();
    void read_diary(ifstream &fin);     //only this is useful.
    void write_diary();
    int  remove_diary();
    //string return_date();

    inline void print_line(){
        std::cout << "- - - - - - - - - - - - - - - - -" << std::endl;
    }

private:
    
    std::string date;
    std::string content;

};





#endif