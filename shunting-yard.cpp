#include "shunting-yard.h"
#include "stackArray.h"

string ctos(char ch){
	stringstream ss;
	string target;
	ss << ch;
	ss >> target;
	return target;
}

string shuntingYard(string row){
	stack output;
	stack oper;
	string token, temp, out, rpn;
	for (int i = 0; i < row.size(); i++){
		if (isdigit(row[i])){
			token += row[i];
			continue;
		}
		if (isdigit(row[i - 1]) || (i = row.size() - 1)){
			output.push(token);
			token.clear();
		}

		if (!isdigit(row[i]) && !isspace(row[i])){
			if (oper.isEmpty()){
				oper.push(ctos(row[i]));
			}
			else{
				oper.top(temp);
				operation current(row[i]);
				operation prev(temp[0]);
				if (prev.getPriority() > current.getPriority()){
					oper.pop(out);
					output.push(out);
					oper.push(ctos(row[i]));
				}
			}
		}
	}
	while (!oper.isEmpty()){
		oper.pop(out);
		output.push(out);
	}
	while (!output.isEmpty()){
		output.pop(out);
		rpn += out;
	}
	return rpn;
}