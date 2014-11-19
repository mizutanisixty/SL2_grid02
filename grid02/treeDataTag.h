#ifndef __treeDataTag__ 
#define __treeDataTag__ 
#include "includer_std.h"
#include "define.h"

namespace tag{
	typedef unsigned char byte;

	typedef enum _tag_t{
		t_end,
		t_byte,
		t_short,
		t_int,
		t_long,
		t_float,
		t_double,
		t_byte_array,
		t_string,
		t_list,
		t_compound,
		t_int_array
	} tag_t;

	class tag_basic{
	protected:
		tag_t type;
		size_t size;
		bool isArray;
		friend return_t del(){
			return RETURN_SUCCESS;
		};
	public:
		tag_basic(){
			type = t_end;
			isArray= false;
			size = 0;
		};
		~tag_basic(){

		};
		operator tag_t(){
			return type;
		};
	};

	template <class T, tag_t tagClassId> class _tag_array_helper : public tag_basic{
	private:
		vector<T> data;
	public:
		_tag_array_helper(){
			isArray = true;
			type = tagClassId;
		};
		~_tag_array_helper(){

		};
		return_t push_back(T param){
			data.push_back(param);
			return RETURN_SUCCESS;
		};
		return_t erase(size_t id){
			data.erase(data.begin() + id);
			return RETURN_SUCCESS;
		};
		bool a(size_t id){
			return data.size() > id;
		};
		return_t pop_back(T &dat){
			if(data.empty())
				return RETURN_FAILED;
			dat = data[data.size() - 1];
			data.pop_back();
			return RETURN_SUCCESS;
		};
		bool empty(){
			return data.empty();
		};
	};

	template <class T, tag_t tagClassId> class _tag_number_helper : public tag_basic{
	private:
		T data;
	public:
		_tag_number_helper(){
			type = tagClassId;
		};
		_tag_number_helper(T i){
			type = tagClassId;
			data = i;
		};
		~_tag_number_helper(){};
		_tag_number_helper& operator= (T param){
			data = param;
			return *this;
		};
		_tag_number_helper& operator= (_tag_number_helper param){
			data = (T)param;
			return *this;
		};
		operator T(){
			return data;
		};
	};

	class tag_string : public tag_basic{
	private:
		std::string data;
	public:
		tag_string(){
			type = t_string;
		};
		~tag_string(){};
		operator string(){
			return data;
		};
		string& _helper_getData(){
			return data;
		};
		tag_string& operator= (string param){
			data = param;
			return *this;
		};
		tag_string& operator= (char* param){
			data = param;
			return *this;
		};
		tag_string& operator= (tag_string param){
			data = param._helper_getData();
			return *this;
		};
		operator const char*(){
			return data.c_str();
		};
	};

	class tag_end : public tag_basic{
	private:
	public:
		tag_end(){
			type = t_end;
		};
		~tag_end(){};
	};

	//Array系クラスの定義
	typedef _tag_number_helper<byte, t_byte> tag_byte;
	typedef _tag_number_helper<short, t_short> tag_short;
	typedef _tag_number_helper<int, t_int> tag_int;
	typedef _tag_number_helper<long, t_long> tag_long;
	typedef _tag_number_helper<float, t_float> tag_float;
	typedef _tag_number_helper<double, t_double> tag_double;
	//中身は
	//typedef _tag_array_helper<_tag_integer_helper<unsigned char, t_byte>, t_byte_array> tag_byte_array;
	//的な？
	typedef _tag_array_helper<tag_byte, t_byte_array> tag_byte_array;
	typedef _tag_array_helper<tag_int, t_int_array> tag_int_array;

	class dat{
	private:
		bool empty;
		tag_t type;
	public:
		dat(){};
		~dat(){};
		dat& operator= (tag_end p){
			type = t_end;
			return *this;
		};

	};
/*
	[v] tag_end
	[v] tag_byte
	[v] tag_short
	[v] tag_int
	[v] tag_long
	[v] tag_float
	[v] tag_double
	[v] tag_byte_array
	[v] tag_string
	[ ] tag_list
	[ ] tag_compound
	[v] tag_int_array
*/
}
#endif 
