#include <iostream>
#include <vector>
#include <string>

#include "./ciphers/AffineCipher.hpp"
#include "./ciphers/AtbashCipher.hpp"
#include "./ciphers/CeaserCipher.hpp"
#include "./ciphers/BinaryCipher.hpp"
#include "./ciphers/VigenereCipher.hpp"

int main()
{
    std::string ciphers[] = {"affine", "atbash", "ceaser", "viginere"};
    int chosenCipher = 0;
    int encodeOrDecode = 0;
    std::string input = "";
    std::string output = "";

    std::cout << "Choose a cipher" << std::endl;
    for (int i = 0; i < sizeof(ciphers) / sizeof(*ciphers); i++)
    {
        std::cout << i + 1 << ") " << ciphers[i] << std::endl;
    }
    std::cout << "Enter # associated with ciphered: ";
    std::cin >> chosenCipher;
    std::cout << "Enter text to encode: ";
    std::cin >> input;

    while (chosenCipher == 0 || input == "")
    {
        if (chosenCipher == 0)
            cout << "CHOOSE A VALID # CORRESPONDING TO A CIPHER" << endl;
        if (input == "")
            cout << "ENTER A PROPER TEXT INPUT" << endl;

        cout << "Choose a cipher" << endl;
        for (int i = 0; i < sizeof(ciphers) / sizeof(*ciphers); i++)
            cout << i + 1 << ") " << ciphers[i] << endl;

        cout << "Enter # associated with ciphered: ";
        cin >> chosenCipher;
        cout << "Enter text to encode: ";
        cin >> input;
    }

    while (chosenCipher != 2 && (encodeOrDecode != 1 && encodeOrDecode != 2))
    {
        cout << "Encode message or decode? (1: encode, 2: decode): ";
        cin >> encodeOrDecode;
    }

    switch (chosenCipher)
    {
    case 1:
    {
        AffineCipher affine = AffineCipher();
        if (encodeOrDecode == 1)
            output = affine.encode(input);
        else if (encodeOrDecode == 2)
            output = affine.decode(input);
        break;
    }
    case 2:
    {
        output = AtbashCipher::flipValues(input);
        break;
    }
    case 3:
    {
        if (encodeOrDecode == 1)
            output = CeaserCipher::encode(input);
        else if (encodeOrDecode == 2)
            output = CeaserCipher::decode(input);
        break;
    }
    case 4:
    {
        VigenereCipher vigenere = VigenereCipher();
        string key = "";
        std::cout << "Enter a key for vigenere: ";
        std::cin >> key;
        while (key == "")
        {
            std::cout << "Enter a key for vigenere: ";
            std::cin >> key;
        }

        break;
    }
    default:
    {
        break;
    }
    };
    std::cout << "Translation: " << output << std::endl;
}