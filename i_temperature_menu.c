/*
 * ============================================================================
 * File        : i_temperature_menu.c
 * Title       : Exercise I - Menu-Driven Temperature Converter
 * Author      : Muhammad Haruna
 * Date        : October 27th 2022
 * Version     : 1.0
 * Course      : MSc Electronic and Computer Engineering
 * Module      : Introduction to C Programming (Lab Exercises)
 * Institution : University of Birmingham, Department of Electronic,
 *               Electrical and Systems Engineering
 *
 * Description : Rewrite of Exercise G as a menu-driven program. The user
 *               can choose between:
 *                   1. Celsius to Fahrenheit conversion
 *                   2. Fahrenheit to Celsius conversion
 *                   3. Exit the program
 *               Each conversion is implemented as a separate C function.
 *
 *               Formulas:
 *                   C = (5 / 9) * (F - 32)
 *                   F = (9 / 5) * C + 32
 *
 * Compiler    : GCC (MinGW) via Code::Blocks IDE
 * Build       : gcc i_temperature_menu.c -o i_temperature_menu
 * Usage       : ./i_temperature_menu
 *
 * Example:
 *   Option 1, input 100 C  -> 212.00 F
 *   Option 2, input 212 F  -> 100.00 C
 *   Option 2, input -40 F  -> -40.00 C
 *
 * Revision History:
 *   Version   Date              Author            Description
 *   1.0       27 October 2022   Muhammad Haruna   Initial version
 * ============================================================================
 */

#include <stdio.h>      /* Standard input/output library, needed for printf() and scanf() */

/* Menu option numbers */
#define OPTION_C_TO_F  1
#define OPTION_F_TO_C  2
#define OPTION_EXIT    3

/* Function prototypes */
double celsiusToFahrenheit(double celsius);
double fahrenheitToCelsius(double fahrenheit);
void   displayMenu(void);
double readTemperature(const char *prompt);
void   clearInputLine(void);

int main(void)          /* Program execution starts here */
{
    int choice;         /* Menu option chosen by the user */
    double input;       /* Temperature entered by the user */
    double result;      /* Converted temperature */

    do
    {
        displayMenu();

        if (scanf("%d", &choice) != 1)      /* Check that a number was entered */
        {
            printf("Invalid input. Please enter 1, 2 or 3.\n\n");
            clearInputLine();
            choice = 0;                     /* Force the loop to show the menu again */
            continue;
        }

        switch (choice)
        {
            case OPTION_C_TO_F:
                input  = readTemperature("Please enter your reading in degrees C   ");
                result = celsiusToFahrenheit(input);
                printf("Thank you,\n");
                printf("The temperature of your reading %.2f C is %.2f F\n\n", input, result);
                break;

            case OPTION_F_TO_C:
                input  = readTemperature("Please enter your reading in degrees F   ");
                result = fahrenheitToCelsius(input);
                printf("Thank you,\n");
                printf("The temperature of your reading %.2f F is %.2f C\n\n", input, result);
                break;

            case OPTION_EXIT:
                printf("Exiting the program. Goodbye.\n");
                break;

            default:        /* Any number other than 1, 2 or 3 */
                printf("Invalid option. Please enter 1, 2 or 3.\n\n");
                break;
        }

    } while (choice != OPTION_EXIT);    /* Repeat until the user chooses to exit */

    return 0;           /* Tell the operating system the program ended successfully */
}

/*
 * celsiusToFahrenheit
 * Converts a temperature from degrees Celsius to degrees Fahrenheit.
 */
double celsiusToFahrenheit(double celsius)
{
    return (9.0 / 5.0) * celsius + 32.0;    /* F = (9 / 5) * C + 32 */
}

/*
 * fahrenheitToCelsius
 * Converts a temperature from degrees Fahrenheit to degrees Celsius.
 * 5.0 / 9.0 is used because 5 / 9 is integer division in C and equals 0.
 */
double fahrenheitToCelsius(double fahrenheit)
{
    return (5.0 / 9.0) * (fahrenheit - 32.0);   /* C = (5 / 9) * (F - 32) */
}

/*
 * displayMenu
 * Shows the program title and the list of options.
 */
void displayMenu(void)
{
    printf("Temperature reading converting program\n");
    printf("++++++++++++++++++++++++++++++++++++++\n");
    printf("1. Celsius to Fahrenheit\n");
    printf("2. Fahrenheit to Celsius\n");
    printf("3. Exit\n");
    printf("Enter your choice: ");
}

/*
 * readTemperature
 * Prompts the user and reads a temperature value, repeating the prompt
 * until a valid number is entered.
 */
double readTemperature(const char *prompt)
{
    double value;

    printf("%s", prompt);

    while (scanf("%lf", &value) != 1)   /* Repeat until a number is read */
    {
        printf("Invalid input. Please enter a number: ");
        clearInputLine();
    }

    return value;
}

/*
 * clearInputLine
 * Discards any remaining characters on the current input line, so that
 * invalid input does not get read again.
 */
void clearInputLine(void)
{
    while (getchar() != '\n')
    {
    }
}