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

int _printf(const char *format, ...);

/**
 * handle_char - handles format specifier c "%c"
 * to print character
 *
 * @character: character from the argument
 *
 * Return: void (Nothing)
 */
int handle_char(char character);

/**
 * handle_string - handles format specifier s "%s"
 * to print stirng
 *
 * @str_buffer: string from the argument
 *
 * Return: void (Nothing)
 */
int handle_string(char *str_buffer);

/**
 * handle_percent - handles the format specifier % "%%"
 * to print percent sign
 *
 * @character: character from the argument
 *
 * Return: void (Nothing)
 */
int handle_percent(char character);

/**
 * handle_reverse_string - handles the format specifier r "%r"
 * to print string reverse
 *
 * @str_buffer: string from argument
 *
 * Return: void (Nothing)
 */
int handle_reverse_string(char *str_buffer);

/**
 * handle_integers - handles the format specifier d and i "%d", "%i"
 * to print integers
 *
 * @number: number from the argument
 *
 * Return: void (Nothing)
 */
int handle_integers(int number);

/**
 * handle_binary - handle the format specifier b "%b"
 *
 * @number: number from the argument
 * printed int bytes
 *
 * Return: void (Nothing);
 */
int handle_binary(int number);

/**
 * handle_unsigned_integers - handles the format specifier u "%u"
 * to print unsigned integers
 *
 * @number: unsigned integer from argument
 *
 * Return: void (Nothing)
 */
int handle_unsigned_integers(unsigned int number);

#endif /* PRINTF */
