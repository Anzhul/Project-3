/*
 * utility.cpp
 * Project UID e98fd45ccce9d7195e89e6171a5451f2
 *
 * Anzhu Ling
 * anzhul
 *
 * EECS 183: Project 3
 * Fall 2023
 *
 * <#description#>
 */

#include "utility.h"
#include <iostream>
#include <string>

/*
 * Requires: Nothing.
 * Modifies: Nothing.
 * Effects:  Returns a copy of original string with all alphabetical
 *           characters converted to uppercase. All other characters (numbers,
 *           symbols, spaces, punctuation marks, etc.) are unchanged.
 */
string toUpperCase(string original) {
    for (int i = 0; i < original.length(); i++) {
        if (original[i] >= 'a' && original[i] <= 'z') {
            original[i] = (original[i] - 'a') + 'A';
        }
    }
    return original;
}

/*
 * Requires: Nothing.
 * Modifies: Nothing.
 * Effects:  Returns a copy of original string with all non-alphabetical
 *           characters (numbers, symbols, spaces, punctuation marks, etc.)
 *           removed.
 *
 *           Example: "EECS 183!" -> "EECS"
 */
string removeNonAlphas(string original) {
    string a = "";
    for (int i = 0; i < original.length(); i++) {
        if ((original[i] >= 'A' && original[i] <= 'Z' )
        || (original[i] >= 'a' && original[i] <= 'z')) {
            a = a + original[i];
        }
    }
    return a;
}

/*
 * Requires: original contains only uppercase alphabet and/or digits from 0 to 9
 * Modifies: Nothing.
 * Effects:  Returns a copy of original string with duplicate characters except
 *           for the first occurence removed.
 *
 *           Example: "AABBCAB" -> "ABC"
 */
string removeDuplicate(string original) {
    for (int i = 0; i < original.length(); i++) {
        for (int j = i + 1; j < original.length(); j++) {
            if (original[i] == original[j]) {
                //Remove at index j, 1 represents length removed
                original.erase(j, 1);
                //Decrease j to account for the removed character
                j--;
            }
        }
    }
    return original;
}

/*
 * Requires: original is a character representing a number from 0 to 9.
 * Modifies: Nothing.
 * Effects:  Returns the integer representation of the correspondiong character.
 *
 *     Example: charToInt('1') returns the integer 1
 */
int charToInt(char original) {
    int a = 0;
    if (original >= '0' && original <= '9') {
        a = original - '0';
        return a;
    }
    else {
        return 0;
    }
}

/*int main(){
    cout << removeDuplicate("AABBCABLL000000") << endl;
    cout << toUpperCase("abcde") << endl;
    cout << removeNonAlphas("a65!cDE 7-u") << endl;
    cout << charToInt('1');
    cout << charToInt('4');
    return 0;
}*/

////////////////////////////////////////////////////////////////////////////////
// Do not touch code below. ////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

void printGrid(const char grid[SIZE][SIZE]) {
    for (int col = 0; col < SIZE; col++) {
        cout << " ---";
    }
    cout << endl;
    for (int row = 0; row < SIZE; row++) {
        cout << "| ";
        for (int col = 0; col < SIZE; col++) {
            cout << string(1, grid[row][col]) + " | ";
        }
        cout << endl;
        for (int col = 0; col < SIZE; col++) {
            cout << " ---";
        }
        cout << endl;
    }
}
