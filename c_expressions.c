/*
 * ============================================================================
 * File        : c_expression.c
 * Title       : Exercise C - Evaluating a Simple Arithmetic Expression
 * Author      : Muhammad Haruna
 * Date        : October 24th 2022
 * Version     : 1.0
 * Course      : MSc Electronic and Computer Engineering
 * Module      : Introduction to C Programming (Lab Exercises)
 * Institution : University of Birmingham, Department of Electronic,
 *               Electrical and Systems Engineering
 *
 * Description : Calculates the expression x = (a + b) - (c + d) using
 *               integer variables with fixed test values, and displays
 *               the result using printf().
 *
 * Test Values : a = 16, b = 34, c = 7, d = 12
 *
 * Compiler    : GCC (MinGW) via Code::Blocks IDE
 * Build       : gcc c_expression.c -o c_expression
 * Usage       : ./c_expression
 *
 * Expected Output:
 *   x = (16 + 34) - (7 + 12) = 31
 *
 * Revision History:
 *   Version   Date              Author            Description
 *   1.0       24 October 2022   Muhammad Haruna   Initial version
 * ============================================================================
 */

#include <stdio.h>      /* Standard input/output library, needed for printf() */

int main(void)          /* Program execution starts here */
{
    /* Declare the integer variables and assign the test values */
    int a = 16;
    int b = 34;
    int c = 7;
    int d = 12;
    int x;              /* Holds the result of the calculation */

    x = (a + b) - (c + d);      /* Evaluate the expression */

    /* Display the expression with its values and the result */
    printf("x = (%d + %d) - (%d + %d) = %d\n", a, b, c, d, x);

    return 0;           /* Tell the operating system the program ended successfully */
}