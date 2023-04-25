#include "main.h"
/**
 * p_rot13str- print rot13 string
 * @parameters: types of arguments
 * @bufferchar: buffer arrays to print
 * @flags:  gets calculation of active flags
 * @width: gives width
 * @precision: gives precision specifics
 * @size: tells the size
 * Return: printed characters
 */
int p_rot13str(va_list parameters, char bufferchar[],
		int flags, int width, int precision, int size)
{
	char a;
	char *string;
	unsigned int i = 0, j;
	int count = 0;
	char in[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char out[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	string = va_arg(parameters, char *);
	UNUSED(precision);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(size);
	UNUSED(bufferchar);

	if (string == NULL)
		string = "(AHYY)";

	while (string[i])
	{
		j = 0;
		while (in[j])
		{
			if (in[j] == string[i])
			{
				a = out[j];
				write(1, &a, 1);
				count++;
				break;
			}
			j++;
		}
		if (!in[j])
		{
			a = string[i];
			write(1, &a, 1);
			count++;
		}
		i++;
	}
	return (count);

}

