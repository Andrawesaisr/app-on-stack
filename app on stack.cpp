// application on array.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
// made by andrew.aisr
#include <iostream>
#include<stack>
using namespace std;
bool isOperator(char ch) {
	return ch == '(' ||ch == ')' || ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '%' || ch == '^';
}
int checkBiger(char ch) {
	switch (ch) {
	case'(':
		return 0;
	case'+':
	case'-':
		return 1;
	case'*':
	case'/':
	case'%':
		return 2;
	case'^':
		return 3;
	defult:
		return -1;
	}
}
int main()
{
	string infix, post = "";
	cout << "enter the infix ";
	cin >> infix;
	stack<int>operand;
	stack<char>oper;
	oper.push('(');
	infix += ')';

	for (int i = 0;i < infix.length();i++) {
		if (isOperator(infix[i])) {
			if (infix[i] == ')') {
				while (oper.top() != '(') {
					post += oper.top();
					oper.pop();
				}
				oper.pop();
			}
			else if (infix[i] == '(' || checkBiger(infix[i]) > checkBiger(oper.top())) {
				oper.push(infix[i]);
			}
			else {
				while (checkBiger(oper.top()) >= checkBiger(infix[i])) {
					post += oper.top();
					oper.pop();
				}
				oper.push(infix[i]);
			}
		}
		else {
			post += infix[i];
		}
	}  
	if (!oper.empty()) {
		cout << "invalid expression";
		system("pause");
		exit(1);

	}
	cout << "postfix is : " << post << endl;
}


