#pragma once
#include <iostream>
#include <string>

template <typename T>
struct stack{
	T *data;
	int size;
	int last;
	stack(int initialSize = 10){
		last = -1;
		size = initialSize;
		data = new T[initialSize];
	}

	void push(const T value){
		last++;
		if (last == size){
			resizeArray();
		}
		data[last] = value;
	}
	void resizeArray(){
		T *newData = new T[size * size];
		for (int i = 0; i < size; i++){
			newData[i] = data[i];
		}
		size *= size;
		delete[] data;
		data = newData;
	}
	bool pop(T &out){
		if (last == -1) return false;
		out = this->data[last--];
		return true;
	}
	bool top(T &out){
		if (last == -1) return false;
		out = data[last];
		return true;
	}
	bool isEmpty(){
		if (last == -1) return true;
		return false;
	}
	void clear(){
		T temp;
		while (!isEmpty()){
			pop(temp);
		}
	}
};

