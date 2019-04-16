#include <iostream>
#include <vector>
#include <string>

#include "./ciphers/affineCipher.h"
#include "./ciphers/atbashCipher.h"
#include "./ciphers/ceaserCipher.h"
#include "./ciphers/binaryCipher.h"
#include "./ciphers/vigenereCipher.h"

using namespace std;

int main() {
    string ciphers[] = {"affine", "atbash", "ceaser", "viginere"};
    int chosenCipher = 0;
    int encodeOrDecode = 0;
    string input = "";
    string output = "";

    cout << "Choose a cipher" << endl;
    for(int i = 0; i < sizeof(ciphers) / sizeof(*ciphers); i++) {
        cout << i + 1 << ") " << ciphers[i] << endl;
    }
    cout << "Enter # associated with ciphered: ";
    cin >> chosenCipher;
    cout << "Enter text to encode: ";
    cin >> input;

    while (chosenCipher == 0 || input == "") {
        if (chosenCipher == 0) {
            cout << "CHOOSE A VALID # CORRESPONDING TO A CIPHER" << endl;
        }
        if (input == "") {
            cout << "ENTER A PROPER TEXT INPUT" << endl;
        }
        
        cout << "Choose a cipher" << endl;
        for(int i = 0; i < sizeof(ciphers) / sizeof(*ciphers); i++) {
            cout << i + 1 << ") " << ciphers[i] << endl;
        }
        cout << "Enter # associated with ciphered: ";
        cin >> chosenCipher;
        cout << "Enter text to encode: ";
        cin >> input;
    }

    while(chosenCipher != 2 || encodeOrDecode != 1 || encodeOrDecode != 2){
        cout << "Encode message or decode? (1: encode, 2: decode): ";
        cin >> encodeOrDecode;
    }
    
    
    switch (chosenCipher) {
        case 1: {
            AffineCipher affine = AffineCipher();
            if (encodeOrDecode == 1) {
                output = affine.encode(input);
            } else if (encodeOrDecode == 2) {
                output = affine.decode(input);
            }
            break;
        } case 2: {
            AtbashCipher atbash = AtbashCipher();
            output = atbash.flipValues(input);
            break;
        } case 3: {
            CeaserCipher ceaser = CeaserCipher();
            if (encodeOrDecode == 1) {
                output = ceaser.encode(input);
            } else if (encodeOrDecode == 2) {
                output = ceaser.decode(input);
            }            
            break;
        } case 4: {
            VigenereCipher vigenere = VigenereCipher();
            string key = "";
            cout << "Enter a key for vigenere: ";
            cin >> key;
            while(key == "") {
                cout << "Enter a key for vigenere: ";
                cin >> key;
            }
            
            break;    
        } default: {
            break;
        }
    }
}