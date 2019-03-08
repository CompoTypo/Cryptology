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
        cipheredFile << (char)(c+3);
    }

    plainTextFile.close();
    cipheredFile.close();
    return 0;

}