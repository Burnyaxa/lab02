#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct stack{
	string  *data;
	int size;
	int last;
	stack(int initialSize = 10){
		last = -1;
		size = initialSize;
		data = new string[initialSize];
	}

	void push(const string value);
	void resizeArray(); 
	bool pop(string &out); 
	bool top(string &out); 
	bool isEmpty(); 
	void clear(); 
};