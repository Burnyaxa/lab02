#include <iostream>
#include <string>
using namespace std;

struct stack{
	char *data;
	int size;
	int last;
	stack(int initialSize = 10){
		last = -1;
		size = initialSize;
		data = new char[initialSize];
	}

	void push(char value);
	void resizeArray(); 
	bool pop(char &out); 
	bool top(char &out); 
	bool isEmpty(); 
	void clear(); 
};