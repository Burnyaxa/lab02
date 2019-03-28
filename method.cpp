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


string ConvDoub (string &line)
{
	int size = line.size();
	for (int i = 1; i < size; i++)
	{
		if (line[i - 1] == line[i])
		{
			if (isdigit(line[i-1])) { continue; }
			if (line[i-1] == '(' || line[i - 1] == ')') { continue; }

			if (readOper(line[i - 1]))
			{
				while (line[i - 1] == line[i])
				{
					int temp = readOper(line[i - 1]);
					if (temp > 2)
					{
						cout << "there not correct input\n";
						string err = "it is wrong: ";
						err = err + line[i - 1] + line[i];
						return err;
					}
					if (temp == 1) { line.erase(i - 1, 1); size--; continue; }
					if (temp == 2)
					{
						if (readOper(line[i + 1]))
						{
							if (temp > 2)
							{
								cout << "there not correct input\n";
								string err = "it is wrong: ";
								err = err + line[i - 1] + line[i];
								return err;
							}
							if (temp == 1) { line.erase(i - 1, 1); size--; continue; }
							if (temp == 2) { line.erase(i - 1, 2); size -= 2; continue; }
						}
						else { line[i - 1] = '+'; line.erase(i, 1); size--; continue; }
					}
				}
				continue;
			}
			cout << "problem in ConvDoub\ni: "<<i<<endl;
		}
	}
	return line;
}


int readOper(char token)
{
	if (token == '+') { return 1; }
	if (token == '-') { return 2; }
	if (token == '*') { return 3; }
	if (token == '/') { return 4; }
	return 0;
}
