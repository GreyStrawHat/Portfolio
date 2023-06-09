#include <iostream>
#include <iomanip>
#include <string>
#include <sstream> // including this library to create a stringstream object for the time conversion functions.
/*
using namespace std;

//First I'll define some function prototypes.

string convertTo12hour(int hour, int minute);
string convertTo24hour(int hour, int minute, string meridian);
void displayChoices();
void getTimeInput(int& hour, int& minute, string& meridian);
void displayResult(string time);

int main() { // Use a do..while loop to rotate through different options until user exits.
    int choice;
    int hour, minute;
    string meridian;

    do {
        displayChoices();
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            getTimeInput(hour, minute, meridian);
            displayResult(convertTo12hour(hour, minute));
            break;
        case 2:
            getTimeInput(hour, minute, meridian);
            displayResult(convertTo24hour(hour, minute, meridian));
            break;
        case 3:
            cout << "Exiting program.\n";
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
            break;
        }

        cout << endl;
    } while (choice != 3);

    return 0;
}

//Next I'll create some functions to convert time from 12 and 24 hour notation and vice versa with AM and PM appended to teh resulting values.

string convertTo12hour(int hour, int minute) {
    string meridian = "AM";
    if (hour >= 12) {
        meridian = "PM";
        if (hour > 12)
            hour = hour - 12;
    }
    stringstream time;  // Using stringstream to concatenate the different data types easily.
    time << setw(2) << setfill('0') << hour << ":" << setw(2) << setfill('0') << minute << " " << meridian;
    return time.str();
}

string convertTo24hour(int hour, int minute, string meridian) {
    if (meridian == "PM" && hour < 12) {
        hour += 12;
    }
    else if (meridian == "AM" && hour == 12) {
        hour = 0;
    }
    stringstream time;
    time << setw(2) << setfill('0') << hour << ":" << setw(2) << setfill('0') << minute;
    return time.str();
}

// Next a function for displaying a menu

void displayChoices() {
    cout << "Select an option from the following menu:" << endl;
    cout << "1. Convert time from 24-hour notation to 12-hour notation" << endl;
    cout << "2. Convert time from 12-hour notation to 24-hour notation" << endl;
    cout << "3. Exit" << endl;
}

// A function for receiving time through user input.
//using the reference operator '&' so any values assigned to the variables are passed to teh main function as well.

void getTimeInput(int& hour, int& minute, string& meridian) {
    cout << "Enter the hour (0-23): " << endl;
    cin >> hour;
    cout << "Enter the minute (0-59): " << endl;
    cin >> minute;
    cout << "AM or PM? " << endl;
    cin >> meridian;
}

//Display results
void displayResult(string time) {
    cout << "Converted time: " << time << endl;
}
*/