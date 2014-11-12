echo off
color 0b
cls
echo.
echo.
set /p fName="ファイル名を入力してください (.hは不要です) > "
echo.
if exist %fName%.h (
	echo %fName%.hはすでに存在しています
) else (
	echo #ifndef __%fName%__ >> %fName%.h
	echo #define __%fName%__ >> %fName%.h
	echo #include "includer_std.h" >> %fName%.h
	echo #include "define.h" >> %fName%.h
	echo #endif >> %fName%.h
	echo %fName%.h の生成に成功しました。
)
echo.
pause
