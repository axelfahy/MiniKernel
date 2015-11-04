/*
 * =====================================================================================
 *
 *       Filename:  test_cases.c
 *
 *    Description:  Test case for kernel
 *
 *        Version:  1.0
 *        Created:  10/27/2015 04:36:29 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Axel Fahy (), axel.fahy@etu.hesge.ch
 *   Organization:  HES-SO hepia section ITI
 *
 * =====================================================================================
 */

#include "test_cases.h"
#include "../common/screen.h"

////////////////////////////////////////////////////////////////////////////////////////
void runKernelTest() {

    initScreen();
    //setCursorPosition(12, 20);
    //printCharacter('X');
    //printCharacter('Y');
    //setCursorPosition(1, 1);
    //printCharacter('a');
    //clearScreen();
    //setCursorPosition(0, 0);
    //printCharacter('A');
    //setCursorPosition(0, 5);
    //printCharacter('B');
    //printString("Hello");
    //setCursorPosition(5, 10);
    setTextColor(C_LIGHT_GREEN);
    setBackgroundColor(C_DARK_GRAY);
    //printCharacter('C');
    //setCursorPosition(77, 23);
    //printCharacter('E');
    //printString("Pikachu");

    //clearScreen();

    //for (int i = 0; i < SCREEN_HEIGHT; i++) {
    //    setCursorPosition(0, i);
    //    printCharacter(i + 48);
    //}

    //setCursorPosition(SCREEN_WIDTH - 1, SCREEN_HEIGHT - 1);
    //printString("New Line");

    //setAllTextColor(C_BLACK);
    //setAllBackgroundColor(C_WHITE);
    //setTextColor(C_BLACK);
    //setBackgroundColor(C_WHITE);

    //int* x;
    //int* y;
    //getCursorPosition(x, y);
    //printf("Pos : (%d, %d)", *x, *y);

    //setTextColor(C_WHITE);
    //setBackgroundColor(C_BLACK);

    //clearScreen();
////////////////////////////////////////////////////////////////////////////////////////
    // Color check
    setTextColor(C_CYAN);
    setBackgroundColor(C_WHITE);
    printString("Text written with different color\r\n");

/*
////////////////////////////////////////////////////////////////////////////////////////
    // Scroll check
    // Print number on first column
    for (int i = 0; i < SCREEN_HEIGHT; i++) {
        // Print in line
        setCursorPosition(0, i);
        printCharacter(i + 48);
        // Print in diagonale
        for (int j = i + 10; j < SCREEN_WIDTH; j+=10) {
            setCursorPosition(j, i);
            printCharacter(i + 48);
        }
    }
    setCursorPosition(SCREEN_WIDTH - 2, SCREEN_HEIGHT - 1);
    printString("NewLine");

    // Writes some characters in order to shift the screen (with a delay)
    for (int i = 0; i < SCREEN_HEIGHT * SCREEN_WIDTH * 2; i++) {
        printCharacter(i % 100);
        sleep(15);
    }
////////////////////////////////////////////////////////////////////////////////////////
    // Printf test
    //char *s = "printf function";
    //printf("Test : %s", s);

    //// char
    //char c1 = 'a';
    //char c2 = 'b';
    //printf("Test char : %c is followed by %c", c1, c2);

    //// integer
    //printf("Test integer : %d and %d (should be 4213 and 99)", 4213, 99);

    //// hex
    //printf("Test hex : %x and %x (should be 0xBABA and 0x42)", 0xBABA, 0x42);
*/
////////////////////////////////////////////////////////////////////////////////////////
    // Cursor check (set / get)
    sleep(20);
    clearScreen();
    uchar x, y;
    x = 20;
    y = 20;
    printf("Set cursor position at (%d, %d).", x, y);
    setCursorPosition(x, y);
    getCursorPosition(&x, &y);
    //printf("Position after get function (%d, %d).", x & (0x00FF), y & (0x00FF));
    printf("(%d, %d)", x, y);
    setCursorPosition(0, 2);
    outw(0x3d5, 'B');
    printf("B : %d", inw(0x3d5) & (0x00FF));
////////////////////////////////////////////////////////////////////////////////////////


}

////////////////////////////////////////////////////////////////////////////////////////
void sleep(int c) {
    for (int i = 0; i < c * 1000; i++);
}