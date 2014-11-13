#ifndef __treeDataTag__ 
#define __treeDataTag__ 
#include "includer_std.h"
#include "define.h"

namespace tag{

typedef unsigned char byte;

	typedef enum{
		tag_end,
		tag_byte,
		tag_short,
		tag_int,
		tag_long,
		tag_float,
		tag_double,
		tag_byte_array,
		tag_string,
		tag_list,
		tag_compound,
		tag_int_array,
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
			type = tag_end;
			isArray= false;
			size = 0;
		};
		~tag_basic(){

		};
	};

	template <class T> class _tag_array_helper : public tag_basic{
	private:
		vector<T> data;
	public:
		_tag_array_helper(){
			isArray = true;
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
}
#endif 
