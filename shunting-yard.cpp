#include "shunting-yard.h"
#include "stackArray.h"

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
	string token, strInteger, temp, out;
	int first, second, result;
	int counter = 0;

	for (int i = 0; i < row.size(); i++){
		token = row[i];

		if (isdigit(token[0])){
			strInteger += row[i];
			if (i == row.size() - 1){
				output.push(stoi(strInteger));
				strInteger.clear();
			}
			continue;
		}

		if (!isdigit(token[0]) && strInteger.size()){
			output.push(stoi(strInteger));
			strInteger.clear();
		}
		
		if (token[0] == '-' && counter == 0 && ((output.isEmpty() && oper.isEmpty()) || (!isdigit(row[i -1]) && row[i - 1] != ')' && oper.top(temp[0]) && temp[0] == '(') )){
			counter++;
			strInteger += token;
			continue;
		}
		

		if (!isdigit(token[0]) && !isspace(token[0])){
			if (token[0] == '('){
				oper.push(token[0]);
				counter = 0;
				continue;
			}
			if (token[0] == ')'){
				while (oper.top(temp[0]) && temp[0] != '('){
					oper.pop(out[0]);
					output.pop(second);
					output.pop(first);
					output.push(calculate(first, second, out[0]));
				}
				if (oper.top(temp[0]) && temp[0] == '('){
					oper.pop(temp[0]);
				}
				continue;
			}
			if (oper.isEmpty()){
				oper.push(token[0]);
			}
			else if(oper.top(temp[0]) && temp[0] != '('){
				operation current(token[0]);
				oper.top(temp[0]);
				operation prev(temp[0]);
				if (prev.getPriority() >= current.getPriority()){
					oper.pop(out[0]);
					output.pop(second);
					output.pop(first);
					output.push(calculate(first, second, out[0]));
					oper.push(token[0]);
				}
				else{
					oper.push(token[0]);
				}

			}
			else if (oper.top(temp[0]) && temp[0] == '('){
				oper.push(token[0]);
			}
		}
	}

	while (!oper.isEmpty()){
		oper.pop(out[0]);
		output.pop(second);
		output.pop(first);
		output.push(calculate(first, second, out[0]));
	}

	output.pop(result);
	return result;
}
