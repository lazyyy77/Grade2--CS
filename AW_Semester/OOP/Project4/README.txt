*******************
aboout running::
--------------------
Just open the cli and go to the directory
then run .\run.ps1
the input is redirect to ./testcase/... .txt
(run.ps1 is a powershell script)

******************


*******************
about compiling::
--------------------
the compilling command is in the front of the run.ps1
so wait a while when running run.ps1
and, don't need to mannuly compile.
if you insist to compile by yourself,
try:
g++ .\src\diary.cpp .\src\folder.cpp .\src\pdlist.cpp -o pdlist
g++ .\src\diary.cpp .\src\folder.cpp .\src\pdremove.cpp -o pdremove
g++ .\src\diary.cpp .\src\folder.cpp .\src\pdshow.cpp -o pdshow
g++ .\src\diary.cpp .\src\folder.cpp .\src\pdadd.cpp -o pdadd

******************

*******************
aboout checking::
--------------------
the output is print on the screen.
some need to check .\txt\memory.txt

******************