/*
 * ============================================================================
 * File        : e_ohms_law.c
 * Title       : Exercise E - Voltage Across a Resistor (Ohm's Law)
 * Author      : Muhammad Haruna
 * Date        : October 24th 2022
 * Version     : 1.0
 * Course      : MSc Electronic and Computer Engineering
 * Module      : Introduction to C Programming (Lab Exercises)
 * Institution : University of Birmingham, Department of Electronic,
 *               Electrical and Systems Engineering
 *
 * Description : Uses Ohm's Law (V = I * R) to calculate the voltage across
 *               a resistor.
 *               Part 1 - uses fixed values: R = 2 kOhm, I = 0.05 A.
 *               Part 2 - prompts the user to enter their own values for
 *                        resistance and current.
 *
 * Compiler    : GCC (MinGW) via Code::Blocks IDE
 * Build       : gcc e_ohms_law.c -o e_ohms_law
 * Usage       : ./e_ohms_law
 *
 * Expected Output (Part 1):
 *   Voltage across a 2000.00 Ohm resistor carrying 0.0500 A is 100.00 V
 *
 * Revision History:
 *   Version   Date              Author            Description
 *   1.0       24 October 2022   Muhammad Haruna   Initial version
 * ============================================================================
 */

#include <stdio.h>      /* Standard input/output library, needed for printf() and scanf() */

int main(void)          /* Program execution starts here */
{
    double resistance;  /* Resistance in Ohms */
    double current;     /* Current in Amps */
    double voltage;     /* Calculated voltage in Volts */

    /* ---------------- Part 1: fixed values ---------------- */
    resistance = 2000.0;        /* 2 kOhm resistor */
    current    = 0.05;          /* 0.05 A current */

    voltage = current * resistance;     /* Ohm's Law: V = I * R */

    printf("Part 1: Fixed values\n");
    printf("Voltage across a %.2f Ohm resistor carrying %.4f A is %.2f V\n\n",
           resistance, current, voltage);

    /* ---------------- Part 2: user input ---------------- */
    printf("Part 2: Enter your own values\n");

    printf("Enter resistance in Ohms: ");
    scanf("%lf", &resistance);  /* %lf is the format specifier for reading a double */

    printf("Enter current in Amps: ");
    scanf("%lf", &current);

    voltage = current * resistance;     /* Ohm's Law: V = I * R */

    printf("Voltage across a %.2f Ohm resistor carrying %.4f A is %.2f V\n",
           resistance, current, voltage);

    return 0;           /* Tell the operating system the program ended successfully */
}