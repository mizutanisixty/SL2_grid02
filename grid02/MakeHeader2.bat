echo off
color 0b
:start
cls
echo *******************************************************************
echo.
echo 			�w�b�_�t�@�C���W�F�l���[�^�[
echo.
echo *******************************************************************
echo �w�b�_�t�@�C���̖��O����͂��Ă������� (.h�͕s�v�ł�)
echo.
echo.
echo �t�@�C�����͐�΃p�X�A���΃p�X�A�t�@�C�����̂����ꂩ
echo [��t�H���_]
echo %~dp0
echo.
echo �t�@�C�����݂̂̏ꍇ�͊�t�H���_�ɂ���t�@�C�����`�F�b�N���܂�
echo ��t�H���_�ɂ���t�@�C�����`�F�b�N���܂�
echo.
rem �t�@�C��������
set fName=
set /p fName="�t�@�C��������͂��Ă������� > "
echo.
if "%fName%" == "q" goto end
if exist %fName%.h (
	echo �t�@�C����%fName%.h���͊��ɑ��݂��Ă��܂�
	set /p res="�G�N�X�v���[���[���J���܂����H (Y/N) > "
	if "%res%"=="y" goto exp
	if "%res%"=="Y" goto exp
	goto nExp
	:exp
pause
	explorer.exe /select,%~dp0%fName%.h
	goto nExp
) else (
	set /p init="includer_std.h, define.h���C���N���[�h���܂����H(Y/N) > "
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
echo �����L�[�������Ă�������
echo # �I���ꍇ�̓t�@�C������ q �Ɠ��͂��Ă�������
pause > nul
goto start
:end
