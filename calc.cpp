// INCLUDE [[ 
#include <iostream>
#include <cctype>
#include <sstream>
#include <stack>
#include <string>
#include <cmath>
// ]]

using namespace std;

// isOperator ----- [[
bool isOperator (char c){
	return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}
// ----- ]]

// precedence ----- [[
int precedence (char op){
	switch (op){
		case '+':
		case '-':
			return 1;
		case '*':
		case '/':
			return 2;
		case '^':
			return 3;
		default:
			return 0;
	}
}
// ----- ]]

// applyOp ----- [[
double applyOp (double a, double b, char op){
	switch (op){
		case '+':
			return a+b;
		case '-':
			return a-b;
		case '*':
			return a*b;
		case '/':
			return a/b;
		case '^':
			return pow(a, b);
		default:
			return 0;
	}
}
// ----- ]]

// doMath ----- [[
double doMath (const string& expr){
	stack<double> num;
	stack<char> op;
	stringstream ss(expr);
	string hui;

	while (getline(ss, hui, ' ')){
		// continue if hui is empty
		if (hui.empty()) continue;
		// push hui in num stack if it is number
		if (isdigit(hui[0])){
			double n;
			stringstream(hui) >> n;
			num.push(n);
		}
		// if hui is operator, do operation on numbers and then pop it
		else if (isOperator(hui[0])){
			char p = hui[0];

			while (!op.empty() && precedence(op.top()) >= precedence(p)){
				double b = num.top();
				num.pop();
				double a = num.top();
				num.pop();
				char p = op.top();
				op.pop();
				num.push(applyOp(a, b, p));
			}
			// push hui to op stack
			op.push(p);
		}
		// push '(' to op stack
		else if (hui[0] == '('){
			op.push('(');
		}
		// applying 2 nums and one operator and then pop it until operators is not empty
		else if (hui[0] == ')'){
			while (!op.empty() && op.top() != '('){
				double b = num.top();
				num.pop();
				double a = num.top();
				num.pop();
				char p = op.top();
				op.pop();
				num.push(applyOp(a, b, p));
			}
			op.pop();
		}
	}

	while (!op.empty()){
		double b = num.top();
		num.pop();
		double a = num.top();
		num.pop();
		char p = op.top();
		op.pop();
		num.push(applyOp(a, b, p));
	}
	return num. top();
}
// ----- ]]

// MAIN ----- [[
int main() {
	cout << "Welcome to calc!\nType 'exit' to exit" << endl;
	while (true){
		string c;
		getline(cin, c);
		if (c != "exit"){
			cout << "Result: " << doMath(c) << endl;
		}
		else {
			break;
		}
	}

	return 0;
}
// ----- ]]
