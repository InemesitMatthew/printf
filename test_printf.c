#include "main.h"

int main(void)
{
    int num = 42;
    unsigned int unum = 12345;
    char *str = "Hello, World!";
    char *rev_str = "gnirts desrever";
    char *rot13_str = "EBG13 vf n yvfg!";
    void *ptr = (void *)0x12345678;

    _printf("Testing format specifiers:\n");
    _printf("Decimal: %d\n", num);
    _printf("Unsigned Decimal: %u\n", unum);
    _printf("Octal: %o\n", num);
    _printf("Hexadecimal (lowercase): %x\n", num);
    _printf("Hexadecimal (uppercase): %X\n", num);
    _printf("Binary: %b\n", num);
    _printf("Pointer: %p\n", ptr);
    _printf("String: %S\n", str);
    _printf("Reversed String: %r\n", rev_str);
    _printf("Rot13 String: %R\n", rot13_str);

    return (0);
}
