@echo off

REM python code path
set py="python\pass\pass.py"

REM log file path
set log="python\pass\pass.txt"

IF "%1"=="cat" (
    IF EXIST %log% (
        type %log%
        exit
    ) ELSE (
        echo Error: File is empty or not found.
        exit
    )
) ELSE IF "%1"=="clear" (
    IF EXIST %log% (
        del %log%
        echo => The log file has been successfully cleared.
        exit
    ) ELSE (
        echo Error: File is already cleared or deleted.
        exit
    )
)

python %py%