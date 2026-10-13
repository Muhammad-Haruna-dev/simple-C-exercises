/*
 * ============================================================================
 * File        : k_long_words.c
 * Title       : Exercise K - Extracting Long Words from a Text File
 * Author      : Muhammad Haruna
 * Date        : October 26th 2022
 * Version     : 1.0
 * Course      : MSc Electronic and Computer Engineering
 * Module      : Introduction to C Programming (Lab Exercises)
 * Institution : University of Birmingham, Department of Electronic,
 *               Electrical and Systems Engineering
 *
 * Description : Reads a page of text from a text file one word at a time.
 *               Any word longer than 9 characters is converted to
 *               lower-case and stored in an array of strings. The stored
 *               words are displayed at the end of the program.
 *
 *               The file name can be given on the command line; if not,
 *               the program reads from "input.txt" by default.
 *
 * Compiler    : GCC (MinGW) via Code::Blocks IDE
 * Build       : gcc k_long_words.c -o k_long_words
 * Usage       : ./k_long_words              (reads input.txt)
 *               ./k_long_words mytext.txt   (reads mytext.txt)
 *
 * Example:
 *   input.txt : The UNIVERSITY of Birmingham offers Electronic Engineering
 *               programmes with INTERNATIONAL collaboration.
 *   Output    : 1: university
 *               2: birmingham
 *               3: electronic
 *               4: engineering
 *               5: programmes
 *               6: international
 *               7: collaboration.
 *
 * Revision History:
 *   Version   Date              Author            Description
 *   1.0       26 October 2022   Muhammad Haruna   Initial version
 * ============================================================================
 */

#include <stdio.h>      /* Standard input/output library, needed for printf(), fopen(), fscanf() */
#include <string.h>     /* String library, needed for strlen() and strcpy() */
#include <ctype.h>      /* Character library, needed for tolower() */

#define MAX_WORDS     500   /* Maximum number of long words that can be stored */
#define MAX_WORD_LEN  100   /* Maximum length of a single word, including the '\0' terminator */
#define MIN_LENGTH    9     /* Words longer than this are stored */

int main(int argc, char *argv[])    /* argc/argv give access to command-line arguments */
{
    const char *fileName = "input.txt";         /* Default file name */
    FILE *file;                                 /* Pointer to the opened text file */
    char word[MAX_WORD_LEN];                    /* Buffer for the word currently being read */
    char longWords[MAX_WORDS][MAX_WORD_LEN];    /* Array of strings holding the long words */
    int wordCount = 0;                          /* Number of long words stored so far */
    int i;                                      /* Loop counter */

    if (argc > 1)                   /* Use the file name from the command line, if one was given */
    {
        fileName = argv[1];
    }

    file = fopen(fileName, "r");    /* Open the file for reading */
    if (file == NULL)               /* fopen() returns NULL if the file could not be opened */
    {
        printf("Error: could not open file \"%s\".\n", fileName);
        return 1;                   /* Non-zero return value signals an error */
    }

    /* Read one word at a time; %99s stops at whitespace and prevents buffer overflow */
    while (fscanf(file, "%99s", word) == 1)
    {
        if (strlen(word) > MIN_LENGTH)          /* Only keep words longer than 9 characters */
        {
            if (wordCount >= MAX_WORDS)         /* Stop if the array is full */
            {
                printf("Warning: storage full, remaining words ignored.\n");
                break;
            }

            /* Convert each character of the word to lower-case */
            for (i = 0; word[i] != '\0'; i++)
            {
                word[i] = (char)tolower((unsigned char)word[i]);
            }

            strcpy(longWords[wordCount], word); /* Store the word in the array */
            wordCount++;
        }
    }

    fclose(file);       /* Close the file once reading is finished */

    /* Display the stored words */
    printf("Words longer than %d characters found in \"%s\": %d\n\n",
           MIN_LENGTH, fileName, wordCount);

    for (i = 0; i < wordCount; i++)
    {
        printf("%d: %s\n", i + 1, longWords[i]);
    }

    return 0;           /* Tell the operating system the program ended successfully */
}