/*
* Project 3: The Corner Grocer - Text Records
* Chada Tech
* 
* Developer: Chris Tapia
* Last Updated: 04/18/21
* Utilizes PythonCode.py 
*/

#include <Python.h>
#include <iostream>
#include <Windows.h>
#include <cmath>
#include <string>
#include <vector>
#include <fstream>
#include <iomanip>

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

	vector<int> validOptions = { 1,2,3,4 };	// valid menu options
	for (int item : validOptions) {
		if (item == option) {
			return true;
		}
	}
	cout << "\nNot an option!! Try again\n" << endl;
	return false;
}

void ViewDataAndHistogram() {
	/* this opens the new dat file to display the data and generate a text-based histogram */

	// vars for opening the file
	ifstream inFS;
	string fileWord;
	int fileNum;
	string item_name;
	int item_frequency;
	vector<string> item_list;
	vector<int> frequencyList;

	string title = "---Text-Based Histogram---";
	int titleWidth = title.length();

	inFS.open("frequency.dat");
	if (!inFS.is_open()) {
		cout << "Unable to open the file" << endl;
	}
	inFS >> item_name;
	inFS >> item_frequency;
	while (!inFS.fail()) {
		// pulls data from file and adds them to separate vectors
		item_list.push_back(item_name);
		frequencyList.push_back(item_frequency);

		inFS >> item_name;
		inFS >> item_frequency;
	}
	for (int i = 0; i < item_list.size(); i++) {
		cout << item_list.at(i) << " " << frequencyList.at(i) << endl;
	}

	// text-based histogram
	int frequencyWidth;

	cout << endl;
	cout << "---Text-Based Histogram---" << endl;
	cout << endl;

	
	for (int i = 0; i < item_list.size(); i++) {
		frequencyWidth = frequencyList.at(i) + 1;
		cout << item_list.at(i) << " ";
		cout << setfill('*') << setw(frequencyWidth) << " " << endl;
	}

	if (!inFS.eof()) {
		cout << "Input failure before reaching the end of the file" << endl;
	}
	cout << "closing frequency.dat file..." << endl;

	inFS.close();
}

void menu() {
	/* method for the menu */
	bool keepRunning = true;	// keeps the loop going while true
	while (keepRunning) {
		// menu loop

		
		cout << "1: List of all items purchased and how many times each was purchased" << endl;
		cout << "2. Select an item to view how many times it was purchased" << endl;
		cout << "3. Generate a a file and a text-based histogram displaying each item and how many times it was purchased" << endl;
		cout << "4. Exit" << endl;
		cout << "Enter your selection as a number (1, 2, 3, or 4)" << endl;
		int option;
		cin >> option;
		string item;	
		
		try {
			if (isValid(option)) {
				switch (option) {
					// went with a switch statement here to better align with a menu
				case 1:
					// executes the MultiplicationTable function in python
					cout << "Opening file..." << endl;
					Sleep(1000);
					cout << "Here's everything that was sold and how many times:" << endl;
					CallProcedure("ViewItems");
					cout << endl;
					system("pause");
					break;
				case 2:
					// executes the specificItemCount function in python

					cout << "Enter a grocery item to view how often it was purchased: " << endl;
					cin >> item;
					cout << endl;
					cout << "Opening file..." << endl;
					Sleep(1000);
					cout << callIntFunc("SpecificItemCount", item) << endl;
					cout << endl;
					system("pause");
					break;
				case 3:
					// executes the GenerateFile function in python and the ViewDataAndHistogram method in cpp
					cout << "Generating a new file and histogram... " << endl;
					Sleep(2000);
					CallProcedure("GenerateFileAndGraph");
					cout << endl;
					cout << "Opening frequency.dat file..." << endl << endl;
					Sleep(1000);
					ViewDataAndHistogram();

					system("pause");
					break;
				case 4:
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
/* main controller method */
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