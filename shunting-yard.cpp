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
	string token, integer, temp, out;
	int first, second, result;
	bool bracket;
	for (int i = 0; i < row.size(); i++){
		token = row[i];
		if (isdigit(token[0])){
			integer += row[i];
			if (i == row.size() - 1){
				output.push(stoi(integer));
				integer.clear();
			}
			continue;
		}
		if (!isdigit(token[0]) && integer.size()){
			output.push(stoi(integer));
			integer.clear();
		}
		if (!isdigit(token[0]) && !isspace(token[0])){
			if (token[0] == '('){
				oper.push(token[0]);
				bracket = 1;
				continue;
			}
			if (token[0] == ')'){
				while (bracket){
					if (oper.top() = '('){
						bracket = 0;
						oper.pop();
						break;
					}
					out = oper.top();
					oper.pop();
					second = output.top();
					output.pop();
					first = output.top();
					output.pop();
					output.push(calculate(first, second, out[0]));
				}
				continue;
			}
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
					output.push(calculate(first, second, out[0]));
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
		output.push(calculate(first, second, out[0]));
	}
	result = output.top();
	output.pop();
	return result;
}