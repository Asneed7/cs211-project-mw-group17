#include "luhn.h"

// Checks that the input contains exactly 16 digits
bool validInput(const std::string& number)
{
    if (number.length() != 16)
    {
        return false;
    }
    for (char digit : number)
    {
        if (digit < '0' || digit > '9')
        {
            return false;
        }

        }
    
    return true;
}

// cheks whether the number passes the luhn algorithm
bool checkLuhn(const std::string& number)
{
    int sum = 0;
    bool doubleDigit = false;

    for (int i = 15; i >= 0; i--) {
        int digit = number[i] - '0';
        if (doubleDigit) {
            digit = digit *2;

            if (digit > 9) {
                digit = digit -9;
            }
        }
        sum += digit;
        doubleDigit = !doubleDigit;
    }
    return sum % 10 == 0;
}