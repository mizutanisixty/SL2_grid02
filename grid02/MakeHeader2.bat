echo off
color 0b
:start
cls
echo *******************************************************************
echo.
echo 			ヘッダファイルジェネレーター
echo.
echo *******************************************************************
echo ヘッダファイルの名前を入力してください (.hは不要です)
echo.
echo.
echo ファイル名は絶対パス、相対パス、ファイル名のいずれか
echo [基準フォルダ]
echo %~dp0
echo.
echo ファイル名のみの場合は基準フォルダにあるファイルをチェックします
echo 基準フォルダにあるファイルをチェックします
echo.
rem ファイル名入力
set fName=
set /p fName="ファイル名を入力してください > "
echo.
if "%fName%" == "q" goto end
if exist %fName%.h (
	echo ファイル〝%fName%.h〟は既に存在しています
	set /p res="エクスプローラーを開きますか？ (Y/N) > "
	if "%res%"=="y" goto exp
	if "%res%"=="Y" goto exp
	goto nExp
	:exp
pause
	explorer.exe /select,%~dp0%fName%.h
	goto nExp
) else (
	set /p init="includer_std.h, define.hをインクルードしますか？(Y/N) > "
	echo #ifndef __%fName%__ >> %fName%.h
	echo #define __%fName%__ >> %fName%.h
	if "%init%"=="y" goto Init
	if "%init%"=="Y" goto Init
	goto nInit
	:Init
	echo #include "includer_std.h" >> %fName%.h
	echo #include "define.h" >> %fName%.h
	:nInit
	echo. >> %fName%.h
	echo. >> %fName%.h
	echo. >> %fName%.h
	echo #endif >> %fName%.h
)

:nExp
echo.
echo.
echo 何かキーを押してください
echo # 終わる場合はファイル名に q と入力してください
pause > nul
goto start
:end
