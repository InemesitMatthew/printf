#ifndef PRINTF
#define PRINTF

/*programs macros*/
#define NULL_BYTE 6
#define UINT_SIZE 32
#define BYTE 1

/*system headers*/
#include <limits.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

/**
 * _printf - format and print data
 *
 * @format: formated string
 * ...: variable number of arguments
 *
 * Return: The total count or length of data printed to stdout
 */
int _printf(const char *format, ...);

/**
 * handle_format_string - Processes a format string, prints it out, replacing
 *                        format specifiers with values from the argument list.
 *
 * @format: The format string, may contain zero or more format specifiers.
 * @args: A va_list containing arguments to replace the format specifiers.
 *
 * Return: The number of characters printed, excluding the null byte.
 */
int handle_format_string(const char *format, va_list args);
/**
 * handle_char - handles format specifier c "%c"
 * to print character
 *
 * @args: A va_list containing arguments to replace the format specifiers.
 *
 * Return: BYTE which is 1 for a single character
 */
int handle_char(va_list args);

/**
 * handle_string - handles format specifier s "%s"
 * to print stirng
 *
 * @args: A va_list containing arguments to replace the format specifiers.
 *
 * Return: The length of the bytes printed otherwise
 * return NULL_BYTE which is 6 if null is passed as the argument
 */
int handle_string(va_list args);

/**
 * handle_percent - handles the format specifier % "%%"
 * to print percent sign
 *
 * Return: BYTE which is 1 for character '%'
 */
int handle_percent(va_list args);

/**
 * handle_reverse_string - handles the format specifier r "%r"
 * to print string reverse
 *
 * @args: A va_list containing arguments to replace the format specifiers.*
 *
 * Return: The length of the bytes printed otherwise
 * return NULL_BYTE which is 6 if null is passed as the argument
 */
int handle_reverse_string(va_list args);

/**
 * handle_integers - handles the format specifier d and i "%d", "%i"
 * to print integers
 *
 * @args: A va_list containing arguments to replace the format specifiers.
 *
 * Return: The length of the number, which consist of each digit
 */
int handle_integers(va_list args);

/**
 * handle_binary - handles the format specifier b "%b"
 *
 * @args: A va_list containing arguments to replace the format specifiers.
 *
 * Return:
 * - The length of the Printed binary
 * - 0 if the number is not unsigned int
 * - 1 if the number is equal to zero
 */
int handle_binary(va_list args);

/**
 * handle_unsigned_integers - handles the format specifier u "%u"
 * to print unsigned integers
 *
 * @args: A va_list containing arguments to replace the format specifiers.
 *
 * Return: The length of the printed unsigned int
 */
int handle_unsigned_integers(va_list args);

/**
 * handle_octal - handles the format specifier o "%o"
 * to print octal representation of numbers
 *
 * @args: A va_list containing arguments to replace the format specifiers.
 *
 * Return: The length of the printed octal number
 */
int handle_octal(va_list args);

/**
 * handle_lowerCase_hexadecimal - handles the format specifier x "%x"
 * to print hexadecimal representation of numbers in lower-case
 *
 * @args: A va_list containing arguments to replace the format specifiers.
 *
 * Return: The length of the printed hexadecimal number
 */
int handle_lowerCase_hexadecimal(va_list args);

/**
 * handle_upperCase_hexadecimal - handles the format specifier X "%X"
 * to print hexadecimal representation of numbers in upper-case
 *
 * @args: A va_list containing arguments to replace the format specifiers.
 *
 * Return: The length of the printed hexadecimal number
 */
int handle_upperCase_hexadecimal(va_list args);

/**
 * handle_pointer - handles the format specifier p "%p"
 * to print memory addresses
 *
 * @args: A va_list containing arguments to replace the format specifiers.
 *
 * Return: The length of the printed address
 */
int handle_pointer(va_list args);

/**
 * handle_rot13 - handles the format specifier R "%R"
 * to print string in rot 13 representation
 *
 * @args: A va_list containing arguments to replace the format specifiers.
 *
 * Return: The length of the printed rot 13 string
 */
int handle_rot13(va_list args);

/**
 * handle_uppeCase_S - handle the specifier S "%S"
 *
 * @args: A va_list containing arguments to replace the format specifiers.
 *
 * Return: Length of bytes printed out
 */
int handle_upperCase_S(va_list args);

/**
 * struct specifierHandlers - Maps format specifiers to corresponding handler
 * function
 *
 * @specifier: The format specifier character, e.g., 'c' for character.
 * @handler:   A pointer to the function that handles the specified format.
 *
 * Description:
 * - This structure defines a mapping between format specifiers and the
 *   functions responsible for processing them in the printf-style format.
 * - It is used to determine the appropriate handler function for each
 *   specifier during string formatting.
 */
extern struct specifierHandlers
{
	char specifier;
	int (*handler)(va_list args);
} specifierHandlers[];

#endif /* PRINTF */
