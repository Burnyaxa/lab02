//#include "stackArray.h"
#include "method.h"
#include "shunting-yard.h"
#include <stack>
void main(int argc, char* argv[])
{
	string row = cmdString(argc,argv);
	cout << row <<  endl;
	cout << shuntingYard(row) << endl;
	system("pause");
}
