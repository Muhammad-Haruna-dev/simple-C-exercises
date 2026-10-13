/*
 * ============================================================================
 * File        : d_expression_input.c
 * Title       : Exercise D - Evaluating an Expression from Keyboard Input
 * Author      : Muhammad Haruna
 * Date        : October 24th 2022
 * Version     : 1.0
 * Course      : MSc Electronic and Computer Engineering
 * Module      : Introduction to C Programming (Lab Exercises)
 * Institution : University of Birmingham, Department of Electronic,
 *               Electrical and Systems Engineering
 *
 * Description : Extends Exercise C so that the values of a, b, c and d are
 *               entered from the keyboard using scanf(). The program then
 *               calculates x = (a + b) - (c + d) and displays the result.
 *
 * Compiler    : GCC (MinGW) via Code::Blocks IDE
 * Build       : gcc d_expression_input.c -o d_expression_input
 * Usage       : ./d_expression_input
 *
 * Test Results:
 *   a     b     c     d     x
 *   16    34    7     12    31
 *   10    20    5     5     20
 *   -4    9     15    -2    -8
 *
 * Revision History:
 *   Version   Date              Author            Description
 *   1.0       24 October 2022   Muhammad Haruna   Initial version
 * ============================================================================
 */

#include <stdio.h>      /* Standard input/output library, needed for printf() and scanf() */

int main(void)          /* Program execution starts here */
{
    int a, b, c, d;     /* Input values entered by the user */
    int x;              /* Holds the result of the calculation */

    /* Explain to the user what the program does */
    printf("Enter values for a, b, c and d to calculate x = (a+b)-(c+d)\n");

    /* Prompt for each value in turn and read it from the keyboard */
    printf("Enter value for a: ");
    scanf("%d", &a);    /* &a passes the address of a, so scanf() can store the value there */

    printf("Enter value for b: ");
    scanf("%d", &b);

    printf("Enter value for c: ");
    scanf("%d", &c);

    printf("Enter value for d: ");
    scanf("%d", &d);

    x = (a + b) - (c + d);      /* Evaluate the expression */

    printf("x is equal to %d\n", x);   /* Display the result */

    return 0;           /* Tell the operating system the program ended successfully */
}