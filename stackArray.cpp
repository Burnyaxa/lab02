#include "stackArray.h"

void stack::push(const string value){
	last++;
	if (last == size){
		resizeArray();
	}
	data[last] = value;
}

bool stack::pop(string &out){
	if (last == -1) return false;
	out = this->data[last--];
	return true;
}

bool stack::top(string &out){
	if (last == -1) return false;
	out = data[last];
	return true;
}

bool stack::isEmpty(){
	if (last == -1) return true;
	return false;
}

void stack::clear(){
	string temp;
	while (!isEmpty()){
		pop(temp);
	}
}

void stack::resizeArray(){
	string *newData = new string[size + 10];
	for (int i = 0; i < size; i++){
		newData[i] = data[i];
	}
	size += 10;
	delete[] data;
	data = newData;
	delete[] newData;
}