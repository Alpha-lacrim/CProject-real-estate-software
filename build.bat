@echo off
where gcc >nul 2>nul
if errorlevel 1 (
    echo gcc was not found on PATH. Install MinGW-w64 or build with your preferred Windows C compiler.
    exit /b 1
)

gcc -Wall -Wextra -std=c11 -o real_estate.exe main.c
