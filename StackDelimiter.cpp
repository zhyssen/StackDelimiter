// This program checks a string to see if it is properly delimited with corresponding
// opening and closing parentheses or brackets. The string of characters is read into 
// a stack, then the stack is checked for proper delimination with parentheses.

#include <iostream>
#include <string>
#include <stack>
using namespace std;

// Function to check if properly delimited
void checkDelimiter(string value)
{
	stack <char> charStack;

	for (int x = 0; x < value.length(); x++)
	{
		// Store opening parentheses into stack
		if (value[x] == '(' || value[x] == '[' || value[x] == '{')
		{
			charStack.push(value[x]);
		}
		else if (value[x] == ')' || value[x] == ']' || value[x] == '}')
		{
			// Look for closing parentheses and check for match with opening parentheses
			if (charStack.empty())
			{
				cout << "The string is not properly delimited." << endl;
				return;
			}

			if (value[x] == ')' && charStack.top() == '(')
			{
				charStack.pop();
			}
			else if (value[x] == ']' && charStack.top() == '[')
			{
				charStack.pop();
			}
			else if (value[x] == '}' && charStack.top() == '{')
			{
				charStack.pop();
			}
			else
			{
				cout << "The string is not properly delimited." << endl;
				return;
			}
		}
	}

	// Output results
	if (charStack.empty())
	{
		cout << "The string is properly delimited." << endl;
	}
	else
	{
		cout << "The string is not properly delimited." << endl;
	}
}

int main()
{
	// Variable
	string value;

	// Get user input
	cout << "Enter a string of characters or words with or without parentheses: \n";
	cout << "(Parenetheses can include (), {}, or [].)\n";
	getline(cin, value);

	// Call the checkDelimiter function
	checkDelimiter(value);

	return 0;
}