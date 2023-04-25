#include "main.h"
/**
 * handle_prt - it prints arguments acccording to types.
 * @format: Formatted string in which to print the arguments.
 * @parameters: arguments passed.
 * @ind: ind
 * @bufferchar: Buffer array to handle print.
 * @flags: finds active flags
 * @width: gets the width of char
 * @precision: finds the precision specification
 * @size: Sizs of the specifiers
 * Return: it returns one or two
 */
int handle_print(const char *format, int *ind, va_list parameters, char bufferchar[],
		int flags, int width, int precision, int size)
{
	int i = 0, unknown_len = 0, prints_chars = -1;

	fmt_t fmt_types[] = {
		{'c', print_characters}, {'s', print_str}, {'%', print_pct},
		{'i', print_int}, {'d', print_int}, {'b', print_binary},
		{'u', print_unsigned_int}, {'o', print_octal}, {'x', p_hexadecimal},
		{'X', print_hexa_upp}, {'p', p_pointer}, {'S', p_non_print},
		{'r', p_reverse}, {'R', p_rot13str}, {'\0', NULL}
	};

	while (fmt_types[i].fmt != '\0')
	{
		if (format[*ind] == fmt_types[i].fmt)
		{
			return fmt_types[i].fn(parameters, bufferchar, flags, width, precision, size);
		}
		i++;
	}

	if (fmt_types[i].fmt == '\0')
	{
		if (format[*ind] == '\0')
		{
			return (-1);
		}

		unknown_len += write(1, "%%", 1);

		if (format[*ind - 1] == ' ')
		{
			unknown_len += write(1, " ", 1);
		}
		else if (width)
		{
			--(*ind);
			while (format[*ind] != ' ' && format[*ind] != '%')
			{
				--(*ind);
			}
			if (format[*ind] == ' ')
			{
				--(*ind);
			}
			return (1);
		}

		unknown_len += write(1, &format[*ind], 1);
		return (unknown_len);
	}

	return (prints_chars);
}
