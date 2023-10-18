/*
 * polybius.cpp
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


#include "polybius.h"
#include "utility.h"
#include <string>
#include <iostream>

//Mix the key with given ALNUM string.
string mixKey(string key){
    string mixedKey = "";
    mixedKey = key + ALNUM;
    //Remove original key chars from mixKey
    for (int i = 0; i < mixedKey.length(); i++){
        for (int j = (i + 1); j < mixedKey.length(); j++){
            if (mixedKey[i] == mixedKey[j]){
                mixedKey.erase(j, 1);
                //Reverse one spot
                j--;
            }
        }
    }
    return mixedKey;
}

//Fill given grid with content.
void fillGrid(char grid[SIZE][SIZE], string content){
    for (int i = 0; i < SIZE; i++){
        for (int j = 0; j < SIZE; j++){
            grid[i][j] = content[(i * SIZE) + j];
        }
    }
}

//Find character c in grid.
string findInGrid(char c, char grid[SIZE][SIZE]){
    string position = "";
    for (int i = 0; i < SIZE; i++){
        for (int j = 0; j < SIZE; j++){
            if (grid[i][j] == c){
                position += to_string(i);
                position += to_string(j);
            }
        }
    }
    return position;
}

//Encrypts by creating a grid with the given key. iF encrypt false then decrypts.
string polybiusSquare(char grid[SIZE][SIZE], string key, string original, bool encrypt){
    //Fills grid with mixdKey
    string mixedKey = mixKey(key);
    fillGrid(grid, mixedKey);
    string output = "";
    if (encrypt){
        for (int i = 0; i < original.length(); i++){
            if (isalpha(original[i]) || isdigit(original[i])){
                output += findInGrid(original[i], grid);
            }
            else {
                output += ' ';
            }
        }
        return output;
    }
    //Decryption
    else{
        for (int i = 0; i < original.length(); i++){
            if (original[i] == ' '){
                output += " ";
            }
            else{
                output += grid[charToInt(original[i])][charToInt(original[i + 1])];
                i++;
            }
        }
        return output;
    }
}