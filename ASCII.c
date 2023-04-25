#include "main.h"

/**
 * is_print- checks if character is printable
 * @c: character to be checked
 * Return: 1 on success 0 if not
 */
int is_print(char c)
{
	if (c >= 32 && c < 127)
		return (1);

	return (0);
}

/**
 * app_hex_code - adds ASCII in hexadecimal to a buffer
 * @bufferchar: characters stored in buffer.
 * @i: the adding starts here
 * @ascii_code: ASSCI CODE.
 * Return: 3
 */
int app_hex_code(char ascii_code, char bufferchar[], int i)
{
	char map_loc[] = "0123456789ABCDEF";

	if (ascii_code < 0)
		ascii_code *= -1;

	bufferchar[i++] = '\\';
	bufferchar[i++] = 'x';

	bufferchar[i++] = map_loc[ascii_code / 16];
	bufferchar[i] = map_loc[ascii_code % 16];

	return (3);
}

/**
 * is_figure - tells if a character is integer
 * @c: the character
 * Return: 1, 0 otherwise
 */
int is_figure(char c)
{
	if (c >= '0' && c <= '9')
		return (1);

	return (0);
}

/**
 * cnvt_size_int- puts integer to a specific size
 * @fig: integer to put
 * @size: integer showing what is put
 * Return: value of integer put
 */
long int cnvt_size_int(long int fig, int size)
{
	if (size == LONG)
		return (fig);
	else if (size == SHORT)
		return ((short)fig);

	return ((int)fig);
}

/**
 * cnvt_size_unsign - puts number to specific size
 * @fig: interger to put
 * @size: special number showing figure to be put
 * Return: value of number put
 */
long int cnvt_size_unsign(unsigned long int fig, int size)
{
	if (size == LONG)
		return (fig);
	else if (size == SHORT)
		return ((unsigned short)fig);

	return ((unsigned int)fig);
}
