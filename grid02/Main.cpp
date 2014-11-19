#include "includer_std.h"
#include "api.h"

int main(){
	cui << "Hello! World" << endl;
	tag::_tag_number_helper<int, tag::t_int> i, j;
	tag::tag_int_array tIntArr;
	i = 30;
	j = i;
	cout << j << endl;

	return RETURN_SUCCESS;
}
