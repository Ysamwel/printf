#include "main.h"
/**
 * p_non_print - Prints ascii codes in hexa of non printable chars
 * @parameters: arguments list
 * @bufferchar: output buffer's array
 * @flags: gives calculation of active flag
 * @width: width
 * @precision: the precision specifics
 * @size: size
 * Return: characters printed
 */
int p_non_print(va_list parameters, char bufferchar[],
		int flags, int width, int precision, int size)
{
	int i = 0, ofst = 0;
	char *string = va_arg(parameters, char *);

	UNUSED(precision);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(size);

	if (string == NULL)
		return (write(1, "(null)", 6));

	while (string[i] != '\0')
	{
		if (is_print(string[i]))
			bufferchar[i + ofst] = string[i];
		else
			ofst += append_hexa_code(string[i], bufferchar, i + ofst);

		i++;
	}

	bufferchar[i + ofst] = '\0';

	return (write(1, bufferchar, i + ofst));
}
