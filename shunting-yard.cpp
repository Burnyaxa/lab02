#include "shunting-yard.h"
//#include "stackArray.h"
#include <stack>

string ctos(char ch){
	stringstream ss;
	string target;
	ss << ch;
	ss >> target;
	return target;
}

int calculate(int first, int second, char operation){
	switch (operation){
	case '+':
		return first + second;
		break;
	case '-':
		return first - second;
		break;
	case '*':
		return first * second;
		break;
	case '/':
		return first / second;
		break;
	case '^':
		return pow(first, second);
		break;
	}
}

int shuntingYard(string row){
	stack <int> output;
	stack <char> oper;
	string token, integer, temp;
	int first, second;
	char out;
	for (int i = 0; i < row.size(); i++){
			token = row[i];
			if (isdigit(token[0])){
				integer += row[i];
				continue;
			}
			if (!isdigit(token[0]) && integer.size()){
				output.push(stoi(integer));
				integer.clear();
			}
			if (!isdigit(token[0]) && !isspace(token[0])){
				if (oper.empty()){
					oper.push(token[0]);
				}
				else{
					//oper.top(temp);
					operation current(token[0]);
					//operation prev(temp[0]);
					operation prev(oper.top());
					if (prev.getPriority() > current.getPriority()){
						out = oper.top();
						oper.pop();
						second = output.top();
						output.pop();
						first = output.top();
						output.pop();
						output.push(calculate(first, second, out));
						oper.push(token[0]);
					}
					else{
						oper.push(token[0]);
					}
				}
			}
		}
	while (!oper.empty()){
		out = oper.top();
		oper.pop();
		second = output.top();
		output.pop();
		first = output.top();
		output.pop();
		output.push(calculate(first, second, out));
	}
	out = output.top();
	output.pop();
	return (int)out;
}