@echo off
set /P file_name="File Name : "
set file_path=intermediate\%file_name%.cpp

if not exist %file_path% (
    copy Template.cpp %file_path% /-Y
)
