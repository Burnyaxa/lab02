#include "method.h"

string cmdString(int argc, char*argv[]){
	string str;
	for (int i = 1; i < argc; i++){
		str += argv[i];
	}
	return str;
}


