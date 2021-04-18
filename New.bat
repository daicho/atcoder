@echo off

set /P contest_name="コンテスト名："

set contest_url="https://atcoder.jp/contests/%contest_name%"
set open_url=%contest_url%
set open_url=%open_url% %contest_url%/tasks
set open_url=%open_url% %contest_url%/tasks/%contest_name%_a
set open_url=%open_url% %contest_url%/tasks/%contest_name%_b
set open_url=%open_url% %contest_url%/tasks/%contest_name%_c
set open_url=%open_url% %contest_url%/tasks/%contest_name%_d
set open_url=%open_url% %contest_url%/tasks/%contest_name%_e
set open_url=%open_url% %contest_url%/tasks/%contest_name%_f

if %contest_name:~0,3% == abc (
    set dir_name="abc\"
) else if %contest_name:~0,3% == arc (
    set dir_name="arc\"
) else if %contest_name:~0,3% == agc (
    set dir_name="agc\"
) else (
    set dir_name="contests\"
)

xcopy template %dir_name%%contest_name%\ /d /e > nul
start chrome %open_url%
