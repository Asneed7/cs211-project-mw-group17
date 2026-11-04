#include <iostream>
#include <string>
#include "luhn.h"

using namespace std;

int main()
{
    string number;

    cout << "Welcome to the Luhn Validation Prpgram!\n";

    while (true) 
    {
        cout << "\nEnter a 16-digit number";
        cout << " (or Q to quit): ";

        if (!getline(cin, number))
        {
            cout << "Goodbye!\n";
            break;
        }

        if (number == "Q" || number == "q")
        {
            cout << "Goodbye!\n";
            break;
        }
        if (!validInput(number))
        {
            cout << "Invalid input! Please enter "
                 << "exactly 16 digits (0-9).\n";
            continue;
        }

        if (checkLuhn(number))
        {
            cout << "Luhn checksum PASSES!\n";
        }
else
{
    cout << "Luhn checksum FAILS!\n";
}  // Closes else        
}  // Closes the while loop

return 0;

}  // Close main()