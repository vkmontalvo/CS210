/* Author: Valerie Montalvo
Date: 1/22/23
CS210
Project 1: ChadaTech Clocks*/


#ifndef CLOCKS
#define CLOCKS

#include<string>
#include<iostream>
#include<iomanip>

using namespace std;

// Convert two-digit numbers to strings to display
string twoDigitString(unsigned int n) {
	string x;

	// If n is between 0 and 9, add a 0 in front of the string, otherwise just convert to string
	if (n >= 0 && n <= 9) {
		x = to_string(n);
		x.insert(0, "0");
	}
	else {
		x = to_string(n);
	}

	// Return the converted string
	return x;
}

// Return a string of characters depending on string length
string nCharString(size_t n, char c) {
	string x;
	for (int i = 0; i < n; ++i) {
		x = x + c;
	};

	return x;
}

// Format time for 24-hour clock in string form
string formatTime24(unsigned int h, unsigned int m, unsigned int s) {
	string hrs;
	string mins;
	string secs;
	string clock24;

	hrs = twoDigitString(h);
	mins = twoDigitString(m);
	secs = twoDigitString(s);

	clock24 = hrs + ":" + mins + ":" + secs;

	return clock24;
}

// Format time for 12-hour clock in string form
string formatTime12(unsigned int h, unsigned int m, unsigned int s) {
	string hrs;
	string mins;
	string secs;
	string dayOrNight = "A M";
	string clock12;

	// If the hour is greater than or equal to 12, add P M
	if (h >= 12) {
		dayOrNight = "P M";

		// If the hour is greater than 12, minus 12 for the 12-hour clock
		if (h > 12) {
			h = h - 12;
		}
	}

	// If the hour is 0, make the hour 12 for 12 AM
	if (h == 0) {
		h = 12;
	}

	// Call the function to convert to two-digit strings for time
	hrs = twoDigitString(h);
	mins = twoDigitString(m);
	secs = twoDigitString(s);

	// Format the final 12-hour clock string
	clock12 = hrs + ":" + mins + ":" + secs + " " + dayOrNight;

	return clock12;
}

// Print the menu to the screen, depending on desired width
void printMenu(unsigned char width) {
	string menuBorder;

	menuBorder = nCharString(width, '*');
	cout << endl;
	cout << menuBorder << endl;
	cout << "* 1 - Add One Hour" << nCharString(width - 19, ' ') << "*" << endl;
	cout << "* 2 - Add One Minute" << nCharString(width - 21, ' ') << "*" << endl;
	cout << "* 3 - Add One Second" << nCharString(width - 21, ' ') << "*" << endl;
	cout << "* 4 - Exit Program" << nCharString(width - 19, ' ') << "*" << endl;
	cout << menuBorder << endl;
}

// Get user input
unsigned int getMenuChoice(unsigned int maxChoice) {
	unsigned int choice = 0;
	while (choice < 1 || choice > maxChoice) {
		cout << "Enter your choice: ";
		cin >> choice;
	}
	return choice;
}

// Display both clocks, calling to the appropriate formatting functions
void displayClocks(unsigned int h, unsigned int m, unsigned int s) {
	cout << nCharString(27, '*') << "   " << nCharString(27, '*') << endl;
	cout << "*" << nCharString(6, ' ') << "12-HOUR CLOCK" << nCharString(6, ' ') << "*   ";
	cout << "*" << nCharString(6, ' ') << "24-HOUR CLOCK" << nCharString(6, ' ') << "*" << endl;
	cout << endl;
	cout << "*" << nCharString(6, ' ') << formatTime12(h, m, s) << nCharString(7, ' ') << "*   ";
	cout << "*" << nCharString(8, ' ') << formatTime24(h, m, s) << nCharString(9, ' ') << "*" << endl;
	cout << nCharString(27, '*') << "   " << nCharString(27, '*') << endl;
}
#endif
