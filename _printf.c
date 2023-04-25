#include "main.h"

void print_buffer(char bufferchar[], int *buff_int);

/**
 * _printf - Printf function
 * @format: format
 * Return: printed character
 */
int _printf(const char *format, ...)
{
	int i = 0, printout = 0, printout_chars = 0;
	int flags, width, precision, size, buff_int = 0;
	va_list parameters;
	char bufferchar[BUFF_SIZE];

	if (format == NULL)
		return (-1);

	va_start(parameters, format);

	while (format[i] != '\0')
	{
		if (format[i] != '%')
		{
			bufferchar[buff_int++] = format[i];
			if (buff_int == BUFF_SIZE)
				print_buffer(bufferchar, &buff_int);
			printout_chars++;
		}
		else
		{
			print_buffer(bufferchar, &buff_int);
			flags = fetch_flags(format, &i);
			width = fetch_width(format, &i, parameters);
			precision = fetch_precision(format, &i, parameters);
			size = get_size(format, &i);
			++i;
			printout = handle_print(format, &i, parameters, bufferchar,
					flags, width, precision, size);
			if (printout == -1)
				return (-1);
			printout_chars += printout;
		}
		i++;
	}

	print_buffer(bufferchar, &buff_int);

	va_end(parameters);

	return (printout_chars);
}


/**
 * print_buffer - it prints bufferchar's content if found
 * @bufferchar: string of chararacters
 * @buff_int: the length, the next character is added here
 */
void print_buffer(char bufferchar[], int *buff_int)
{
	if (*buff_int > 0)
		write(1, &bufferchar[0], *buff_int);

	*buff_int = 0;
}
