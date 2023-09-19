# Task 0: Custom `_printf` Function README

## Introduction

Task 0 involves creating a custom `_printf` function, a simplified version of the standard `printf` function in C. The custom function is designed to allow you to format and print text to the screen.

## Usage

To use the custom `_printf` function for Task 0, follow these steps:

1. Include the `main.h` header file in your code.

   ```c
   #include "main.h"
   ```

2. Call `_printf` with a format string and any additional arguments you want to print. For example:

   ```c
   _printf("Hello, %s!\n", "world");
   ```

## Supported Format Specifiers

The `_printf` function for Task 0 supports the following format specifiers:

- `%c`: Prints a single character.
- `%s`: Prints a string of characters.
- `%%`: Prints a literal percent sign.

## Example

Here's an example of how to use `_printf` for Task 0:

```c
_printf("Hello, %s!\n", "world");
```

This code will print: "Hello, world!"

## Handling Special Cases

- `%s` handles NULL strings gracefully and prints "(null)" if the string is NULL.
- The function does not handle other formatting options like field width or precision.

## Return Value

The `_printf` function for Task 0 returns the number of characters printed (excluding the null byte used to end the output to strings).

## Procedure and Thought Process

The custom `_printf` function for Task 0 was developed with simplicity in mind. Here's the basic procedure and thought process used to create it:

1. Initialize a `va_list` to handle variable arguments and start processing the format string.
2. Loop through the format string character by character.
3. When encountering a '%' character, check the next character to determine the format specifier.
4. For each format specifier, handle it appropriately (e.g., print a character, string, or percent sign) using the `write` function.
5. Keep track of the count of characters printed.
6. For strings, handle the special case of NULL strings.
7. Continue processing the format string until the end.
8. Clean up the `va_list` with `va_end`.
9. Return the count of characters printed.

The goal was to create a straightforward and minimalistic version of `printf` that provides basic functionality without the complexity of full formatting options and buffer management.

## Complete Code

Here's the complete code implementation of the custom `_printf` function for Task 0:

```c
#include "main.h"
#include <stdarg.h>
#include <unistd.h> /* For write */

/**
 * _printf - Custom printf function
 * @format: The format string
 * @...: Variable number of arguments
 *
 * Return: The number of characters printed (excluding the null byte).
 */
int _printf(const char *format, ...)
{
    va_list args;
    int count = 0; /* Initialize the character count */
    int character; /* Variable to store a character from va_arg */

    va_start(args, format); /* Initialize the va_list */

    while (format && *format)
    {
        if (*format  == '%')
        {
            format++; /* Move past '%' */

            /* Handle format specifiers */
            if (*format == 'c')
            {
                character = va_arg(args, int);
                write(1, &character, 1); /* Print character */
                count++;
            }
            else if (*format == 's')
            {
                char *str = va_arg(args, char *);
                if (str)
                {
                    while (*str)
                    {
                        write(1, str, 1);
                        /**
                         * Print each character
                         * of the string
                         */
                        str++;
                        count++;
                    }
                }
                else
                {
                    /* Handle NULL string */
                    write(1, "(null)", 6);
                    count += 6;
                }
            }
            else if (*format == '%')
            {
                write(1, "%", 1);
                /**
                 * Print percent sign
                 */
                count++;
            }
        }
        else
        {
            write(1, format, 1);
            /**
             * Print non-format specifier character
             */
            count++;
        }
        format++; /* Move to the next characters in the format string */
    }

    va_end(args); /* Clean up the va_list */

    return count;
}
```

---
