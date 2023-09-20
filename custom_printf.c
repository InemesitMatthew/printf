#include "main.h"
#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>

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
    char buffer[1024]; /* Local buffer for write */
    char *str_buffer = buffer; /* Pointer to buffer for string handling */

    int i;
    char character; /* Declare character variable */
    int len; /* Declare len variable */
    char len_str[UINT_SIZE]; /* Buffer to store integer as string, size of 32*/

    va_start(args, format); /* Initialize the va_list */

    while (format && *format)
    {
        if (*format == '%')
        {
            format++; /* Move past '%' */

            /* Handle format specifiers */
            switch (*format)
            {
                case 'b':
                    /* Handle binary conversion */
                    {
                        unsigned int num = va_arg(args, unsigned int);
                        int binary[UINT_SIZE]; /* Array to store binary representation */
                        int index = 0;

                        if (num == 0)
                        {
                            write(1, "0", 1);
                            count++;
                        }
                        else
                        {
                            /* Calculate the binary representation */
                            while (num > 0)
                            {
                                binary[index++] = num % 2;
                                num /= 2;
                            }
                            /* Print the binary representation in reverse order */
                            for (i = index - 1; i >= 0; i--)
                            {
                                /* Convert to character */
                                char digit = binary[i] + '0';
                                write(1, &digit, 1);
                                count++;
                            }
                        }
                    }
                    break;

                case 'c':
                    /* Handle character conversion */
                    character = va_arg(args, int);
                    write(1, &character, 1);
                    count++;
                    break;

                case 'd':
                case 'i':
                    /* Handle decimal and integer conversion */
                    {
                        int num = va_arg(args, int);
                        char num_str[UINT_SIZE]; /* Buffer to store integer as string */
                        int len = snprintf(num_str, sizeof(num_str), "%d", num);

                        if (len > 0)
                        {
                            write(1, num_str, len);
                            count += len;
                        }
                    }
                    break;

                case 'u':
                    /* Handle unsigned integer conversion */
                    {
                        unsigned int num = va_arg(args, unsigned int);
                        char num_str[UINT_SIZE]; /* Buffer to store unsigned integer as string */
                        int len = snprintf(num_str, sizeof(num_str), "%u", num);

                        if (len > 0)
                        {
                            write(1, num_str, len);
                            count += len;
                        }
                    }
                    break;

                case 'o':
                    /* Handle octal conversion */
                    {
                        unsigned int num = va_arg(args, unsigned int);
                        char num_str[UINT_SIZE]; /* Buffer to store octal representation */
                        int len = snprintf(num_str, sizeof(num_str), "%o", num);

                        if (len > 0)
                        {
                            write(1, num_str, len);
                            count += len;
                        }
                    }
                    break;

                case 'x':
                    /* Handle lowercase hexadecimal conversion */
                    {
                        unsigned int num = va_arg(args, unsigned int);
                        char num_str[UINT_SIZE]; /* Buffer to store hexadecimal representation */
                        int len = snprintf(num_str, sizeof(num_str), "%x", num);

                        if (len > 0)
                        {
                            write(1, num_str, len);
                            count += len;
                        }
                    }
                    break;

                case 'X':
                    /* Handle uppercase hexadecimal conversion */
                    {
                        unsigned int num = va_arg(args, unsigned int);
                        char num_str[UINT_SIZE]; /* Buffer to store uppercase hexadecimal representation */
                        int len = snprintf(num_str, sizeof(num_str), "%X", num);

                        if (len > 0)
                        {
                            write(1, num_str, len);
                            count += len;
                        }
                    }
                    break;

                case 'p':
                    /* Handle pointer conversion */
                    {
                        void *ptr = va_arg(args, void *);
                        char ptr_str[UINT_SIZE]; /* Buffer to store pointer as string */
                        int len = snprintf(ptr_str, sizeof(ptr_str), "%p", ptr);

                        if (len > 0)
                        {
                            write(1, ptr_str, len);
                            count += len;
                        }
                    }
                    break;

                case 's':
                case 'S':
                    /* Handle string conversion */
                    str_buffer = va_arg(args, char *);
                    if (str_buffer != NULL)
                    {
                        while (*str_buffer)
                        {
                            write(1, str_buffer, 1);
                            str_buffer++;
                            count++;
                        }
                    }
                    else
                    {
                        write(1, "(null)", 6);
                        count += 6;
                    }
                    break;

                case 'r':
                    /* Handle reversed string conversion */
                    {
                        char *str = va_arg(args, char *);
                        int len = 0;

                        if (str)
                        {
                            while (str[len])
                                len++;

                            for (i = len - 1; i >= 0; i--)
                            {
                                write(1, &str[i], 1);
                                count++;
                            }
                        }
                    }
                    break;

                case 'R':
                    /* Handle rot13'ed string conversion */
                    {
                        char *str = va_arg(args, char *);
                        char rot13_table[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";
                        int len = 0;

                        if (str)
                        {
                            while (str[len])
                            {
                                if ((str[len] >= 'A' && str[len] <= 'Z') || (str[len] >= 'a' && str[len] <= 'z'))
                                {
                                    write(1, &(rot13_table[str[len] - 'A']), 1);
                                    count++;
                                }
                                else
                                {
                                    write(1, &(str[len]), 1);
                                    count++;
                                }
                                len++;
                            }
                        }
                    }
                    break;

                case 'n':
                    len = va_arg(args, int);
                    int len_len = snprintf(len_str, sizeof(len_str), "%d", len);
                    if (len_len > 0)
                    {
                        write(1, len_str, len_len);
                        count += len_len;
                    }
                    break;

                default:
                    /* Handle unsupported format specifier */
                    write(1, "%", 1);
                    write(1, format, 1);
                    count += 2;
                    break;
            }
        }
        else
        {
            write(1, format, 1);
            count++;
        }
        format++; /* Move to the next character in the format string */
    }

    va_end(args); /* Clean up the va_list */

    return count;
}
