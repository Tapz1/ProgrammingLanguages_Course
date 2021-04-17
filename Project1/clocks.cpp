/*
 * Project One: Chada Tech Clocks
 * 
 *	Date: 03/20/21
 *  Author: Chris Tapia
 *	CS210
 * 
 */

#include <iostream>
#include <stdlib.h>
#include <windows.h>
#include <iomanip>
#include <time.h>

using namespace std;


int menuOptions(int& hr, int& min, int& sec, bool& contRunning) {
	/*this function uses pass by reference to simultaneuously update the time variables in the clocks function*/
	cout << setfill('*') << setw(34) << '*' << endl;
	cout << "*\t" << "1 - Add One Hour" << "\t *" << endl;
	cout << "*\t" << "2 - Add One Minute" << "\t *" << endl;
	cout << "*\t" << "3 - Add One Second" << "\t *" << endl;
	cout << "*\t" << "4 - Exit Program" << "\t *" << endl;
	cout << setfill('*') << setw(34) << '*' << endl;
	int menuOption;
	cin >> menuOption;
	switch (menuOption) {
	case 1:
		return hr++;
		break;
	case 2:
		return min++;
		break;
	case 3:
		return sec++;
		break;
	case 4:
		contRunning = false;
		return 0; // requires an int to be returned, zero is insignificant
		break;
	default:
		break;
	}
}


int twelveAndTwentyFourHourClocks() {
	/* this function allows the user to reset the clock displaying up to date current time or manipulate the time */
	
	bool contRunning = true;
	
	// initial timestamp data called before 
	time_t now = time(NULL);
	struct tm timeinfo;
	localtime_s(&timeinfo, &now);
	int hr = timeinfo.tm_hour;
	int min = timeinfo.tm_min;
	int sec = timeinfo.tm_sec;

	while (contRunning == true) {
		char choice;
		
		system("cls");

		// 24 hour time clock
		cout << setfill('*') << setw(26) << '*' << endl;
		cout << "*\t" << "24-Hour Clock" << "\t *" << endl;
		cout << "*\t" << hr << " : " << min << " : " << sec << "\t *" << endl;
		cout << setfill('*') << setw(26) << '*' << endl;

		// to get regular time from military time
		if (hr > 12) {
			hr -= 12;
		}
		// regular time clock
		cout << setfill('*') << setw(26) << '*' << endl;
		cout << "*\t" << "12-Hour Clock" << "\t *" << endl;
		cout << "*\t" << hr << " : " << min << " : " << sec << "\t *" << endl;
		cout << setfill('*') << setw(26) << '*' << endl;

		// couldnt find way to continuously refresh the display to show updated time AND look for a button press
		// so user has option to refresh the time which is updated or go to the menu and temp add on time
		cout << "1 - Refresh/Reset \t 2 - Menu" << endl;;
		cin >> choice;
		if (choice == '1') {
			time_t now = time(NULL);
			struct tm timeinfo;
			localtime_s(&timeinfo, &now);
			hr = timeinfo.tm_hour;
			min = timeinfo.tm_min;
			sec = timeinfo.tm_sec;
			continue;
		}
		else {
			// displays menu switch using pass by reference
			menuOptions(hr, min, sec, contRunning);
		}
		
		//Sleep(1000); // originally had for continuously refreshing 
	}

	cout << "You have exited the program" << endl;

	return 0;
}




int main() {
	cout << "Your Time Displayed in Two Formats" << endl;

	twelveAndTwentyFourHourClocks();
	
	
	return 0;
}




