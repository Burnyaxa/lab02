#include "stackArray.h"
#include "method.h"
#include "shunting-yard.h"

void main(int argc, char* argv[]){
	string row = cmdString(argc,argv);
	cout << "Result: "<< shuntingYard(row) << endl;
	system("pause");
}
