#include <iostream>
/*
using namespace std;

int main()
{
    char letter;
    int digit, num;
    int counter = 0;

    cout << "Enter a telephone number expressed in alphabetical characters to get the numerical value's or press # to exit." << endl;
    cin >> letter;
    cout << endl;

    while (cin && counter < 7) // Loop while the input stream continues and the counter is less than 7.
    {
        num = static_cast<int>(letter) - static_cast<int>('A');
        if (num >= 0 && num < 26)
        {
            digit = (num / 3) + 2;

            if (((num / 3 == 6) || (num / 3 == 7)) && (num % 3 == 0))
            {
                digit = digit - 1;
            }
            if (digit > 9)
            {
                digit = 9;
            }
            cout << digit;
            counter++;
            if (counter == 3)
            {
                cout << '-';
            }
            if (counter == 7) // If the counter is 7, clear the input buffer, output a new line character and reset the counter to 0 then continue looping.
            {
                cin.clear();
                cin.ignore(200, '\n');
                cout << endl;
                counter = 0;
            }
        }
        else if (num >= 32 && num < 58) // Same as above but adjusted for lowercase characters.
        {
            num = num - 32;

            digit = (num / 3) + 2;

            if (((num / 3 == 6) || (num / 3 == 7)) && (num % 3 == 0))
            {
                digit = digit - 1;
            }
            if (digit > 9)
            {
                digit = 9;
            }
            cout << digit;
            counter++;
            if (counter == 3)
            {
                cout << '-';
            }
            if (counter == 7)
            {
                cin.clear();
                cin.ignore(200, '\n');
                cout << endl;
                counter = 0;
            }
        }
        else if (letter == '#')
        {
            cout << "Exiting...";
            return 0;
        }
        else    // If the character entered is not a letter or a number, output an error message.
        {
            cout << "Try again.\n"; 
            cin.clear();
            cin.ignore(200, '\n');
            cout << endl;
            counter = 0;

        }
        cin >> letter;
    }
    return 0;

}
*/