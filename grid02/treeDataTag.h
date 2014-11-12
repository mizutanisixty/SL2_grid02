#ifndef __treeDataTag__ 
#define __treeDataTag__ 
#include "includer_std.h"
#include "define.h"

namespace tag{
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
	public:
		tag_basic(){

		};
		~tag_basic(){

		}
	};

	class _tag_array_helper{
	public:
		_tag_array_helper(){

		};
		~_tag_array_helper(){

		};
	};
}
#endif 
