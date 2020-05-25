#ifndef AFFINECIPHER_H
#define AFFINECIPHER_H

#include <string>
#include <iostream>

class AffineCipher {
    private:
        // a and b must be coprime
        static const int a = 5;
        static const int b = 8;
    public:
        std::string encode(std::string input) {
            std::string output = "";
            for(int i = 0; i < input.length(); i++) {
                if (input[i] != ' ') {
                    if (input[i] > 64 && input[i] < 91) { // capital letters
                        output += (char)((((a * (input[i]-'A') ) + b) % 26) + 'A');
                    } else if (input[i] > 96 && input[i] < 123) { // lower case letters
                        output += (char)((((a * (input[i]-'a') ) + b) % 26) + 'a');
                    } else {
                        output += input[i];
                    }
                } else {
                    output += input[i];
                } 
            }
            return output;
        }

        std::string decode(std::string input) {
            std::string output = "";
            int aInverse = 0;
            for(int i = 0; i < 26; i++) {
                if ((a * i) % 26 == 1) {
                    aInverse = i;
                }
            }
            for(int i = 0; i < input.length(); i++) {
                if (input[i] != ' ') {
                    if (input[i] > 64 && input[i] < 91) { // capital letters
                        output += (char) (aInverse * (26 + input[i] - 'A' - b) % 26 + 'A'); 
                    } else if (input[i] > 96 && input[i] < 123) { // lower case letters
                        output += (char) (aInverse * (26 + input[i] - 'a' - b) % 26 + 'a'); 
                    }
                } else {
                    output += input[i];
                }
            }
            return output;
        }
};
#endif