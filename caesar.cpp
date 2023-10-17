/*
 * caesar.cpp
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

#include "caesar.h"
#include <iostream>


//Shifts a character by n, wraps if necessary.
char shiftAlphaCharacter(char c, int n){
        if (isalpha(c)){
                if (islower(c)){
                    if ((c - 'a' + n) < 0){
                        c = ('z' + (c-'a' + n + 1) % 26);
                    }
                    else{
                        //(difference of original + shift)remainder + base
                        c = (c - 'a' + n) % 26 + 'a';
                    }
                }
                else if (isupper(c)){
                    if ((c - 'A' + n) < 0){
                        c = ('Z' + (c-'A' + n + 1) % 26);
                    }
                    else{
                        c = (c - 'A' + n) % 26 + 'A';
                    }
                    return c;
                }
        }
        return c;
}

//Encrypts or decrypts a string by shifting it by key amount.
string caesarCipher(string original, int key, bool encrypt){
    if (encrypt){
        string encrypted = "";
        //Iterate through string, shift each character by key int.
        for (int i = 0; i < original.length(); i++){
            encrypted += shiftAlphaCharacter(original[i], key);
        }
        return encrypted;
    }
    else{
        string decrypted = "";
        for (int i = 0; i < original.length(); i++){
            decrypted += shiftAlphaCharacter(original[i], -key);
        }
        return decrypted;
    }
}