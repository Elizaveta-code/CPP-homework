#include <iostream>
#include <string>
#include <cctype>

void countLetters(const std::string& str, int& numLetters, int& numDigits)
{
    numLetters = 0;
    numDigits = 0;
    
    for (char c : str) {
        if (std::isalpha(c)) {
            numLetters++;
        } else if (std::isdigit(c)) {
            numDigits++;
        }
    }
}

int main()
{
    std::string test = "Hello123World45";
    
    int letters, digits;
    
    countLetters(test, letters, digits);
    std::cout << "letters: " << letters << ", digits: " << digits << std::endl;
}