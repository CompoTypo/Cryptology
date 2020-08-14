#ifndef BINARYCIPHER_H
#define BINARYCIPHER_H

#include <iostream>
#include <string>
#include <cstdlib>
#include <sstream>
#include <math.h>

class BinaryCipher
{
private:
    static std::string reverse(std::string input)
    {
        std::string output = "";
        for (int i = input.length() - 1; i >= 0; i--)
        {
            output += input[i];
        }
        return output;
    }

    static std::string intToBin(int asciiVal)
    {
        std::string bin = "";
        while (asciiVal > 0)
        {
            std::stringstream ss;
            ss << asciiVal % 2;
            bin += ss.str();
            asciiVal /= 2;
        }
        //cout << bin << endl;
        return reverse(bin);
    }

public:
    static std::string stringToBin(std::string input)
    {
        std::string output = "";
        int asciiRep;
        std::string asciiString = "";
        for (int i = 0; i < input.length(); i++)
        {
            asciiRep = (int)input.c_str()[i];
            output += intToBin(asciiRep) + " ";
        }
        return output;
    }

    static std::string binToString(std::string input)
    {
        std::string output = "";
        std::string word = "";
        for (int i = 0; i <= input.length(); i++)
        {
            if (input[i] == ' ' || i == input.length())
            {
                int counter = 0;
                int asciiVal = 0;
                for (int j = word.length() - 1; j >= 0; --j)
                {
                    asciiVal += (word[j] - 48) * pow(2, counter);
                    ++counter;
                }
                output += (char)asciiVal;
                word = "";
            }
            else
            {
                word = word + input[i];
            }
        }
        return output;
    }
};
#endif