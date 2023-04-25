#include "main.h"
/**
 * print_binary - prints out the unisigned int
 * @parameters: arguments
 * @bufferchar: it handles the buffer array
 * @flags: finds the active flags
 * @width: get width of the char passed in
 * @precision: specifications
 * @size: specifiers size
 * Return: characters printed out.
 */
int print_binary(va_list parameters, char bufferchar[],
		int flags, int width, int precision, int size)
{
	unsigned int j, k, i, sum;
	unsigned int b[32];
	int count;

	UNUSED(bufferchar);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	j = va_arg(parameters, unsigned int);
	k = 2147483648;
	b[0] = j / k;
	i = 1;
	while (i < 32)
	{
		k /= 2;
		b[i] = (j / k) % 2;
		i++;
	}

	i = 0;
	sum = 0;
	count = 0;

	while (i < 32)
	{
		sum += b[i];

		if (sum || i == 31)
		{
			char y = '0' + b[i];

			write(1, &y, 1);
			count++;
		}
		i++;
	}

	return (count);
}
