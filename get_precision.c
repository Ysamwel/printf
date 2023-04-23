#include "main.h"

/**
 * get_precision - precision for printing
 * @format:  prints the arguments
 * @i:arguments to be printed.
 * @parameters: list of arguments.
 *
 * Return: precision
 */
int get_precision(const char *format, int *i, va_list parameters)
{
	int curr = *i + 1;
	int precision = -1;

	if (format[curr] != '.')
		return (precision);

	precision = 0;

	for (curr += 1; format[curr] != '\0'; curr++)
	{
		if (is_digit(format[curr]))
		{
			precision *= 10;
			precision += format[curr] - '0';
		}
		else if (format[curr] == '*')
		{
			curr++;
			precision = va_arg(parameters, int);
			break;
		}
		else
			break;
	}

	*i = curr - 1;

	return (precision);
}
