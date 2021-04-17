
//void main()
//{
//	cout << "Start 1 \n";
//	Py_Initialize();
//	cout << "2\n";
//	PyObject* my_module = PyImport_ImportModule("myfirstprogram");
//	cerr << my_module << "\n";
//	PyErr_Print();
//	cout << "3\n";
//	PyObject* my_function = PyObject_GetAttrString(my_module, "printsomething");
//	cout << "4\n";
//	PyObject* my_result = PyObject_CallObject(my_function, NULL);
//	Py_Finalize();
//}

#include <Python.h>
#include <iostream>
#include <Windows.h>
#include <cmath>
#include <string>
#include <vector>

using namespace std;

/*
Description:
	To call this function, simply pass the function name in Python that you wish to call.
Example:
	callProcedure("printsomething");
Output:
	Python will print on the screen: Hello from python!
Return:
	None
*/
void CallProcedure(string pName)
{
	char* procname = new char[pName.length() + 1];
	std::strcpy(procname, pName.c_str());

	Py_Initialize();
	PyObject* my_module = PyImport_ImportModule("PythonCode");
	PyErr_Print();
	PyObject* my_function = PyObject_GetAttrString(my_module, procname);
	PyObject* my_result = PyObject_CallObject(my_function, NULL);
	Py_Finalize();

	delete[] procname;
}

/*
Description:
	To call this function, pass the name of the Python functino you wish to call and the string parameter you want to send
Example:
	int x = callIntFunc("PrintMe","Test");
Output:
	Python will print on the screen:
		You sent me: Test
Return:
	100 is returned to the C++
*/
int callIntFunc(string proc, string param)
{
	char* procname = new char[proc.length() + 1];
	std::strcpy(procname, proc.c_str());

	char* paramval = new char[param.length() + 1];
	std::strcpy(paramval, param.c_str());


	PyObject* pName, * pModule, * pDict, * pFunc, * pValue = nullptr, * presult = nullptr;
	// Initialize the Python Interpreter
	Py_Initialize();
	// Build the name object
	pName = PyUnicode_FromString((char*)"PythonCode");
	// Load the module object
	pModule = PyImport_Import(pName);
	// pDict is a borrowed reference 
	pDict = PyModule_GetDict(pModule);
	// pFunc is also a borrowed reference 
	pFunc = PyDict_GetItemString(pDict, procname);
	if (PyCallable_Check(pFunc))
	{
		pValue = Py_BuildValue("(z)", paramval);
		PyErr_Print();
		presult = PyObject_CallObject(pFunc, pValue);
		PyErr_Print();
	}
	else
	{
		PyErr_Print();
	}
	//printf("Result is %d\n", _PyLong_AsInt(presult));
	Py_DECREF(pValue);
	// Clean up
	Py_DECREF(pModule);
	Py_DECREF(pName);
	// Finish the Python Interpreter
	Py_Finalize();

	// clean 
	delete[] procname;
	delete[] paramval;


	return _PyLong_AsInt(presult);
}

/*
Description:
	To call this function, pass the name of the Python functino you wish to call and the string parameter you want to send
Example:
	int x = callIntFunc("doublevalue",5);
Return:
	25 is returned to the C++
*/
int callIntFunc(string proc, int param)
{
	char* procname = new char[proc.length() + 1];
	std::strcpy(procname, proc.c_str());

	PyObject* pName, * pModule, * pDict, * pFunc, * pValue = nullptr, * presult = nullptr;
	// Initialize the Python Interpreter
	Py_Initialize();
	// Build the name object
	pName = PyUnicode_FromString((char*)"PythonCode");
	// Load the module object
	pModule = PyImport_Import(pName);
	// pDict is a borrowed reference 
	pDict = PyModule_GetDict(pModule);
	// pFunc is also a borrowed reference 
	pFunc = PyDict_GetItemString(pDict, procname);
	if (PyCallable_Check(pFunc))
	{
		pValue = Py_BuildValue("(i)", param);
		PyErr_Print();
		presult = PyObject_CallObject(pFunc, pValue);
		PyErr_Print();
	}
	else
	{
		PyErr_Print();
	}
	//printf("Result is %d\n", _PyLong_AsInt(presult));
	Py_DECREF(pValue);
	// Clean up
	Py_DECREF(pModule);
	Py_DECREF(pName);
	// Finish the Python Interpreter
	Py_Finalize();

	// clean 
	delete[] procname;

	return _PyLong_AsInt(presult);
}


bool isValid(int option) {
	/* added this method to easily check if the user input is a valid menu option */

	vector<int> validOptions = { 1,2,3 };	// valid menu options
	for (int item : validOptions) {
		if (item == option) {
			return true;
		}
	}
	cout << "\nNot an option!! Try again\n" << endl;
	return false;
}


void menu() {
	/* method for the menu */
	bool keepRunning = true;	// keeps the loop going while true
	while (keepRunning) {
		// menu loop
		cout << "1: Display a Multiplication Table" << endl;
		cout << "2. Double a Value" << endl;
		cout << "3. Exit" << endl;
		cout << "Enter your selection as a number 1, 2, 3" << endl;
		int option;
		cin >> option;

		int num;
		try {
			if (isValid(option)) {
				switch (option) {
					// went with a switch statement here to better align with a menu
				case 1:
					// executes the MultiplicationTable function in python
					cout << "Enter the number you'd like a table for: " << endl;
					cin >> num;
					cout << callIntFunc("MultiplicationTable", num) << endl;
					cout << endl;
					system("pause");
					break;
				case 2:
					// executes the DoubleValue function in python
					cout << "Enter the number you'd like to double: " << endl;
					cin >> num;
					cout << callIntFunc("DoubleValue", num) << endl;
					cout << endl;
					system("pause");
					break;
				case 3:
					// by setting keepRunning to false, the loop ends
					keepRunning = false;
					cout << "Thanks for playing!" << endl;
					break;
				default:
					break;
				}
			}

		}
		catch (const std::exception& exc) {
			cout << exc.what() << endl;
			cout << "Wrong option" << endl;
		}

		cout << endl;
	}
}

void main()
/* controller method */
{
	try
	{
		menu();
	}
	catch (const std::exception& exc)
	{
		cout << exc.what() << endl;
		cout << "Error occurred";
		system("pause");
	}
	
}
