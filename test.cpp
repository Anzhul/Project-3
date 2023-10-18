#include "utility.h"
#include "caesar.h"
#include "vigenere.h"
#include "polybius.h"
#include <iostream>
#include <string>

using namespace std;

void testShiftAlphaCharacter();
void testToUpperCase();
void testRemoveNonAlphas();
void testRemoveDuplicate();
void testCharToInt();
void testCaesarCipher();
void testVigenereCipher();
void testFillGrid();
void testMixKey();
void testFindInGrid();
void testPolybiusSquare();

void startTests(){
    testToUpperCase();
    testRemoveNonAlphas();
    testRemoveDuplicate();
    testCharToInt();
    testShiftAlphaCharacter();
    testCaesarCipher();
    testVigenereCipher();
    testFillGrid();
    testMixKey();
    testFindInGrid();
    testPolybiusSquare();
    return;
}

void testShiftAlphaCharacter(){
    cout << "Now testing function ShiftAlphaCharacter()" << endl;
    cout << "Expected: 'a', Actual: '" << shiftAlphaCharacter('a', 0) << "'" << endl;
    cout << "Expected: 'b', Actual: '" << shiftAlphaCharacter('a', 1) << "'" << endl;
    cout << "Expected: 'd', Actual: '" << shiftAlphaCharacter('b', 2) << "'" << endl;
    cout << "Expected: 'y', Actual: '" << shiftAlphaCharacter('a', -2) << "'" << endl;
    cout << "Expected: 'p', Actual: '" << shiftAlphaCharacter('z', -10) << "'" << endl;
    cout << "Expected: 'B', Actual: '" << shiftAlphaCharacter('Z', 2) << "'" << endl;
    cout << "Expected: 'H', Actual: '" << shiftAlphaCharacter('Z', -200) << "'" << endl;
    cout << "Expected: 'B', Actual: '" << shiftAlphaCharacter('A', -26) << "'" << endl;
    cout << "Expected: 'H', Actual: '" << shiftAlphaCharacter('l', 200) << "'" << endl;
    return;
}

void testToUpperCase(){
    cout << "Now testing function ToUpperCase()" << endl;
    cout << "Expected: 'HELLO', Actual: '" << toUpperCase("hello") << "'" << endl;
    cout << "Expected: 'OH NO', Actual: '" << toUpperCase("oH No") << "'" << endl;
    cout << "Expected: 'THIS IS WORKING', Actual: '" << toUpperCase("thIs is WORKING") 
    << "'" << endl;
    cout << "Expected: 'HEHE 420', Actual: '" << toUpperCase("Hehe 420") << "'" << endl;
    cout << "Expected: '3CSE3-EAF MWEAFW', Actual: '" << toUpperCase("3cse3-eaf mweafw") 
    << "'" << endl;
}

void testRemoveNonAlphas(){
    cout << "Now testing function RemoveNonAlphas()" << endl;
    cout << "Expected: 'hello', Actual: '" << removeNonAlphas("hello342") << "'" << endl;
    cout << "Expected: 'oHNo', Actual: '" << removeNonAlphas("oH No") << "'" << endl;
    cout << "Expected: 'thIsisWORKING', Actual: '" << removeNonAlphas("thIs is WORKING")
    << "'" << endl;
    cout << "Expected: 'Hehe', Actual: '" << removeNonAlphas("Hehe 420") << "'" << endl;
    cout << "Expected: 'a', Actual: '" << removeNonAlphas("2423948a2_32321") << "'" << endl;
}

void testRemoveDuplicate(){
    cout << "Now testing function RemoveDuplicate()" << endl;
    cout << "Expected: '1234567', Actual: '" << removeDuplicate("1234567") << "'" << endl;
    cout << "Expected: 'HELO', Actual: '" << removeDuplicate("HELLO") << "'" << endl;
    cout << "Expected: 'OHN', Actual: '" << removeDuplicate("OHNO") << "'" << endl;
    cout << "Expected: '321YO', Actual: '" << removeDuplicate("321213YO") << "'" << endl;
    cout << "Expected: 'YOI', Actual: '" << removeDuplicate("YOYOYOYOYI") << "'" << endl;
    cout << "Expected: '123456789', Actual: '" << removeDuplicate("123456789") << "'" << endl;
    cout << "Expected: 'A', Actual: '" << removeDuplicate("AAAAAAAAA") << "'" << endl;
    cout << "Expected: '21B4CGH', Actual: '" << removeDuplicate("21B4CGH4") << "'" << endl;
}

void testCharToInt(){
    cout << "Now testing function CharToInt()" << endl;
    cout << "Expected: 1, Actual: '" << charToInt('1') << "'" << endl;
    cout << "Expected: 2, Actual: '" << charToInt('2') << "'" << endl;
    cout << "Expected: 1, Actual: '" << charToInt('8') << "'" << endl;
    cout << "Expected: 5, Actual: '" << charToInt('4') << "'" << endl;
}
    
