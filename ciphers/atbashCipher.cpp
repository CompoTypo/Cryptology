#include <iostream>
#include <fstream>

using namespace std;

int main() {

    ofstream cipheredFile;
    cipheredFile.open("cipered.txt");

    ifstream plainTextFile; 
    plainTextFile.open("loremIpsum.txt");

    while (!plainTextFile.eof()) {
        char c = plainTextFile.get();
        if (c > 64 && c < 91) { // capital letters
            c = 90 - (c - 65);
            cout << c << endl;
            cipheredFile << c;
        }

        if (c > 96 && c < 123) { // lower case letters
            c = 122 - (c - 97);
            cout << c << endl;
            cipheredFile << c;
        }
    }

    plainTextFile.close();
    cipheredFile.close();
    return 0;

}