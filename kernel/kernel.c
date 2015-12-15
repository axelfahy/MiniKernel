/*
 * =====================================================================================
 *
 *       Filename:  kernel.c
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  10/16/2015 11:22:24 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Axel Fahy, Rudolf Hohn
 *   Organization:  HES-SO hepia section ITI
 *
 * =====================================================================================
 */

#include "../test/test_cases.h"
#include "kernel.h"
#include "x86.h"
#include "gdt.h"
#include "idt.h"
#include "pic.h"
#include "screen.h"
#include "keyboard.h"
#include "timer.h"
#include "../common/pfs.h"

void runKernel() {

    // Init of gdt
    gdt_init();

    // Init of idt
    idt_init();

    // Remap interruptions
    // Needs to be done before activate them
    pic_init();

    // Init of screen
    initScreen();

    // Init of timer
    timer_init(DEFAULT_FREQ);

    // Init of keyboard with CH layout
    keyboard_init(LAYOUT_CH);

    // Activation of interruption (needs to be at the end)
    sti();

    // Messages of initialization
    printf("Starting GDT                                                           [  ");
    setTextColor(C_GREEN);
    printf("OK");
    setTextColor(C_WHITE);
    printf("  ]\r\n");

    printf("Starting screen                                                        [  ");
    setTextColor(C_GREEN);
    printf("OK");
    setTextColor(C_WHITE);
    printf("  ]\r\n");

    printf("Starting PIC                                                           [  ");
    setTextColor(C_GREEN);
    printf("OK");
    setTextColor(C_WHITE);
    printf("  ]\r\n");

    printf("Enabling interruptions                                                 [  ");
    setTextColor(C_GREEN);
    printf("OK");
    setTextColor(C_WHITE);
    printf("  ]\r\n");

    printf("Starting IDT                                                           [  ");
    setTextColor(C_GREEN);
    printf("OK");
    setTextColor(C_WHITE);
    printf("  ]\r\n");

    printf("Starting timer at %d[Hz]                                              [  ", DEFAULT_FREQ);
    setTextColor(C_GREEN);
    printf("OK");
    setTextColor(C_WHITE);
    printf("  ]\r\n");

    printf("Starting keyboard                                                      [  ");
    setTextColor(C_GREEN);
    printf("OK");
    setTextColor(C_WHITE);
    printf("  ]\r\n");

    // Init of PFS (Filesystem)
    if (pfs_init() < 0) {
        printf("Problem during init of PFS\r\n");
        halt();
    }
    else {
        printf("Starting PFS                                                           [  ");
        setTextColor(C_GREEN);
        printf("OK");
        setTextColor(C_WHITE);
        printf("  ]\r\n");
    }


    // Print the splash screen from file
    char buffer[BUFFER_SIZE_SPLASH];
    file_read(SPLASH_FILE, (void *)&buffer);
    printf("%s\n", buffer);
    printf("> ");

#ifdef TEST
    runKernelTest();
#else
    for (;;) {
        char c = (char)(getc());
        if ((int)(c) >= 0) {
            if (c == 'Q') {
                printf("\r\nShutdown of the system in 1 second.");
                sleep(1000);
                printf("\r\nNOW !");
                halt();
            }
            else {
                printf("%c", c);
            }
        }
    }
#endif

}
