vector <string> charTOvecstring (char*argv[])
{
	vector <string> str;
	for (int i = 0; argv[i]; i++)
	{
		string s(argv[i]);
		str.push_back(s);
	}
	return str;
}

string cmdString(int argc, char*argv[])
{
	string str;
	for(int i = 1; i < argc; i++)
	{
		string a(argv[i]);
		str = str + a + " ";
	}
	
	return str;
}
