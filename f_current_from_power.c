/*
 * ============================================================================
 * File        : f_current_from_power.c
 * Title       : Exercise F - Current from Power Dissipation and Resistance
 * Author      : Muhammad Haruna
 * Date        : October 24th 2022
 * Version     : 1.0
 * Course      : MSc Electronic and Computer Engineering
 * Module      : Introduction to C Programming (Lab Exercises)
 * Institution : University of Birmingham, Department of Electronic,
 *               Electrical and Systems Engineering
 *
 * Description : Calculates the current flowing in a resistor from the power
 *               dissipated and the resistance, using I = sqrt(P / R).
 *               The square root is computed with sqrt() from the math
 *               library. Inputs are validated before the calculation.
 *
 * Compiler    : GCC (MinGW) via Code::Blocks IDE
 * Build       : gcc f_current_from_power.c -o f_current_from_power -lm
 *               (-lm links the math library on Linux/macOS)
 * Usage       : ./f_current_from_power
 *
 * Observations (without input validation):
 *   - R = 0      : P / R is a division by zero. With doubles this gives
 *                  "inf" (infinity) when P > 0, or "nan" when P = 0.
 *   - P or R < 0 : P / R becomes negative, and the square root of a
 *                  negative number is undefined, so sqrt() returns "nan"
 *                  (Not a Number).
 *   - Prevention : check that R is greater than zero and P is zero or
 *                  greater before calculating, and reject invalid input
 *                  with an error message (implemented below).
 *
 * Revision History:
 *   Version   Date              Author            Description
 *   1.0       24 October 2022   Muhammad Haruna   Initial version
 * ============================================================================
 */

#include <stdio.h>      /* Standard input/output library, needed for printf() and scanf() */
#include <math.h>       /* Math library, needed for sqrt() */

int main(void)          /* Program execution starts here */
{
    double power;       /* Power dissipated in Watts */
    double resistance;  /* Resistance in Ohms */
    double current;     /* Calculated current in Amps */

    printf("Current in a resistor: I = sqrt(P / R)\n");

    printf("Enter power dissipation in Watts: ");
    scanf("%lf", &power);

    printf("Enter resistance in Ohms: ");
    scanf("%lf", &resistance);

    /* Validate inputs to avoid division by zero and square roots of negative numbers */
    if (resistance <= 0.0)
    {
        printf("Error: resistance must be greater than zero.\n");
        return 1;       /* Non-zero return value signals that the program ended with an error */
    }

    if (power < 0.0)
    {
        printf("Error: power cannot be negative.\n");
        return 1;
    }

    current = sqrt(power / resistance);     /* I = sqrt(P / R) */

    printf("Current flowing in the resistor is %.4f A\n", current);

    return 0;           /* Tell the operating system the program ended successfully */
}