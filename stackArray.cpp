#include "stackArray.h"

void stack::push(const char value){
	last++;
	if (last == size){
		resizeArray();
	}
	data[last] = value;
}

bool stack::pop(char &out){
	if (last == -1) return false;
	out = this->data[last--];
	return true;
}

bool stack::top(char &out){
	if (last == -1) return false;
	out = data[last];
	return true;
}

bool stack::isEmpty(){
	if (last == -1) return true;
	return false;
}

void stack::clear(){
	char temp;
	while (!isEmpty()){
		pop(temp);
	}
}

void stack::resizeArray(){
	char *newData = new char[size + 10];
	for (int i = 0; i < size; i++){
		newData[i] = data[i];
	}
	size += 10;
	delete[] data;
	data = newData;
	delete[] newData;
}