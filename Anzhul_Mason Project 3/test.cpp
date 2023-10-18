#include "utility.h"
#include "caesar.h"
#include "vigenere.h"
#include "polybius.h"
#include <iostream>



void testShiftAlphaCharacter() {
    cout << "Now testing function shiftAlphaCharacter()" << endl;
    cout << "Expected: 'a', Actual: '" << shiftAlphaCharacter('a', 0) << "'" << endl;
    cout << "Expected: 'b', Actual: '" << shiftAlphaCharacter('a', 1) << "'" << endl;
    cout << "Expected: 'd', Actual: '" << shiftAlphaCharacter('b', 2) << "'" << endl;
    return;
}

void testToUpperCase() {
    cout << "Now testing function toUpperCase()" << endl;
    cout << "Expected: 'ABC', Actual: '" << toUpperCase("abc") << "'" << endl;
    cout << "Expected: 'CBA', Actual: '" << toUpperCase("cba") << "'" << endl;
    cout << "Expected: 'KKK', Actual: '" << toUpperCase("kkk") << "'" << endl;
}

void testRemoveNonAlphas() {
    cout << "Now testing function removeNonAlphas()" << endl;
    cout << "Expected: 'abc', Actual: '" << removeNonAlphas("abc123") << "'" << endl;
    cout << "Expected: 'ABC', Actual: '" << removeNonAlphas("ABC456") << "'" << endl;
    cout << "Expected: 'WSH', Actual: '" << removeNonAlphas("W!S@H#") << "'" << endl;
}

void testRemoveDuplicate() {
    cout << "Now testing function removeDuplicate()" << endl;
    cout << "Expected: 'abc', Actual: '" << removeDuplicate("aabbcc") << "'" << endl;
    cout << "Expected: 'ABC', Actual: '" << removeDuplicate("AABBCC") << "'" << endl;
    cout << "Expected: 'jibao!', Actual: '" << removeDuplicate("jijibao!jijibao!") << "'" << endl;
}

void testCharToInt() {
    cout << "Now testing function charToInt()" << endl;
    cout << "Expected: '0', Actual: '" << charToInt('0') << "'" << endl;
    cout << "Expected: '1', Actual: '" << charToInt('1') << "'" << endl;
    cout << "Expected: '2', Actual: '" << charToInt('2') << "'" << endl;
}

void testCaesarCipher() {
    cout << "Now testing function caesarCipher()" << endl;
    cout << "Expected: 'khoor', Actual: '" << caesarCipher("hello", 3, true) << "'" << endl;
    cout << "Expected: 'OLSSV', Actual: '" << caesarCipher("HELLO", 7, true) << "'" << endl;
    cout << "Expected: 'hello', Actual: '" << caesarCipher("olssv", 7, false) << "'" << endl;
    cout << "Expected: 'Meet me at the Diag at 11 p.m.', Actual: '" << caesarCipher("Cuuj cu qj jxu Tyqw qj 11 f.c.", 42, false) << "'" << endl;
}

void testVigenereCipher() {
    cout << "Now testing function vigenereCipher()" << endl;
    cout << "Expected: 'RIJVSUYVJN', Actual: '" << vigenereCipher("HELLOWORLD", "key", true) << "'" << endl;
    cout << "Expected: 'rfrktopqkbj', Actual: '" << vigenereCipher("programming", "code", true) << "'" << endl;
    cout << "Expected: 'Meet me at the Diag at 11 p.m.', Actual: '" << vigenereCipher("Euyb dv ee lxy Lzrk ll 11 f.g.", "Squirrel!", false) << "'" << endl;
}

void testFillGrid() {
    cout << "Now testing function fillGrid()" << endl;
    char grid[SIZE][SIZE];
    fillGrid(grid, ALNUM);
    cout << "Expected: '" << endl;
    cout << "ABCDEF\nGHIJKL\nMNOPQR\nSTUVWX\nYZ0123\n456789" << endl;
    cout << "'" << endl;
    cout << "Actual: '" << endl;
    printGrid(grid);
    cout << "'" << endl;
}

void testMixKey() {
    cout << "Now testing function mixKey()" << endl;
    cout << "Expected: '01234ABCDEFGHIJKLMNOPQRSTUVWXYZ56789', Actual: '" << mixKey("01234") << "'" << endl;
    cout << "Expected: 'WSHABCDEFGIJKLMNOPQRTUVXYZ0123456789', Actual: '" << mixKey("WSH") << "'" << endl;
}

void testFindInGrid() {
    cout << "Now testing function findInGrid()" << endl;
    char grid[SIZE][SIZE];
    fillGrid(grid, ALNUM);
    cout << "Expected: '00', Actual: '" << findInGrid('A', grid) << "'" << endl;
    cout << "Expected: '55', Actual: '" << findInGrid('9', grid) << "'" << endl;
}

void testPolybiusSquare() {
    cout << "Now testing function polybiusSquare()" << endl;
    char grid[SIZE][SIZE];
    cout << "Expected: '413314', Actual: '" << polybiusSquare(grid, "123", "WSH", true) << "'" << endl;
    cout << "Expected: '183', Actual: '" << polybiusSquare(grid, "POLYBIUS", "435445", false) << "'" << endl;
}

void startTests(){
    cout << "Beginning Test"<< endl;
    char grid[SIZE][SIZE];
    fillGrid(grid, "POLYBIUSABCDEFGHIJKLMNOQRSTUVWXYZ0123456789");
    fillGrid(grid, ALNUM);
    printGrid(grid);
    cout << mixKey("POLYBIUS") << endl;
    cout << findInGrid('G', grid) << endl;
    cout << polybiusSquare(grid, "183", "EECS 183 IS THE BEST", true) << endl;
    cout << polybiusSquare(grid, "183", "11110533 000102 1533 341411 04113334", false) << endl;
    testShiftAlphaCharacter();
    testToUpperCase();
    testRemoveNonAlphas();
    testRemoveDuplicate();
    testCharToInt();
    testCaesarCipher();
    testVigenereCipher();
    testFillGrid();
    testMixKey();
    testFindInGrid();
    testPolybiusSquare();
}
