/*
 * Calculator.cpp
 *
 *  Date: 03/20/21
 *  Author: Chris Tapia
 */

#include <iostream>

using namespace std;

void main()
{
	char statement[100];
	// changed int to double data type to allow doubles and ints
	double op1, op2;
	char operation;
	// changed the parentheses around Y to single quotes because it's a char datatype, not a string.
	char answer = 'Y'; 
		
	// also changed y to Y to match the conditional statement for the while loop to work
		// added Y or y as applicable user responses to keep the program running
		while (answer == 'Y' || answer == 'y')
		{
			cout << "Enter expression" << endl;
			cin >> op2 >> operation >> op1;
		
		// fixed all if statements to have code brackets
			// fixed by changing "" to single quotes '' around + since it's a char data type
			if (operation == '+') {
				// the << after op2 was reversed, changed it
				cout << op1 << " + " << op2 << " = " << op1 + op2 << endl;
			}
			if (operation == '-') {
				// the << before op1 was reversed sinced we're outputting not inputting. Changed it
				cout << op1 << " - " << op2 << " = " << op1 - op2 << endl;
			}
			if (operation == '*') {
				// added forgotten semicolon & changed the operation here from '/' to '*' for multiplication
				cout << op1 << " * " << op2 << " = " << op1 * op2 << endl;
			}
			if (operation == '/') {
				// changed the operation here from '*' to '/' for division
				cout << op1 << " / " << op2 << " = " << op1 / op2 << endl;
			}

			cout << "Do you wish to evaluate another expression? " << endl;
			cin >> answer;
			
			// added if statement to check if answer is N or n to output message upon finishing
			if (answer == 'N' || answer == 'n') {
				cout << "Program Finished." << endl;
			}
		}
}