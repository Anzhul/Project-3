/*
 * ciphers.cpp
 * Project UID e98fd45ccce9d7195e89e6171a5451f2
 *
 * Songhan Wu
 * wuumaa
 *
 * EECS 183: Project 3
 * Fall 2023
 *
 * <#description#>
 */

#include "utility.h"
#include "caesar.h"
#include "vigenere.h"
#include "polybius.h"
#include <iostream>
#include <string>

using namespace std;

//string caesarCipher(string original, int key, bool encrypt);
//string vigenereCipher(string original, string keyword, bool encrypt);
//string polybiusSquare(char grid[SIZE][SIZE], string key, string original, bool encrypt);

string Input1;
string Input2;
string original;
string key;
char grid[SIZE][SIZE];

string toLowerCase(string original) {
    for (int i = 0; i < original.length(); i++) {
        if (original[i] >= 'A' && original[i] <= 'Z') {
            original[i] = (original[i] - 'A') + 'a';
        }
    }
    return original;
}

bool isallNum(string original) {
    for (int i = 0; i < original.length(); i++) {
        if (!isalpha(original[i]) && !isdigit(original[i])) {
            break;
            return false;
        }
    }
    return true;
}

int stringToint(string original_key) {
    int newInt = 0;
    for (int i = 0; i < original_key.length(); i++) {
        newInt += charToInt(original_key[i]);
    }
    return newInt;
}

void ciphers() {
    cout << "Choose a cipher (Caesar, Vigenere, or Polybius): ";
    cin >> Input1;
    Input1 = toLowerCase(Input1);
    cout << "Encrypt or decrypt: ";
    cin >> Input2;
    Input2 = toLowerCase(Input2);
    cout << "Enter a message: ";
    cin >> original;
    cout << "What is your key: ";
    cin >> key;

    if (Input1 == "caesar" || Input1 == "c") {
        int temp_key = stringToint(key);
        if (Input2 == "encrypt" || Input2 == "e") {
            cout << caesarCipher(original, temp_key, true);
        }
        else if (Input2 == "decrypt" || Input2 == "d") {
            cout << caesarCipher(original, temp_key, false);
        }
        else {
            cout << "Invalid mode!";
        }
    }
    else if (Input1 == "vigenere" || Input1 == "v") {
        string temp_key = removeNonAlphas(key);
        if (temp_key == "") {
            cout << "Invalid key!";
        }
        else {
            if (Input2 == "encrypt" || Input2 == "e") {
                cout << vigenereCipher(original, key, true);
            }
            else if (Input2 == "decrypt" || Input2 == "d") {
                cout << vigenereCipher(original, key, false);
            }
            else {
                cout << "Invalid mode!";
            }
        }
    }
    else if (Input1 == "polybius" ||  Input1 == "p") {
        if (isallNum(original) == false) {
            cout << "Invalid message!";
        }
        else {
            if (Input2 == "encrypt" || Input2 == "e") {
                cout << polybiusSquare(grid, key, original, true);
            }
            else if (Input2 == "decrypt" || Input2 == "d") {
                cout << polybiusSquare(grid, key, original, false);
            }
            else {
                cout << "Invalid mode!";
            }
        }
    }
    else {
        cout << "Invalid cipher!";
    }
}
