/*
 * vigenere.cpp
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
#include "caesar.h"
#include "vigenere.h"
#include <iostream>

//Shifts a string by a keyword.
//Shifts backwards if encrypt is false. 
string vigenereCipher(string original, string keyword, bool encrypt){
    string key = "";
    int j = 0;
    int test = 0;
    //Remember to strip all non-alphabetic characters from the keyword.
    key = removeNonAlphas(keyword);
    //Convert all letters in the keyword to uppercase.
    key = toUpperCase(key);
    if (encrypt){
        for (int i = 0; i < original.length(); i++){
            if (isalpha(original[i])){
                original[i] = shiftAlphaCharacter(original[i], key[j%key.length()]-'A');
                j++;
            }
        }
        return original;
    }
    else{
        for (int i = 0; i < original.length(); i++){
            if (isalpha(original[i])){
                original[i] = shiftAlphaCharacter(original[i], -(key[j%key.length()]-'A'));
                j++;
            }
        }
        return original;
    }
}