#include <iostream>
#include <cstdlib>
#include <cmath>
/*
using namespace std;

int randnum() {
    return rand() % 100;
}

int doublenumber(int number) {
    return number * 2;
}

int reversedigits(int number) {
    int reversedNumber = 0;
    while (number > 0) {
        int digit = number % 10;
        reversedNumber = reversedNumber * 10 + digit;
        number /= 10;
    }
    return reversedNumber;
}

int raisepower(int number, int power) {
    if (power == 2) {
        return pow(number, power);
    }
    else if (power == 3) {
        return pow(number, power);
    }
    else if (power == 4) {
        return pow(number, power);
    }
    else {
        cout << "You did not select a power of 2, 3, or 4. Try Again." << endl;
        return 0;
    }
}

int sumdigits(int number) {
    int sum = 0;
    while (number > 0) {
        sum += number % 10;
        number /= 10;
    }
    return sum;
}

int twodigitpowerRaise(int number) {
    int firstDigit = number / 10;
    int secondDigit = number % 10;
    return pow(firstDigit, secondDigit);
}

int threedigitpowerRaise(int number) {
    int firstDigit = number / 100;
    int secondDigit = (number / 10) % 10;
    int lastDigit = number % 10;

    if (lastDigit <= 4) {
        return pow(firstDigit * 10 + secondDigit, lastDigit);
    }

    return number;
}

bool isPrime(int number) {
    if (number < 2)
        return false;
    for (int i = 2; i <= sqrt(number); i++) {
        if (number % i == 0)
            return false;
    }
    return true;
}

int main() {
    srand(time(NULL));
    int number = randnum();
    int choice;
    cout << "Randonly Generated Number: " << number << endl;
    cout << "Select Option: " << endl;
    cout << "1. Double the number" << endl;
    cout << "2. Reverse the digits of the number" << endl;
    cout << "3. Raise the number to a power" << endl;
    cout << "4. Sum the digits of the number" << endl;
    cout << "5. Raise the first digit to the power of the second digit" << endl;
    cout << "6. Raise the first two digits to the power of the last digit" << endl;
    cout << "0. Exit" << endl;
    cout << "Enter your choice: " << endl;
    cin >> choice;

    switch (choice) {
    case 1:
        number = doublenumber(number);
        cout << "[+] Printing value...\t" << number << endl;
        break;
    case 2:
        number = reversedigits(number);
        cout << "[+] Printing value...\t" << number << endl;
        break;
    case 3:
        int power;
        cout << "Enter the power (2, 3, or 4): ";
        cin >> power;
        number = raisepower(number, power);
        cout << "[+] Printing value...\t" << number << endl;
        break;
    case 4:
        number = sumdigits(number);
        cout << "[+] Printing value...\t" << number << endl;
        break;
    case 5:
        number = twodigitpowerRaise(number);
        cout << "[+] Printing value...\t" << number << endl;
        break;
    case 6:
        number = threedigitpowerRaise(number);
        cout << "[+] Printing value...\t" << number << endl;
        break;
    case 0:
        cout << "Exiting program.\n";
        return 0;
    }
}
*/