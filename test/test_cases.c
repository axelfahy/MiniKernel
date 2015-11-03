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


void runKernelTest() {

    initScreen();
    setCursorPosition(12, 20);
    printCharacter('X');
    printCharacter('Y');
    setCursorPosition(1, 1);
    printCharacter('a');
    clearScreen();
    setCursorPosition(0, 0);
    printCharacter('A');
    setCursorPosition(0, 5);
    printCharacter('B');
    printString("Hello");
    setCursorPosition(5, 10);
    setTextColor(C_LIGHT_GREEN);
    setBackgroundColor(C_DARK_GRAY);
    printCharacter('C');
    setCursorPosition(77, 23);
    printCharacter('E');
    printString("Pikachu");

    clearScreen();

    for (int i = 0; i < SCREEN_HEIGHT; i++) {
        setCursorPosition(0, i);
        printCharacter(i + 48);
    }

    setCursorPosition(SCREEN_WIDTH - 1, SCREEN_HEIGHT - 1);
    printString("New Line");

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

    //for (int i = 0; i < SCREEN_HEIGHT; i++) {
    //    setCursorPosition(0, i);
    //    printCharacter(i + 48);
    //}

    //for (int i = 0; i < SCREEN_HEIGHT * SCREEN_WIDTH * 2; i++) {
    //    printCharacter(i % 255);
    //    sleep(15);
    //}
    //

    printString("                ");
    char *s = "J'aime les licornes...";
    printString(s);
    printf("Test string : %s", s);
    printString("                ");

    char c = 'z';
    char d = 'a';
    printf("Test char : %c et %c", c, d);
    printString("                ");

    printf("Test integer : %d et %d", 4213, 99);
    printString("                ");
    printf("Test hexa : %x et %x", 0xBABA, 0xA);
    printString("                ");

////////////////////////////////////////////////////////////////////////////////////////
    // Check cursor functions (set / get)
    uchar x, y;
    x = 2;
    y = 3;
    setCursorPosition(x, y);
    //printf("Set cursor position at (%d, %d).", x, y);
    getCursorPosition(&x, &y);
    printf("X:%d", x);
    printf("Y:%d", y);
    //printf("Position after get function (%d, %d).", x, y);
////////////////////////////////////////////////////////////////////////////////////////


}

void sleep(int c) {
    for (int i = 0; i < c * 1000; i++);
}
