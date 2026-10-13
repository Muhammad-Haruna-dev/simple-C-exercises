/*
 * ============================================================================
 * File        : b_two_lines.c
 * Title       : Exercise B - Displaying Output on Two Lines
 * Author      : Muhammad Haruna
 * Date        : October 24th 2022
 * Version     : 1.0
 * Course      : MSc Electronic and Computer Engineering
 * Module      : Introduction to C Programming (Lab Exercises)
 * Institution : University of Birmingham, Department of Electronic,
 *               Electrical and Systems Engineering
 *
 * Description : Displays two lines of text on the standard output, using
 *               the newline escape sequence (\n) so that each sentence
 *               appears on its own line.
 *
 * Compiler    : GCC (MinGW) via Code::Blocks IDE
 * Build       : gcc b_two_lines.c -o b_two_lines
 * Usage       : ./b_two_lines
 *
 * Expected Output:
 *   This is my second program in C
 *   It displays output on two lines
 *
 * Revision History:
 *   Version   Date              Author            Description
 *   1.0       24 October 2022   Muhammad Haruna   Initial version
 * ============================================================================
 */

#include <stdio.h>      /* Standard input/output library, needed for printf() */

int main(void)          /* Program execution starts here */
{
    printf("This is my second program in C\n");   /* First line, then move to a new line */
    printf("It displays output on two lines\n");  /* Second line, then move to a new line */

    return 0;           /* Tell the operating system the program ended successfully */
}