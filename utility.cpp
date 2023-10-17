/*
 * utility.cpp
 * Project UID e98fd45ccce9d7195e89e6171a5451f2
 *
 * Anzhu Ling, Mason
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

//Shifts a character by n, wraps if necessary.
string toUpperCase(string original){
    for (int i = 0; i < original.length(); i++) {
        if (original[i] >= 'a' && original[i] <= 'z') {
            original[i] = (original[i] - 'a') + 'A';
        }
    }
    return original;
}

//Strips non-alpha characters from string.
string removeNonAlphas(string original){
    string a = "";
    for (int i = 0; i < original.length(); i++) {
        if (original[i] >= 'A' && original[i] <= 'Z' 
        || original[i] >= 'a' && original[i] <= 'z') {
            a = a + original[i];
        }
    }
    return a;
}

//Removes duplicate chars from string.
string removeDuplicate(string original){
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

//Turns a char into a int.
int charToInt(char original){
    int a = 0;
    if (original >= '0' && original <= '9') {
        a = original - '0';
        return a;
    }
}

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
