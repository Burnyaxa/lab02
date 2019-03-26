#include <sstream>
#include <string>
#include "stackArray.h"
using namespace std;

class operation{
	int priority;
public:
	operation(char op){
		switch (op){
		case '+':
		case '-':
			this->priority = 1;
			break;
		case '*':
		case '/':
			this->priority = 2;
			break;
		case '^':
			this->priority = 3;
			break;
		}
	}
	int getPriority(){
		return this->priority;
	}
};

int calculate(int first, int second, char operation);
int shuntingYard(string row);