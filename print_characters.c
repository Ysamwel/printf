#include "main.h"

/**
 * print_character - it prints a character
 * @parameters:arguments
 * @bufferchar: handles the buffer array
 * @flags:  finds active flags
 * @width: the width of the character
 * @precision: specification
 * @size: Size of the specifiers
 * Return: characters printed
 */
int print_characters(va_list parameters, char bufferchar[],
		int flags, int width, int precision, int size)
{
	char c = va_arg(parameters, int);

	return (handle_write_char(c, bufferchar, flags, width, precision, size));
}