void testCaesarCipher(){
    cout << "Now testing function CaesarCipher()" << endl;
    cout << "Expected: 'hello', Actual: '" << caesarCipher("hello", 0, true) << "'" << endl;
    cout << "Expected: 'ifmmp', Actual: '" << caesarCipher("hello", 1, true) << "'" << endl;
    cout << "Expected: 'hello', Actual: '" << caesarCipher("ifmmp", 1, false) << "'" << endl;
    cout << "Expected: 'KD JK', Actual: '" << caesarCipher("OH NO", -4, true) << "'" << endl;
    cout << "Expected: 'OH NO', Actual: '" << caesarCipher("KD JK", -4, false) << "'" << endl;
    cout << "Expected: 'BUS BUNNY 123', Actual: '" << caesarCipher("BUGS BUNNY 123", 26, true) 
    << "'" << endl;
    cout << "Expected: 'bPqa QA i BMAB??', Actual: '" << caesarCipher("tHis IS a TEST??", 8, true) << endl;
    cout << "Expected: 'tHis IS a TEST??', Actual: '" << caesarCipher("bPqa QA i BMAB??", 8, false) 
    << "'" << endl;

}

void testVigenereCipher(){
    cout << "Now testing function VigenereCipher()" << endl;
    cout << "Expected: 'hola', Actual: '" << vigenereCipher("hola", "a", true) << "'" << endl;
    cout << "Expected: '2432432bruh', Actual: '" << vigenereCipher("2432432bruh", "afadsw", false) << "'" << endl;
    cout << "Expected: 'kwx aax ipatl mvw', Actual: '" 
    << vigenereCipher("for the blood god", "FIGHT THEM", true) << "'" << endl;
    cout << "Expected: 'XPRPB', Actual: '" << vigenereCipher("YARGH", "BLARGH", false) << "'" << endl;
    cout << "Expected: 'Odeexei Odkaa', Actual: '" << vigenereCipher("Charlie Brown", "121314mwen", true) << "'" << endl;
    cout << "Expected: 'OH NO', Actual: '" << vigenereCipher("KD JK", "a", false) << "'" << endl;
    cout << "Expected: 'BUS BUNNY 123', Actual: '" << vigenereCipher("BUGS BUNNY 123", "afewq", true)<< "'" << endl;
}
    
void testFillGrid(){
    cout << "Now testing function FillGrid()" << endl;
    char grid[SIZE][SIZE];
    fillGrid(grid, ALNUM);
    cout << "Expected: 'A', Actual: '" << grid[0][0] << "'" << endl;
    cout << "Expected: '1', Actual: '" << grid[4][3] << "'" << endl;
    cout << "Expected: 'M', Actual: '" << grid[2][0] << "'" << endl;
    cout << "Expected: '4', Actual: '" << grid[4][4] << "'" << endl;
}

void testMixKey(){
    cout << "Now testing function MixKey()" << endl;
    cout << "Expected: 'ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789', Actual: '" 
    << mixKey("ABC") << "'" << endl;
    cout << "Expected: '6435AEWYIBCDFGHJKLMNOPQRSTUVXZ012789', Actual: '" 
    << mixKey("YUMI9") << "'" << endl;   
    cout << "Expected: 'LANDERYBCFGHIJKMOPQSTUVWXZ0123456789'" << mixKey("LAND") << "'" << endl;
    cout << "Expected: '1A2B3CDEFGHIJKLMNOPQRSTUVWXYZ0456789'" << mixKey("1A2B3C") << "'" << endl;
    cout << "Expected: 'WATBCDEFGHIJKLMNOPQRSUVXYZ0123456789'" << mixKey("WAT") << "'" << endl;
    cout << "Expected: '97421vweABCDEFGHIJKLMNOPQRSTUVWXYZ03568'" << mixKey("97421vwe") << "'" << endl;

}
    
void testFindInGrid(){
    cout << "Now testing function FindInGrid()" << endl;
    char grid[SIZE][SIZE];
    fillGrid(grid, ALNUM);
    cout << "Expected: '00', Actual: '" << findInGrid('A', grid) << "'" << endl;
    cout << "Expected: '43', Actual: '" << findInGrid('1', grid) << "'" << endl;
    cout << "Expected: '20', Actual: '" << findInGrid('M', grid) << "'" << endl;
    cout << "Expected: '21', Actual: '" << findInGrid('N', grid) << "'" << endl;
    cout << "Expected: '02', Actual: '" << findInGrid('C', grid) << "'" << endl;
    cout << "Expected: '55', Actual: '" << findInGrid('9', grid) << "'" << endl;
    cout << "Expected: '50', Actual: '" << findInGrid('4', grid) << "'" << endl;
}
    
void testPolybiusSquare(){
    cout << "Now testing function PolybiusSquare()" << endl;
    char grid[SIZE][SIZE];
    fillGrid(grid, ALNUM);
    cout << "Expected: '00', Actual: '" << polybiusSquare(grid, "ABC", "A", true) << "'" << endl;
    cout << "Expected: '43', Actual: '" << polybiusSquare(grid, "ABC", "1", true) << "'" << endl;
    cout << "Expected: '20', Actual: '" << polybiusSquare(grid, "ABC", "M", true) << "'" << endl;
    cout << "Expected: '21', Actual: '" << polybiusSquare(grid, "ABC", "N", true) << "'" << endl;
    cout << "Expected: '02', Actual: '" << polybiusSquare(grid, "ABC", "C", false) << "'" << endl;
    cout << "Expected: '55', Actual: '" << polybiusSquare(grid, "ABC", "9", false) << "'" << endl;
    cout << "Expected: '02', Actual: '" << polybiusSquare(grid, "ABC", "CG9", false) << "'" << endl;
    cout << "Expected: '55', Actual: '" << polybiusSquare(grid, "ABC", "93V41", false) << "'" << endl;
}
