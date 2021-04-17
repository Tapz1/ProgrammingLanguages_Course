/*
 * Project Two: Working With Files
 *
 *	Date: 04/02/21
 *  Author: Chris Tapia
 *	CS210
 *
 */


#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <iomanip>
#include <string>
#include <vector>
using namespace std;


void fahrenheitToCelsius(int &temp) {
	/* converts from fahrenheit to celsius*/

	temp = ((double)temp - 32.0) * (0.5556);
}

int main(){
	ifstream inFS;
	ofstream outFS; 
	string fileWord;
	int fileNum;
	vector<string> citiesVect;
	vector<int> tempsVect;


	//opening file
	cout << "Opening file: FahrenheitTemperature.txt" << endl;
	inFS.open("FahrenheitTemperature.txt");
	if (!inFS.is_open()) {
		cout << "Unable to open the file" << endl;
		return 1;
	}

	// reading
	cout << "Here's are the temps from your current file: " << endl;
	inFS >> fileWord;
	inFS >> fileNum;
	while (!inFS.fail()) {
		citiesVect.push_back(fileWord);
		tempsVect.push_back(fileNum);
		
		inFS >> fileWord;
		inFS >> fileNum;

	}
	
	for (int i = 0; i < citiesVect.size(); i++) {
		cout << citiesVect.at(i) << " " << tempsVect.at(i) << endl;
	}
	
	if (!inFS.eof()) {
		cout << "Input failure before reaching the end of the file" << endl;
	}
	cout << "closing FahrenheitTemperature.txt..." << endl;
	
	inFS.close();

	system("pause");

	// writing to file
	cout << "Opening file: CelsiusTemperature.txt" << endl;
	outFS.open("CelsiusTemperature.txt");
	if (!outFS.is_open()) {
		cout << "Could not open the new file, 'CelsiusTemperature.txt'" << endl;
		return 1;
	}
	
	cout << endl;
	cout << "Here's your new file with the temps converted to Celsius: " << endl;
	
	for (int i = 0; i < citiesVect.size(); i++) {
		fahrenheitToCelsius(tempsVect.at(i));
		//cout << citiesVect.at(i) << " " << tempsVect.at(i) << endl;
		outFS << citiesVect.at(i) << " " << tempsVect.at(i) << endl;
		cout << citiesVect.at(i) << " " << tempsVect.at(i) << endl;
			
	}

	cout << "closing CelsiusTemperature.txt..." << endl;

	outFS.close();
		

	return 0;
}