/*
 * caesar.cpp
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

#include "caesar.h"
#include <iostream>

/*
 * Requires: c is an alphabetical character.
 * Modifies: Nothing.
 * Effects:  Returns c shifted by n characters.
 *           If c is lowercase, it will remain lowercase.
 *           If c is uppercase, it will remain uppercase.
 * Used in:  caesarCipher.
 */
char shiftAlphaCharacter(char c, int n){
        if (isalpha(c)){
                if (islower(c)){
                    if ((c - 'a' + n) < 0){
                        c = ('z' + (c - 'a' + n) % 26) + 1;
                    }
                    else{
                        //(difference of original + shift)remainder + base
                        c = (c - 'a' + n) % 26 + 'a';
                    }

                }
                else if (isupper(c)){
                    if ((c - 'A' + n) < 0){
                        c = ('Z' + (c - 'A' + n) % 26) + 1;
                    }
                    else{
                        c = (c - 'A' + n) % 26 + 'A';
                    }
                }
        }
        return c;
}

/*
 * Requires: Nothing.
 * Modifies: Nothing.
 * Effects:  If encrypt is true, returns string encrypted with Caesar cipher
 *           using key. If encrypt is false, returns string decrypted with
 *           Caesar cipher using key.
 */
string caesarCipher(string original, int key, bool encrypt){
    if (encrypt){
        string encrypted = "";
        //Iterate through string, shift each character by key int.
        for (int i = 0; i < original.length(); i++){
            encrypted += shiftAlphaCharacter(original[i], key);
        }
        return encrypted;
    }else{
        string decrypted = "";
        for (int i = 0; i < original.length(); i++){
            decrypted += shiftAlphaCharacter(original[i], -key);
        }
        return decrypted;
    }
}

/*int main(){
    cout << caesarCipher("Meet me at the Diag at 11 p.m.", 42, true) << endl;
    cout << caesarCipher("Meet me at the Diag at 11 p.m.", 42, false) << endl;
    cout << caesarCipher("abcde", 50, true) << endl;
    cout << caesarCipher("abcde", 2, true) << endl;
    return 0;
}*/
