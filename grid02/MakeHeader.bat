echo off
color 0b
cls
echo.
echo.
set /p fName="�t�@�C��������͂��Ă������� (.h�͕s�v�ł�) > "
echo.
if exist %fName%.h (
	echo %fName%.h�͂��łɑ��݂��Ă��܂�
) else (
	echo #ifndef __%fName%__ >> %fName%.h
	echo #define __%fName%__ >> %fName%.h
	echo #include "includer_std.h" >> %fName%.h
	echo #include "define.h" >> %fName%.h
	echo #endif >> %fName%.h
	echo %fName%.h �̐����ɐ������܂����B
)
echo.
pause
