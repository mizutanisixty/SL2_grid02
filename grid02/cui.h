#ifndef __grid_cui__
#define __grid_cui__

#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
#include <Windows.h>
#include <ImageHlp.h>
#pragma comment(lib, "imagehlp.lib")	//Win32API
#include "define.h"
#include "algorithm.h"

#ifdef add_one_and_new
#undef add_one_and_new
#endif
#define add_one_and_new(arr, T, pos) arr.add(1), arr[pos] = new T

using namespace std;

class CUI{
private:
	bool useBuf, useFile;
	ofstream ofs;
	string log_path;

public:	
	string str;

	void output(string tmp){
		if(useBuf)
			str += tmp;
		else
			cout << tmp;

		if(useFile && ofs.is_open())
			ofs << tmp;
	};

	template<typename U> U input(){
		U tmp;
		cin >> tmp;
		if(useFile && ofs.is_open())
			ofs << tmp << endl;
		return tmp;
	}

	CUI(){
		setlocale( LC_ALL, "Japanese" );	//Unicode文字の設定
		useBuf = false;
		useFile = false;
		log_path = "../logging/";
		[&]{
			string buf;
			bool found = false;
			std::ifstream ifs(setting_path);
			auto setDef = [&]{
				std::ofstream ofs(setting_path, ios::app);
				if(ofs.fail())
					return ;
				//"デフォルトの書き込み"
				ofs << "log_path=" << log_path << endl;
				ofs.close();
			};
			if(ifs.fail()){
				setDef();
				ifs.close();
				ifs.open(setting_path);
			}
			size_t pos1;
			char tmp[256], *seek;
			while(std::getline(ifs, buf) != NULL){
				strcpy(tmp, buf.c_str());
				if( (pos1 = buf.find('=')) != string::npos){
					tmp[pos1] = '\0';
					seek = tmp + pos1 + 1;
					if(!strcmp(tmp, "log_path")){
						log_path = seek;
						found = true;
						return ;
					}
				}
			}
			if(!found)
				setDef();
			ifs.close();
		}();
#ifdef __debug__
		output("log_path = ");
		output(log_path);
		output("\n");
#endif
	};

	~CUI(){
		if(ofs.is_open())
			ofs.close();
	};

	void switchBuf(bool useBuffer){
		useBuf = useBuffer;
	};

	void switchFileBuf(bool useFileBuffer, string _path = "output.txt", bool append = true){
		string path = log_path + _path;
		//"/"を"\\"に置換
		size_t sPos;
		while((sPos=path.find("/")) != string::npos)
			path.replace(sPos,1,"\\");
		//フォルダが無ければ作る
		MakeSureDirectoryPathExists(path.c_str());	//Win32API
		useFile = useFileBuffer;
		if(useFile){
			if(ofs.is_open())
				ofs.close();
			if(append)
				ofs.open(path, ios::app);	//app = 追記
			else
				ofs.open(path);
			if(ofs.fail()){
				output("failed to open log file.\n");
			}
		}
	};

	bool fileWriting(){
		return (useFile && ofs.is_open());
	};

	//マニピュレータ
	CUI& operator <<(CUI& (*p)(CUI&)){
		return (*p)(*this);
	};

	//一行入力
	void getline(string &str){
		std::getline(cin, str);
		if(useFile && ofs.is_open())
			ofs << str << endl;
	};

	//メッセージボックス
	CUI& operator ()(string str, string title, UINT uType = MB_OK){
		WCHAR mes[257], head[257];
		auto ctowc = [&](WCHAR t2[], string str){
			char t[257];
			strcpy_s(t,256,str.c_str());
			t[256] = '\0';
			mbstowcs(t2, t, 256);
		};
		ctowc(mes, str);
		ctowc(head, title);
		MessageBox(NULL, mes, head, uType);
		return *this;
	};
	
	//出力
	CUI& operator << (short num){
		char tmp[32]={0,};
		math::itoa<short>(num,tmp);
		output(tmp);
		return *this;
	};

	CUI& operator << (int num){
		char tmp[32]={0,};
		math::itoa<int>(num,tmp);
		output(tmp);
		return *this;
	};

	CUI& operator << (long num){
		char tmp[32]={0,};
		math::itoa<long>(num,tmp);
		output(tmp);
		return *this;
	};

	CUI& operator << (long long num){
		char tmp[32]={0,};
		math::itoa<long long>(num,tmp);
		output(tmp);
		return *this;
	};

	CUI& operator << (unsigned short num){
		char tmp[32]={0,};
		math::itoa<unsigned short>(num,tmp);
		output(tmp);
		return *this;
	};

	CUI& operator << (unsigned int num){
		char tmp[32]={0,};
		math::itoa<unsigned int>(num,tmp);
		output(tmp);
		return *this;
	};

	CUI& operator << (unsigned long num){
		char tmp[32]={0,};
		math::itoa<unsigned long>(num,tmp);
		output(tmp);
		return *this;
	};

	CUI& operator << (unsigned long long num){
		char tmp[32]={0,};
		math::itoa<unsigned long long>(num,tmp);
		output(tmp);
		return *this;
	};

	CUI& operator << (char s){
		char tmp[2] = {s, '\0'};
		output(tmp);
		return *this;
	};

	
	CUI& operator << (string s){
		output(s);
		return *this;
	};
	
	CUI& operator << (char s[]){
		output(s);
		return *this;
	};

	//入力
	CUI& operator >> (short &num){
		num = input<short>();
		return *this;
	};

	CUI& operator >> (int &num){
		num = input<int>();
		return *this;
	};

	CUI& operator >> (long &num){
		num = input<long>();
		return *this;
	};

	CUI& operator >> (long long &num){
		num = input<long long>();
		return *this;
	};

	CUI& operator >> (unsigned short &num){
		num = input<unsigned short>();
		return *this;
	};

	CUI& operator >> (unsigned int &num){
		num = input<unsigned int>();
		return *this;
	};

	CUI& operator >> (unsigned long &num){
		num = input<unsigned long>();
		return *this;
	};

	CUI& operator >> (unsigned long long &num){
		num = input<unsigned long long>();
		return *this;
	};

	CUI& operator >> (char &s){
		s = input<char>();
		return *this;
	};

	CUI& operator >> (string &s){
		s = input<string>();
		return *this;
	};
	
	CUI& operator >> (char s[]){
		s = input<char*>();
		return *this;
	};

	
};

CUI& endl(CUI& manip){
	manip.output("\n");
	return manip;
}

CUI& cls(CUI& manip){
	system("cls");
	return manip;
}

CUI& clear(CUI& manip){
	manip.str = "";
	return manip;
}

CUI& show(CUI& manip){
	manip.output(manip.str);
	return manip;
}

CUI& bs(CUI& manip){
	manip.output("\b");
	manip.output(" ");
	manip.output("\b");
	return manip;
}

CUI& beep(CUI& manip){
	putchar('\a');
	return manip;
}

//インスタンス生成
CUI cui;
//ここまでインスタンスの条件式

#endif
