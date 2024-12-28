@echo off

REM Set build variables
set PWDDIR=%cd%
for /f "tokens=*" %%a in ('where g++') do set GPPPATH=%%a
for /f "tokens=3 delims= " %%a in ('g++ --version ^| findstr g++') do set GPPVER=%%a
for /f "tokens=*" %%a in ('g++ -dumpmachine') do set MACHINEVER=%%a

REM Create build directory
if not exist "%PWDDIR%\build" (
    mkdir "%PWDDIR%\build"
)

REM Check if previous version of main.exe exists
if exist "%PWDDIR%\build\main.exe" (
    echo Cleaning up...
    del "%PWDDIR%\build\*.exe"
)

REM Check if g++ exists
if "%GPPPATH%"=="" (
    echo g++ is not installed. Search and install it with your package manager or compiler suite before executing this script.
    exit /b 1
)

REM Build the main program
echo Building with GCC %GPPVER% (g++) for %MACHINEVER%...
g++ main.cpp -o "%PWDDIR%\build\main.exe"

REM Check if program builded successfully
if exist "%PWDDIR%\build\main.exe" (
    echo Build completed successfully. The executable is located in the build directory.
) else (
    echo Build failed.
    exit /b 1
)

pause
