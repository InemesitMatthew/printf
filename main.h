#ifndef PRINTF
#define PRINTF

/*programs macros*/
#define NULL_BYTE 6
#define UINT_SIZE 32
#define BYTE 1

/*system headers*/
#include <limits.h>
#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
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
 * handle_char - handles format specifier c "%c"
 * to print character
 *
 * @character: character from the argument
 *
 * Return: BYTE which is 1 for a single character
 */
int handle_char(char character);

/**
 * handle_string - handles format specifier s "%s"
 * to print stirng
 *
 * @str_buffer: string from the argument
 *
 * Return: The length of the bytes printed otherwise
 * return NULL_BYTE which is 6 if null is passed as the argument
 */
int handle_string(char *str_buffer);

/**
 * handle_percent - handles the format specifier % "%%"
 * to print percent sign
 *
 * @character: character from the argument
 *
 * Return: BYTE which is 1 for character %
 */
int handle_percent(char character);

/**
 * handle_reverse_string - handles the format specifier r "%r"
 * to print string reverse
 *
 * @str_buffer: string from argument
 *
 * Return: The length of the bytes printed otherwise
 * return NULL_BYTE which is 6 if null is passed as the argument
 */
int handle_reverse_string(char *str_buffer);

/**
 * handle_integers - handles the format specifier d and i "%d", "%i"
 * to print integers
 *
 * @number: number from the argument
 *
 * Return: The length of the number, which consist of each digit
 */
int handle_integers(int number);

/**
 * handle_binary - handles the format specifier b "%b"
 *
 * @number: number from the argument
 *
 * Return:
 * - The length of the Printed binary
 * - 0 if the number is not unsigned int
 * - 1 if the number is equal to zero
 */
int handle_binary(int number);

/**
 * handle_unsigned_integers - handles the format specifier u "%u"
 * to print unsigned integers
 *
 * @number: unsigned integer from argument
 *
 * Return: The length of the printed unsigned int
 */
int handle_unsigned_integers(unsigned int number);

/**
 * handle_octal - handles the format specifier o "%o"
 * to print octal representation of numbers
 *
 * @number: number from the argument
 *
 * Return: The length of the printed octal number
 */
int handle_octal(int number);

/**
 * handle_lowerCase_hexadecimal - handles the format specifier x "%x"
 * to print hexadecimal representation of numbers in lower-case
 *
 * @number: number from the argument
 *
 * Return: The length of the printed hexadecimal number
 */
int handle_lowerCase_hexadecimal(int number);

/**
 * handle_upperCase_hexadecimal - handles the format specifier X "%X"
 * to print hexadecimal representation of numbers in upper-case
 *
 * @number: number from the argument
 *
 * Return: The length of the printed hexadecimal number
 */
int handle_upperCase_hexadecimal(int number);


/**
 * handle_pointer - handles the format specifier p "%p"
 * to print memory addresses
 *
 * @ptr: pointer that stores address
 *
 * Return: The length of the printed address
 */
int handle_pointer(void *ptr);

/**
 * handle_rot13 - handles the format specifier R "%R"
 * to print string in rot 13 representation
 *
 * @str: string from the argument
 *
 * Return: The length of the printed rot 13 string
 */
int handle_rot13(char *str);

#endif /* PRINTF */
