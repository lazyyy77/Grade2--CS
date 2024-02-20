#include <iostream>
#include <fstream>
#include "diary.h"
#include "folder.h"

int main(){

    C_Folder folder;
    folder.sort_folder();
    string add_date;
    cout << "<Please input the date of the diary you want to add.>\n";
    cout << "<the input form shold be [yyyy-mm-dd], e.g. 2023-11-18 >\n";
    cin >> add_date;
    
    folder.add_to_folder(add_date);

    // fin.close();


    return 0;
}