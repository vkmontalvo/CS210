/* Author: Valerie Montalvo
Date: 1/22/23
CS210
Project 1: ChadaTech Clocks*/

#include "Clocks.h" // Include header file with functions

int main() {

	// Variable declarations
	int hour = 12;
	int min = 0;
	int sec = 0;
	int maxChoice = 5;
	int userChoice = 0;
	int menuWidth = 27;

	// While the user doesn't choose to exit the program
	while (userChoice != 4) {

		displayClocks(hour, min, sec); // Display both 12 and 24-hour clocks.
		printMenu(menuWidth); // Print the user menu
		userChoice = getMenuChoice(maxChoice); // Get the user's choice

		// Switch depending on user's choice
		switch (userChoice) {

		// User chooses to add one hour
		case 1:
			hour += 1; // Add one to the hour
			system("CLS"); // Clear the screen
			break; // Exit the switch statement

		// User chooses to add one minute

		case 2:
			min += 1; // Add one to the minute
			system("CLS"); // Clear the screen
			break; // Exit the switch statement

		// User chooses to add one second
		case 3:
			sec += 1; // Add one to the seconds
			system("CLS"); // Clear the screen
			break; // Exit the switch statement

		// User chooses to exit the program
		case 4:
			cout << "Exiting program..." << endl; // Output goodbye
			break; // Exit the switch statement

		// User chooses invalid selection
		default:
			system("CLS"); // Clear the screen
			cout << "ERROR: Invalid selection. Please make a selection from the menu." << endl << endl; // Output error message
			break; // Exit the switch statement
		}
	}
}