# simple-C-exercises
C Programming Exercises 

# Introduction to C Programming – Lab Exercises

Solutions to the **MSc Lab Exercises – Introduction to C Programming** from the Department of Electronic, Electrical and Systems Engineering, University of Birmingham.

These exercises cover the fundamentals of C: output formatting, arithmetic, keyboard input, the maths library, loops, functions, file handling, strings and dynamic arrays.

- **Author:** Muhammad Haruna
- **Programme:** MSc Electronic and Computer Engineering, University of Birmingham
- **Date:** October 2022
- **Language:** C (C99)

---

## Exercises

| Exercise | File | Description | Status |
|---|---|---|---|
| A | `a_hello.c` | Print "Hello World" to the screen | ✅ Done |
| B | `b_two_lines.c` | Display output on two separate lines | ⏳ |
| C | `c_expression.c` | Calculate `x = (a + b) - (c + d)` with fixed values | ⏳ |
| D | `d_expression_input.c` | Same as C, with values entered via `scanf()` | ⏳ |
| E | `e_ohms_law.c` | Voltage across a resistor (V = I × R), fixed and user input | ⏳ |
| F | `f_current_from_power.c` | Current from power and resistance, `I = √(P / R)`, with input validation | ⏳ |
| G | `g_fahrenheit_to_celsius.c` | Fahrenheit to Celsius converter | ⏳ |
| H | `h_even_odd.c` | Repeatedly classify numbers as Even/Odd until out of range (0–999) | ⏳ |
| I | `i_temperature_menu.c` | Menu-driven C↔F converter using functions | ⏳ |
| J | `j_sum_product.c` | Sum of integers and product of floats in a series ending with -999 | ⏳ |
| K | `k_long_words.c` | Read words from a text file, lower-case and store words longer than 9 characters | ⏳ |
| L | `l_matrix_multiply.c` | Multiply two user-sized floating-point matrices | ⏳ |

---

## Building and Running

The programs were originally written in **Code::Blocks** with the GCC (MinGW) compiler, but any standard C compiler will work.

Compile a single exercise with GCC:

```bash
gcc a_hello.c -o a_hello
./a_hello
```

Exercises that use the maths library (e.g. `sqrt()` in Exercise F) need the `-lm` flag on Linux/macOS:

```bash
gcc f_current_from_power.c -o f_current_from_power -lm
```

On Windows, run the compiled program with:

```bash
a_hello.exe
```

---

## Skills Covered

- Program structure, `#include` directives and `main()`
- Formatted output with `printf()` and escape sequences
- Integer and floating-point arithmetic
- Keyboard input with `scanf()`
- Using the maths library (`math.h`)
- Input validation and error handling
- Loops and conditional statements
- Writing and calling user-defined functions
- File input and string manipulation
- Arrays, 2D arrays and dynamic memory allocation

---

## Notes

These exercises were unassessed practice tasks set during supervised lab sessions. The code here is my own work, rewritten and documented for this repository.
