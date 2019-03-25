#include <sstream>
#include <string>
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

string ctos(char ch);
string shuntingYard(string row);