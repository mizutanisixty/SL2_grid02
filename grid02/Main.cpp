#include "includer_std.h"
#include "api.h"

#define fatalException(reason) exit(failed(reason))
#define Exception(reason) {error(reason); queue|=QUEUE_CONTINUE; return RETURN_FAILED;}

#define maf(type) finalData = ma(void*,1)


int failed(const char* str){
	WORD s = grep_strong_2;
	cui << "\n\n";
	grep(debug_message_line_fatal,"*",s);
	cui << "\n\n\t\t\t\t";
	grep("STOP", "STOP", s);
	cui << "\n\tReason : " << str << "\n\n";
	grep(debug_message_line_fatal,"*",s);
	cui << "\n";
	return -1;
}

int error(const char* str){
	cui << "\n";
	grep(debug_message_line, "-");
	cui << "\n\t\t\t\t";
	grep("STOP", "STOP");
	cui << "\n\tReason : " << str << "\n";
	grep(debug_message_line,"-");
	cui << "\n";
	return -1;
}

int main(){
	cui << "Hello! World" << endl;
	tag::_tag_number_helper<int, tag::t_int> i, j;
	tag::tag_int_array ia;
	i = 30;
	j = i;
	cui << j << endl;
	tag::tag_string s;
	s = "test\n";
	cui << s;
	for(int i=0; i<30; i++)
		ia.push_back(i);
	while(!ia.empty()|true)
		cui << ia.pop_back() << endl;

	return RETURN_SUCCESS;
}
