#include "folder.h"


/*this function do the initialize the diarylist when open any pd program.
it will read the diary store in the memory.
*/
C_Folder::C_Folder(){

    ifstream fin(memory);   
    if(!fin.is_open()){
        cout << "failed to open the memory.\n";
        return;
    }
    string newline;
    while(getline(fin, newline)){
        if(!newline.compare("*New_Diary*")){
            C_Diary* new_diary;
            new_diary = new C_Diary;
            new_diary->read_diary(fin);
            DiaryFolder.push_back(new_diary);
        }
    }
    fin.close();
}

C_Folder::~C_Folder(){
    return;
}

/*this function sort the diary by date
*/
void C_Folder::sort_folder(){
    int n=DiaryFolder.size();
    for(int i=n;i>0;i--){
        for(int j=1;j<i;j++){
            if(DiaryFolder[j]->date < DiaryFolder[j-1]->date){
                C_Diary* temp_diary=DiaryFolder[j];
                DiaryFolder[j]=DiaryFolder[j-1];
                DiaryFolder[j-1]=temp_diary;
            }
        }
    }
    // for(int i=0;i<n;i++){
    //     cout << DiaryFolder[i]->date << endl;
    // }
}

/*this function is only a tool to verify the correctness in the developing process.
ignore it.
*/
C_Diary* C_Folder::return_diary(int i){
    return DiaryFolder[i];
}

/* this function remove the diary of a specific date
by copy the other diarys to memory_copy and then copy them back to memory.
*/
void C_Folder::update_folder(string remove_date){
    
    int find_date=0;
    int n=DiaryFolder.size();
    
    for(int i=0;i<n;i++){
        if(DiaryFolder[i]->date==remove_date){
            find_date=1;
            DiaryFolder.erase(DiaryFolder.begin()+i);
            break;
        }
    }
    if(find_date==0){
        cout << "<The date " << remove_date << " doesn't exist. Failed to remove.>" << endl;
        cout << "[Warning -1]" << endl;
        return;
    }
    n=DiaryFolder.size();
    cout << n << endl;
    for(int i=0;i<n;i++){
        cout << DiaryFolder[i]->date << endl;
    }

    ofstream fout(memory_copy);
    if(!fout.is_open()){
        cout << "failed to open the memory_copy in update.\n";
        return;
    }
    ifstream fin(memory);
    if(!fin.is_open()){
        cout << "failed to open the memory in update.\n";
        return;
    }

    string temp_line, judge_date;
    while(getline(fin, temp_line)){
        if(temp_line=="*New_Diary*"){
            getline(fin, judge_date);
            if(judge_date==remove_date){
                while(getline(fin, temp_line))
                    if(temp_line=="*End_Diary*")    break;
            }else{
                fout << temp_line << endl;
                fout << judge_date << endl;
            }
        }else{
            fout << temp_line << endl;
        }
    }
    fin.close();
    fout.close();

    fin.open(memory_copy);
    if(!fin.is_open()){
        cout << "failed to open the memory_copy in update_copy.\n";
        return;
    }
    fout.open(memory);
    if(!fout.is_open()){
        cout << "failed to open the memory in update_copy.\n";
        return;
    }

    cout << "<Successfully removed the diary.>" << endl;
    while(getline(fin, temp_line))  fout << temp_line << endl;
    fin.close();
    fout.close();

}

/* this function add a new diary to the diaryfolder
by copy the other diarys to memory_copy and then copy them back to memory.
then, add the new diary to the end (by append).
*/
void C_Folder::add_to_folder(string add_date){

    int find_date=0;
    int n=DiaryFolder.size();
    
    for(int i=0;i<n;i++){
        if(DiaryFolder[i]->date==add_date){
            find_date=1;
            DiaryFolder.erase(DiaryFolder.begin()+i);
            break;
        }
    }
    if(find_date==1)    cout << "[Warning, the date " << add_date << " is being replaced]" << endl;
    cout << "<Please type in the content of the diary>" << endl;

    // n=DiaryFolder.size();
    // for(int i=0;i<n;i++){
    //     cout << DiaryFolder[i]->date << endl;
    // }

    ofstream fout(memory_copy);
    if(!fout.is_open()){
        cout << "failed to open the memory_copy in add.\n";
        return;
    }
    ifstream fin(memory);
    if(!fin.is_open()){
        cout << "failed to open the memory in add.\n";
        return;
    }
    string temp_line, judge_date;
    while(getline(fin, temp_line)){
        if(temp_line=="*New_Diary*"){
            getline(fin, judge_date);
            if(judge_date==add_date){
                while(getline(fin, temp_line))
                    if(temp_line=="*End_Diary*")    break;
            }else{
                fout << temp_line << endl;
                fout << judge_date << endl;
            }
        }else{
            fout << temp_line << endl;
        }
    }
    fin.close();
    fout.close();

    fin.open(memory_copy);
    if(!fin.is_open()){
        cout << "failed to open the memory_copy in add_copy.\n";
        return;
    }
    fout.open(memory);
    if(!fout.is_open()){
        cout << "failed to open the memory in add_copy.\n";
        return;
    }

    while(getline(fin, temp_line))  fout << temp_line << endl;
    fin.close();
    fout.close();

    C_Diary* new_diary = new C_Diary;
    new_diary->date=add_date;
    fout.open(memory, ios::app);

    fout << "*New_Diary*" << endl;
    fout << add_date;
    while(getline(cin, temp_line)){
        fout << temp_line << endl;
        new_diary->content+=temp_line;
        new_diary->content+="\n";
        if(!temp_line.compare("."))
            break;
    }
    fout << "*End_Diary*" << endl;
    
    DiaryFolder.push_back(new_diary);
    this->sort_folder();

}

/*this function search a specific date in the diaryfolder
and print it to the screen.
*/
void C_Folder::search_folder(string show_date){
    int n=DiaryFolder.size(), find_date=0;
    for(int i=0;i<n;i++){
        if(DiaryFolder[i]->date==show_date){
            DiaryFolder[i]->write_diary();
            find_date=1;
            break;
        }
    }
    if(find_date==0)    cout << "[Warning, the date " << show_date << " doesn't exist.]" << endl;
    return;
}

/*this function search the diary between start_date and end_date
and print it to the screen.
*/
void C_Folder::list_folder(string start_date, string end_date){

    int n=DiaryFolder.size(), find_date=0;
    for(int i=0;i<n;i++){
        if(DiaryFolder[i]->date >= start_date){
            if(DiaryFolder[i]->date >end_date)  break;
            else    DiaryFolder[i]->write_diary(), find_date=1;
        }
    }
    if(find_date==0)    cout << "[Warning, there's no diary between date " << start_date << " and date " << end_date << ".]" << endl;
    return;


}