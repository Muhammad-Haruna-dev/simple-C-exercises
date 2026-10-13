/*
 * ============================================================================
 * File        : h_even_odd.c
 * Title       : Exercise H - Even or Odd Number Checker
 * Author      : Muhammad Haruna
 * Date        : October 27th 2022
 * Version     : 1.0
 * Course      : MSc Electronic and Computer Engineering
 * Module      : Introduction to C Programming (Lab Exercises)
 * Institution : University of Birmingham, Department of Electronic,
 *               Electrical and Systems Engineering
 *
 * Description : Repeatedly reads whole numbers from the keyboard and
 *               displays "Even" or "Odd" for each one. The program stops
 *               when the user enters a number less than 0 or greater
 *               than 999.
 *
 *               A number is even if dividing it by 2 leaves no remainder,
 *               which is tested with the modulus operator (%).
 *
 * Compiler    : GCC (MinGW) via Code::Blocks IDE
 * Build       : gcc h_even_odd.c -o h_even_odd
 * Usage       : ./h_even_odd
 *
 * Example:
 *   Enter a number (0-999): 14     -> Even
 *   Enter a number (0-999): 7      -> Odd
 *   Enter a number (0-999): 0      -> Even
 *   Enter a number (0-999): 1000   -> program ends
 *
 * Revision History:
 *   Version   Date              Author            Description
 *   1.0       27 October 2022   Muhammad Haruna   Initial version
 * ============================================================================
 */

#include <stdio.h>      /* Standard input/output library, needed for printf() and scanf() */

#define MIN_VALUE 0     /* Smallest number accepted */
#define MAX_VALUE 999   /* Largest number accepted */

int main(void)          /* Program execution starts here */
{
    int number;         /* Number entered by the user */

    printf("Even or Odd checker\n");
    printf("Enter a number less than %d or greater than %d to exit.\n\n",
           MIN_VALUE, MAX_VALUE);

    while (1)           /* Keep reading until an out-of-range number is entered */
    {
        printf("Enter a number (%d-%d): ", MIN_VALUE, MAX_VALUE);

        if (scanf("%d", &number) != 1)      /* scanf() returns 1 if a number was read successfully */
        {
            printf("Invalid input. Please enter a whole number.\n");
            while (getchar() != '\n')       /* Discard the rest of the invalid line */
            {
            }
            continue;                       /* Ask again */
        }

        if (number < MIN_VALUE || number > MAX_VALUE)   /* Out of range, so stop */
        {
            break;
        }

        if (number % 2 == 0)    /* Remainder of 0 when divided by 2 means even */
        {
            printf("Even\n");
        }
        else
        {
            printf("Odd\n");
        }
    }

    printf("Number out of range. Program ended.\n");

    return 0;           /* Tell the operating system the program ended successfully */
}