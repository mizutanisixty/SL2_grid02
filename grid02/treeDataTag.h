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
			T dat = data[data.size() - 1];
			data.pop_back();
			return RETURN_SUCCESS;
		};
	};

	class tag_int : tag_basic{
	public:
		tag_int(){};
		~tag_int(){};
	};

	//ArrayŒnƒNƒ‰ƒX‚Ì’è‹`
	typedef _tag_array_helper<tag_byte, t_byte_array> tag_byte_array;
	typedef _tag_array_helper<tag_int, t_int_array> tag_int_array;

	typedef union _tag_u{
		tag_end tEnd;
		tag_byte tByte;
		tag_short tShort;
		tag_int tInt;
		tag_long tLong;
		tag_float tFloat;
		tag_double tDouble;
		tag_byte_array tByteArr;
		tag_string tString;
		tag_list tList;
		tag_compound tCompound;
		tag_int_array tIntArr;
	} tag_u;
}
#endif 
