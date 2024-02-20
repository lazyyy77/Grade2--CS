g++ .\src\diary.cpp .\src\folder.cpp .\src\pdlist.cpp -o pdlist
g++ .\src\diary.cpp .\src\folder.cpp .\src\pdremove.cpp -o pdremove
g++ .\src\diary.cpp .\src\folder.cpp .\src\pdshow.cpp -o pdshow
g++ .\src\diary.cpp .\src\folder.cpp .\src\pdadd.cpp -o pdadd

Get-Content .\testcase\pdshow1.txt | .\pdshow.exe
#test the date (11-19) doesn't exist
Get-Content .\testcase\pdshow2.txt | .\pdshow.exe
#test the the date (11-14) exists. show it.
Get-Content .\testcase\pdadd1.txt | .\pdadd.exe
#test add a new day.
Get-Content .\testcase\pdadd2.txt | .\pdadd.exe
#test cover a existing file (the file created by pdadd1).
Get-Content .\testcase\pdremove1.txt | .\pdremove.exe
#test remove the day that doesn't exist.
Get-Content .\testcase\pdremove2.txt | .\pdremove.exe
#test remove the day that exists.
Get-Content .\testcase\pdlist1.txt | .\pdlist.exe
#test list all
Get-Content .\testcase\pdlist2.txt | .\pdlist.exe
#test list a range with output
Get-Content .\testcase\pdlist3.txt | .\pdlist.exe
#test list a range without output