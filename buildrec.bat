@echo off

set /A "i=0"
if exist "%cd%\bin-int\" (
	rmdir "%cd%\bin-int\" /q /s
	mkdir "%cd%\bin-int\"
) else (
	mkdir "%cd%\bin-int\"
)

setlocal ENABLEDELAYEDEXPANSION
for /f %%f in ('dir /b recourses') do (
	call xxd.exe -i "recourses/%%f" > bin-int/recourses-!i!.rec
	echo. >> bin-int/recourses-!i!.rec
	echo !i!
	set /A i+=1
)
endlocal

cd bin-int
copy /b "*.rec" "..\src\Recourses.h"
