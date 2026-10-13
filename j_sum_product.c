/*
 * ============================================================================
 * File        : j_sum_product.c
 * Title       : Exercise J - Sum of Integers and Product of Floats
 * Author      : Muhammad Haruna
 * Date        : October 25th 2022
 * Version     : 1.0
 * Course      : MSc Electronic and Computer Engineering
 * Module      : Introduction to C Programming (Lab Exercises)
 * Institution : University of Birmingham, Department of Electronic,
 *               Electrical and Systems Engineering
 *
 * Description : Reads a series of numbers from the keyboard, which may be
 *               integers or floating-point numbers. The series ends when
 *               -999 is entered. At the end, the program displays the sum
 *               of all the integers and the product of all the
 *               floating-point numbers.
 *
 *               Every number is read as a double. A number is treated as
 *               an integer if it has no fractional part, which is tested
 *               by checking whether the number equals floor() of itself.
 *
 * Compiler    : GCC (MinGW) via Code::Blocks IDE
 * Build       : gcc j_sum_product.c -o j_sum_product -lm
 *               (-lm links the math library on Linux/macOS)
 * Usage       : ./j_sum_product
 *
 * Example:
 *   Input   : 4  2.5  7  1.2  -3  0.5  -999
 *   Integers: 4, 7, -3        -> Sum     = 8
 *   Floats  : 2.5, 1.2, 0.5   -> Product = 1.5000
 *
 * Revision History:
 *   Version   Date              Author            Description
 *   1.0       25 October 2022   Muhammad Haruna   Initial version
 * ============================================================================
 */

#include <stdio.h>      /* Standard input/output library, needed for printf() and scanf() */
#include <math.h>       /* Math library, needed for floor() */

#define TERMINATOR (-999.0)     /* Value that ends the input series */

int main(void)          /* Program execution starts here */
{
    double number;              /* Current number entered by the user */
    long long integerSum = 0;   /* Running sum of all integer values */
    double floatProduct = 1.0;  /* Running product of all floating-point values (starts at 1) */
    int integerCount = 0;       /* Number of integers entered */
    int floatCount = 0;         /* Number of floating-point numbers entered */

    printf("Enter a series of numbers (integers or decimals).\n");
    printf("Enter -999 to finish.\n\n");

    while (1)           /* Keep reading until the terminator is entered */
    {
        printf("Enter a number: ");

        if (scanf("%lf", &number) != 1)     /* scanf() returns 1 if a number was read successfully */
        {
            printf("Invalid input. Please enter a number.\n");
            while (getchar() != '\n')       /* Discard the rest of the invalid line */
            {
            }
            continue;                       /* Ask again */
        }

        if (number == TERMINATOR)           /* Stop when -999 is entered */
        {
            break;
        }

        if (number == floor(number))        /* No fractional part, so it is an integer */
        {
            integerSum += (long long)number;
            integerCount++;
        }
        else                                /* Has a fractional part, so it is a floating-point number */
        {
            floatProduct *= number;
            floatCount++;
        }
    }

    /* Display the results */
    printf("\nResults\n");
    printf("-------\n");

    if (integerCount > 0)
    {
        printf("Sum of the %d integer(s): %lld\n", integerCount, integerSum);
    }
    else
    {
        printf("No integers were entered.\n");
    }

    if (floatCount > 0)
    {
        printf("Product of the %d floating-point number(s): %.4f\n", floatCount, floatProduct);
    }
    else
    {
        printf("No floating-point numbers were entered.\n");
    }

    return 0;           /* Tell the operating system the program ended successfully */
}