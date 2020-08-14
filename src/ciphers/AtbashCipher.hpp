#ifndef ATBASHCIPHER_H
#define ATBASHCIPHER_H

#include <iostream>

using namespace std;

class AtbashCipher
{
public:
    static string flipValues(string plainTextInput)
    {
        string output = "";
        for (int i = 0; i < plainTextInput.length(); ++i)
        {
            char c = plainTextInput[i];
            if (c > 64 && c < 91)
            { // capital letters
                c = 90 - (c - 65);
                output += c;
            }
            else if (c > 96 && c < 123)
            { // lower case letters
                c = 122 - (c - 97);
                output += c;
            }
            else
            {
                output += c;
            }
        }
        return output;
    }
};
#endif