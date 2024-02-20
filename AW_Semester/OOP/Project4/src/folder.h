#ifndef __FOLDER_H__
#define __FOLDER_H__
#include <iostream>
#include <vector>
#include "diary.h"
using namespace std;

class C_Folder{

public:             //see the detail and the comments of the function in the .cpp
    C_Folder();
    ~C_Folder();
    void sort_folder();                     //sort diary
    void add_to_folder(string add_date);    //add new diary
    void search_folder(string show_date);   //search and print a specific diary
    void update_folder(string remove_date); //remove diary
    void list_folder(string start_date, string end_date);   //search and print the diary between the list range
 
    C_Diary* return_diary(int i);

private:
    const string memory="./txt/memory.txt";             //path to memory
    const string memory_copy="./txt/memory_copy.txt";   //path to memory_copy
    vector<C_Diary*> DiaryFolder;                       //store the diary

};

#endif