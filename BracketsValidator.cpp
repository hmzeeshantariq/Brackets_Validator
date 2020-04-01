#include "Stack.h"
#include <string>
using namespace std;

bool isOpenBracket(char);
bool isCloseBracket(char);
bool isValidBracket(string);

int main()
{
	string str;
	cout << "Enter any Expression: ";
	getline(cin, str);

	if (isValidBracket(str))
		cout << "Valid Brackets found\n";
	else
		cout << "Invalid Brackets Used\n";
	return 0;
}

bool isOpenBracket(char ch) {
	switch (ch) {
	case '(':
	case '{':
	case '[':
		return 1;
	default:
		return 0;
	}
}

bool isCloseBracket(char ch) {
	switch (ch) {
	case ')':
	case '}':
	case ']':
		return 1;
	default:
		return 0;
	}
}

bool isValidBracket(string str) {
	int index = 0;
	char currChar;
	Stack<char> stack;
	while (currChar = str[index]) {
		if (isOpenBracket(currChar))
			stack.push(currChar);
		else if (isCloseBracket(currChar)) {
			switch (currChar) {
			case ')':
				if (stack.isEmpty() || stack.stackTop() != '(')
					return false;
				stack.pop();
				break;
			case '}':
				if (stack.isEmpty() || stack.stackTop() != '{')
					return false;
				stack.pop();
				break;
			case ']':
				if (stack.isEmpty() || stack.stackTop() != '[')
					return false;
				stack.pop();
				break;
			}
		}
		index++;
	}
	return stack.isEmpty();
}
