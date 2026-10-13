/*
 * ============================================================================
 * File        : g_fahrenheit_to_celsius.c
 * Title       : Exercise G - Fahrenheit to Celsius Converter
 * Author      : Muhammad Haruna
 * Date        : October 25th 2022
 * Version     : 1.0
 * Course      : MSc Electronic and Computer Engineering
 * Module      : Introduction to C Programming (Lab Exercises)
 * Institution : University of Birmingham, Department of Electronic,
 *               Electrical and Systems Engineering
 *
 * Description : Converts a temperature entered in degrees Fahrenheit to
 *               degrees Celsius using C = (5 / 9) * (F - 32).
 *
 *               Note: 5.0 / 9.0 is used instead of 5 / 9, because 5 / 9
 *               is integer division in C and evaluates to 0, which would
 *               make every result 0.
 *
 * Compiler    : GCC (MinGW) via Code::Blocks IDE
 * Build       : gcc g_fahrenheit_to_celsius.c -o g_fahrenheit_to_celsius
 * Usage       : ./g_fahrenheit_to_celsius
 *
 * Test Results:
 *   Fahrenheit (F)   Celsius (C)
 *   212              100.00
 *   150              65.56
 *   100              37.78
 *   50               10.00
 *   32               0.00
 *   0                -17.78
 *   -40              -40.00
 *   -100             -73.33
 *
 * Revision History:
 *   Version   Date              Author            Description
 *   1.0       25 October 2022   Muhammad Haruna   Initial version
 * ============================================================================
 */

#include <stdio.h>      /* Standard input/output library, needed for printf() and scanf() */

int main(void)          /* Program execution starts here */
{
    double fahrenheit;  /* Temperature entered by the user in degrees F */
    double celsius;     /* Converted temperature in degrees C */

    /* Display the program title and underline */
    printf("Fahrenheit to Celsius temperature reading converting program\n");
    printf("+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n\n");

    /* Prompt for and read the Fahrenheit reading */
    printf("Please enter your reading in degrees F   ");
    scanf("%lf", &fahrenheit);

    celsius = (5.0 / 9.0) * (fahrenheit - 32.0);    /* C = (5 / 9) * (F - 32) */

    /* Display the result */
    printf("Thank you,\n");
    printf("The temperature of your reading %.2f F is %.2f C\n", fahrenheit, celsius);

    return 0;           /* Tell the operating system the program ended successfully */
}