#include <iostream>
#include <fstream>
#include "diary.h"
#include "folder.h"

int main(){

    C_Folder folder;
    folder.sort_folder();
    char choice;
    string start_date, end_date;
    cout << "<Do you want to list all the diary?> <y/n>" << endl;
    cin >> choice;
    if(choice=='Y'||choice=='y'){
        start_date.assign("0000-00-00");
        end_date.assign("9999-99-99");
    }else{
        cout << "<Please input the START-DATE of the diary you want to list.>\n";
        cout << "<the input form shold be [yyyy-mm-dd], e.g. 2023-11-18 >\n";
        cin >> start_date;

        cout << "<Please input the END-DATE of the diary you want to list.>\n";
        cout << "<the input form shold be [yyyy-mm-dd], e.g. 2023-11-18 >\n";
        cin >> end_date;
    }
    
    folder.list_folder(start_date, end_date);

    // fin.close();

    return 0;
}
