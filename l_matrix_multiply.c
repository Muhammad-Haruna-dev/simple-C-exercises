/*
 * ============================================================================
 * File        : l_matrix_multiply.c
 * Title       : Exercise L - Multiplying Two Floating-Point Matrices
 * Author      : Muhammad Haruna
 * Date        : October 26th 2022
 * Version     : 1.0
 * Course      : MSc Electronic and Computer Engineering
 * Module      : Introduction to C Programming (Lab Exercises)
 * Institution : University of Birmingham, Department of Electronic,
 *               Electrical and Systems Engineering
 *
 * Description : Reads two floating-point matrices whose dimensions are
 *               chosen by the user at run-time, multiplies them together,
 *               and displays the result.
 *
 *               Matrix A is (rowsA x colsA) and matrix B is (rowsB x colsB).
 *               Multiplication is only legal when colsA == rowsB, and the
 *               result C is (rowsA x colsB), where:
 *                   C[i][j] = sum over k of A[i][k] * B[k][j]
 *
 *               Memory for each matrix is allocated dynamically with
 *               malloc(), since the sizes are not known until run-time.
 *               Each matrix is stored as a single block of memory, with
 *               element (row, col) at index row * cols + col.
 *
 * Compiler    : GCC (MinGW) via Code::Blocks IDE
 * Build       : gcc l_matrix_multiply.c -o l_matrix_multiply
 * Usage       : ./l_matrix_multiply
 *
 * Example:
 *   A (2 x 3) = | 1  2  3 |     B (3 x 2) = |  7   8 |
 *               | 4  5  6 |                 |  9  10 |
 *                                           | 11  12 |
 *
 *   C = A x B (2 x 2) = |  58   64 |
 *                       | 139  154 |
 *
 * Revision History:
 *   Version   Date              Author            Description
 *   1.0       26 October 2022   Muhammad Haruna   Initial version
 * ============================================================================
 */

#include <stdio.h>      /* Standard input/output library, needed for printf() and scanf() */
#include <stdlib.h>     /* Standard library, needed for malloc() and free() */

/* Function prototypes */
int     readPositiveInt(const char *prompt);
double *createMatrix(int rows, int cols);
void    readMatrix(const char *name, double *matrix, int rows, int cols);
void    multiplyMatrices(const double *a, const double *b, double *c,
                         int rowsA, int colsA, int colsB);
void    printMatrix(const char *name, const double *matrix, int rows, int cols);

int main(void)          /* Program execution starts here */
{
    int rowsA, colsA;   /* Dimensions of matrix A */
    int rowsB, colsB;   /* Dimensions of matrix B */
    double *a, *b, *c;  /* Pointers to matrices A, B and the result C */

    printf("Matrix multiplication: C = A x B\n\n");

    /* Read the dimensions of matrix A */
    rowsA = readPositiveInt("Enter number of rows for matrix A: ");
    colsA = readPositiveInt("Enter number of columns for matrix A: ");

    /* Read the dimensions of matrix B, repeating until they are legal for multiplication */
    while (1)
    {
        rowsB = readPositiveInt("Enter number of rows for matrix B: ");
        colsB = readPositiveInt("Enter number of columns for matrix B: ");

        if (rowsB == colsA)     /* Columns of A must equal rows of B */
        {
            break;
        }
        printf("Error: rows of B (%d) must equal columns of A (%d). Try again.\n",
               rowsB, colsA);
    }

    /* Allocate memory for the three matrices */
    a = createMatrix(rowsA, colsA);
    b = createMatrix(rowsB, colsB);
    c = createMatrix(rowsA, colsB);

    if (a == NULL || b == NULL || c == NULL)    /* malloc() returns NULL if memory is unavailable */
    {
        printf("Error: not enough memory for the matrices.\n");
        free(a);        /* free() is safe to call on NULL */
        free(b);
        free(c);
        return 1;       /* Non-zero return value signals an error */
    }

    /* Read the matrix elements from the keyboard */
    readMatrix("A", a, rowsA, colsA);
    readMatrix("B", b, rowsB, colsB);

    /* Multiply and display the matrices */
    multiplyMatrices(a, b, c, rowsA, colsA, colsB);

    printMatrix("A", a, rowsA, colsA);
    printMatrix("B", b, rowsB, colsB);
    printMatrix("C = A x B", c, rowsA, colsB);

    /* Release the allocated memory */
    free(a);
    free(b);
    free(c);

    return 0;           /* Tell the operating system the program ended successfully */
}

/*
 * readPositiveInt
 * Prompts the user and reads an integer greater than zero, repeating
 * the prompt until a valid value is entered.
 */
int readPositiveInt(const char *prompt)
{
    int value;

    while (1)
    {
        printf("%s", prompt);

        if (scanf("%d", &value) == 1 && value > 0)  /* Valid positive integer read */
        {
            return value;
        }

        printf("Invalid input. Please enter a whole number greater than zero.\n");
        while (getchar() != '\n')   /* Discard the rest of the invalid line */
        {
        }
    }
}

/*
 * createMatrix
 * Allocates memory for a matrix of the given size.
 * Returns a pointer to the memory, or NULL if allocation fails.
 */
double *createMatrix(int rows, int cols)
{
    return (double *)malloc((size_t)rows * (size_t)cols * sizeof(double));
}

/*
 * readMatrix
 * Prompts the user to enter every element of the matrix, row by row.
 */
void readMatrix(const char *name, double *matrix, int rows, int cols)
{
    int row, col;

    printf("\nEnter the elements of matrix %s (%d x %d):\n", name, rows, cols);

    for (row = 0; row < rows; row++)
    {
        for (col = 0; col < cols; col++)
        {
            printf("%s[%d][%d] = ", name, row + 1, col + 1);   /* Show 1-based positions to the user */

            while (scanf("%lf", &matrix[row * cols + col]) != 1)    /* Repeat until a number is read */
            {
                printf("Invalid input. Please enter a number: ");
                while (getchar() != '\n')
                {
                }
            }
        }
    }
}

/*
 * multiplyMatrices
 * Calculates C = A x B, where A is (rowsA x colsA) and B is (colsA x colsB).
 * Each element C[i][j] is the sum of A[i][k] * B[k][j] for every k.
 */
void multiplyMatrices(const double *a, const double *b, double *c,
                      int rowsA, int colsA, int colsB)
{
    int i, j, k;
    double sum;

    for (i = 0; i < rowsA; i++)             /* Each row of A */
    {
        for (j = 0; j < colsB; j++)         /* Each column of B */
        {
            sum = 0.0;
            for (k = 0; k < colsA; k++)     /* Multiply matching elements and add them up */
            {
                sum += a[i * colsA + k] * b[k * colsB + j];
            }
            c[i * colsB + j] = sum;
        }
    }
}

/*
 * printMatrix
 * Displays a matrix with its name and dimensions.
 */
void printMatrix(const char *name, const double *matrix, int rows, int cols)
{
    int row, col;

    printf("\nMatrix %s (%d x %d):\n", name, rows, cols);

    for (row = 0; row < rows; row++)
    {
        for (col = 0; col < cols; col++)
        {
            printf("%10.2f", matrix[row * cols + col]);    /* Each value in a 10-character column */
        }
        printf("\n");
    }
}