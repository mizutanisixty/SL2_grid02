#include "includer_std.h"
#include "api.h"

int main(){
	cui << "Hello! World" << endl;
	tag::_tag_number_helper<int, tag::t_int> i, j;
	tag::tag_int_array ia;
	i = 30;
	j = i;
	cout << j << endl;
	tag::tag_string s;
	s = "test\n";
	cout << s;
	for(int i=0; i<30; i++)
		ia.push_back(i);
	while(ia.empty())
		cout << (ia.pop_back(i), i) << endl;

	return RETURN_SUCCESS;
}
