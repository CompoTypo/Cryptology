#ifndef CEASERCIPHER_H
#define CEASERCIPHER_H

#include <iostream>
#include <fstream>

class CeaserCipher {
    private:
        std::string output;
    public:
        std::string encode(std::string unciphered) {
            output = "";
            for(int i = 0; i < unciphered.length(); i++) {
                char c = unciphered[i];
                output += (c + 3);
            }
            return output;
        }

        std::string decode(std::string ciphered) {
            output = "";
            for(int i = 0; i < ciphered.length(); i++) {
                char c = ciphered[i];
                output += (c - 3);
            }
            return output;
        }
};
#endif