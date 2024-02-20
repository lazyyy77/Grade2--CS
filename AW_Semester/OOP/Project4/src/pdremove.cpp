#include <iostream>
#include <fstream>
#include "diary.h"
#include "folder.h"

int main(){

    C_Folder folder;
    folder.sort_folder();
    string remove_date;
    cout << "<Please input the date of the diary you want to remove.>\n";
    cout << "<the input form shold be [yyyy-mm-dd], e.g. 2023-11-18 >\n";
    cin >> remove_date;
    
    folder.update_folder(remove_date);

    // fin.close();

    return 0;
}

