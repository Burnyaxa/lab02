#include "method.h"

vector <string> charTOvecstring (char*argv[])
{
	vector <string> str;
	for (int i = 0; argv[i]; i++)
	{
		string s(argv[i]);
		str[i] = s;
	}
	return str;
}
