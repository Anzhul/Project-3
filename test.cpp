#include "utility.h"
#include "caesar.h"
#include "vigenere.h"
#include "polybius.h"
#include "test.h"
#include <iostream>

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
}
