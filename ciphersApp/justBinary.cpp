#include <iostream>
#include <string>
#include "./ciphers/binaryCipher.h"

using namespace std;

int main() {
    BinaryCipher bin = BinaryCipher();

    string input = "01110111 01101000 01101111 00100000 01110111 01101000 01100001 01110100 00100000 01110111 01101000 01100101 01110010 01100101 00100000 01110111 01101000 01100101 01101110 00100000 01110111 01101000 01111001";

    string output = bin.binToString(input);

    cout << output << endl;
}