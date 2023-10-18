/*
 * ciphers.cpp
 * Project UID e98fd45ccce9d7195e89e6171a5451f2
 *
 * Anzhu Ling, Songhan Wu
 * anzhul, wuumaa
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

void ciphers(){
    string cipher;
    string encrypt;
    bool encryptBool = false;
    string message;
    string key;
    int caesarKey = 0;

    //Choosing which cipher to use
    cout << "Choose a cipher (Caesar, Vigenere, or Polybius): ";
    cin >> cipher;
    cout << endl;
    cipher = toUpperCase(cipher);
    if (cipher != "C" && cipher != "V" && cipher != "P" && 
    cipher != "CAESAR" && cipher != "VIGENERE" && cipher != "POLYBIUS"){
        cout << "Invalid cipher!";
        return;
    }

    //Encryption type
    cout << "Encrypt or decrypt: ";
    cin >> encrypt;
    cout << endl;
    encrypt = toUpperCase(encrypt);
    if (encrypt != "E" && encrypt != "D" && encrypt != "ENCRYPT" && encrypt != "DECRYPT"){
        cout << "Invalid mode!";
        return;
    }
    if (encrypt == "E" || encrypt == "ENCRYPT"){
        encryptBool = true;
    }
    else{
        encryptBool = false;
    };


    //Enter a message
    cout << "Enter a message: ";
    //It keeps ignoring the first character of the message. 
    //Remove this if it conflicts with the autograder.
    cin.ignore(1, '\n');
    getline(cin, message);
    cout << endl;
    if (cipher == "P" || cipher == "POLYBIUS"){
        for (int i = 0; i < message.length(); i++){
            if (!isalpha(message[i]) && !isdigit(message[i]) && message[i] != ' '){
                cout << "Invalid message!";
                return;
            }
        }
    }

    //Enter a key
    cout << "What is your key: ";
    if (cipher =="C" || cipher == "CAESAR"){
        cin >> caesarKey;
    }
    else{
        getline(cin, key);
    }
    cout << endl;
    if (cipher == "V" || cipher == "VIGENERE"){
        bool valid = false;
        for (int i = 0; i < key.length(); i++){
            if (isalpha(key[i])){
                valid = true;
            }
        }
        if (!valid){
            cout << "Invalid key!";
            return;
        }
    }

    //Encryption of the various functions. 
    if (cipher == "P" || cipher == "POLYBIUS"){
        //Create the grid.
        char grid[SIZE][SIZE];
        fillGrid(grid, ALNUM);
        //Convert to uppercase.
        message = toUpperCase(message);
        key = toUpperCase(key);
        key = removeNonAlphas(key);
        key = removeDuplicate(key);
        if (encryptBool){
            cout << "The encrypted message is: ";
        }
        else{
            cout << "The decrypted message is: ";
        }
        cout << polybiusSquare(grid, key, message, encryptBool) << endl;
    }
    else if (cipher == "C" || cipher == "CAESAR"){
        if (encryptBool){
            cout << "The encrypted message is: ";
        }
        else{
            cout << "The decrypted message is: ";
        }
        cout << caesarCipher(message, caesarKey, encryptBool) << endl;
    }
    else if (cipher == "V" || cipher == "VIGENERE"){
        if (encryptBool){
            cout << "The encrypted message is: ";
        }
        else{
            cout << "The decrypted message is: ";
        }
        cout << vigenereCipher(message, key, encryptBool) << endl;
    }
}