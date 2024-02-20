#include <iostream>
#include "diary.h"

C_Diary::C_Diary(){
    return;
}

C_Diary::~C_Diary(){
    return;
}

C_Diary::C_Diary(std::string temp_date, std::string temp_content){
    date=temp_date;
    content=temp_content;
}

void C_Diary::read_diary(ifstream &fin){

    getline(fin, date);
    string newline;
    while(getline(fin, newline)){
        if(!newline.compare("*End_Diary*"))
            break;
        content+=newline;
        content+="\n";
    }

}

void C_Diary::write_diary(){

    C_Diary::print_line();
    std::cout << "*DATE: " << date << std::endl;
    std::cout << "*CONTENT: " << std::endl;
    std::cout << content << std::endl;
    C_Diary::print_line();

}

int C_Diary::remove_diary(){

    string Date, FileName, line;
    cin >> Date;
    FileName = Date +".txt";
    return remove(FileName.c_str());

}

// string C_Diary::return_date(){
//     return date;
// }

// void C_Diary::change_date(string new_date){
//     date=new_date;
// }
