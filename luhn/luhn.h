#ifndef LUHN_H
#define LUHN_H

#include <string>

bool validInput(const std::string& number);
bool checkLuhn(const std::string& number);
#endif