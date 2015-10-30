/*
 * =====================================================================================
 *
 *       Filename:  screen.c
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  10/16/2015 11:21:12 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Axel Fahy, Rudolf Hohn
 *   Organization:  HES-SO hepia section ITI
 *
 * =====================================================================================
 */

#include "screen.h"

// Screen properties
volatile screen s = {
    .cursor = (ushort*)FIRST_ADDR,
    .textColor = C_WHITE,
    .bgColor = C_BLACK
};

void initScreen() {
    // Default color
    setTextColor(C_WHITE);
    setBackgroundColor(C_BLACK);
    // Clear and set the cursor position
    clearScreen();
}


////////////////////////////////////////////////////////////////////////////////////////
void clearScreen() {
    // Clear all the screen
    setCursorPosition(0, 0);
    for (int i = 0; i < SCREEN_WIDTH * SCREEN_HEIGHT; i++) {
        printCharacter('\0');
    }
    setCursorPosition(0, 0);
}


////////////////////////////////////////////////////////////////////////////////////////
void setAllTextColor(uchar color) {
    // Change text color of all screen
    for (int i = 0; i < SCREEN_WIDTH; i++) {
        for (int j = 0; j < SCREEN_HEIGHT; j++) {
            //setTextColor(i, j, color);
        }
    }
}


////////////////////////////////////////////////////////////////////////////////////////
void setTextColor(uchar color) {
    s.textColor = color;
}


////////////////////////////////////////////////////////////////////////////////////////
uchar getTextColor() {
    return s.textColor;
}


////////////////////////////////////////////////////////////////////////////////////////
// TODO
void setAllBackgroundColor(uchar color) {
    // Change background color of all screen
    for (int i = 0; i < SCREEN_WIDTH; i++) {
        for (int j = 0; j < SCREEN_HEIGHT; j++) {
            //setBackgroundColor(i, j, color);
        }
    }
}


////////////////////////////////////////////////////////////////////////////////////////
void setBackgroundColor(uchar color) {
    s.bgColor = color;
}


////////////////////////////////////////////////////////////////////////////////////////
uchar getBackgroundColor() {
    return s.bgColor;
}


////////////////////////////////////////////////////////////////////////////////////////
void printCharacter(uchar character) {
    // Reset char
    *s.cursor = 0x0;

    // Set char (text and bg color and character value)
    *s.cursor = (s.bgColor << 12) | (s.textColor << 8) | character;
    // Move the cursor
    s.cursor++;

    // Update the cursor position on the screen
    uchar x, y;
    x = (uchar)((((uint)s.cursor - FIRST_ADDR) / 2) % SCREEN_WIDTH);
    y = (uchar)((((uint)s.cursor - FIRST_ADDR) / 2) / SCREEN_WIDTH);
    setCursorPosition(x, y); // KO ne marche pas car ne remet pas bien le curseur ?
}


////////////////////////////////////////////////////////////////////////////////////////
void printString(uchar* string) {
    // Print character until 0 is reached
    while (*string) {
        printCharacter(*(string++));
    }
}


////////////////////////////////////////////////////////////////////////////////////////
void printf() {

}


////////////////////////////////////////////////////////////////////////////////////////
void setCursorPosition(uchar x, uchar y) {
    ushort pos = y * SCREEN_WIDTH + x;

    outb(0x3d4, 14);
    outw(0x3d5, (ushort)(pos >> 8));    // MSB of pos
    outb(0x3d4, 15);
    outw(0x3d5, (ushort)(pos & 255));   // LSB of pos

    s.cursor = (ushort*)FIRST_ADDR;     // Go to first address
    s.cursor += (ushort)pos;            // Add the pos
}


////////////////////////////////////////////////////////////////////////////////////////
void getCursorPosition(uchar* x, uchar* y) {
    int pos, msb, lsb;
    outb(0x3d4, 14);
    msb = (int)(inw(0x3d5)); // MSB of pos
    outb(0x3d4, 15);
    lsb = (int)(inw(0x3d5)); // LSB of pos

    pos = lsb;
    pos = pos | (msb << 8);

    lineToGrid(pos, x, y);
}


////////////////////////////////////////////////////////////////////////////////////////
// NOT USED
ushort gridToLine(uchar x, uchar y) {
    // We need to multiply by 2 because each character is on 2 bytes
    return y * SCREEN_WIDTH + x;
}


////////////////////////////////////////////////////////////////////////////////////////
// NOT USED
void lineToGrid(ushort pos, uchar* x, uchar* y) {
    // x is the division, y the modulo
    *x = (uchar)(((pos) - FIRST_ADDR) / SCREEN_WIDTH);
    *y = (uchar)(((pos) - FIRST_ADDR) % SCREEN_WIDTH);
}

