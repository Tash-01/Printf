#include "main.h"

/**
 * g_s - calc size to cast arg
 * @format: str to print to
 * @x: list arg to print
 *
 * Return: prcsn.
 */
int get_size(const char *format, int *x)
{
	int index_pos = *x + 1;
	int s = 0;

	if (format[index_pos] == 'l')
		s = S_L;
	else if (format[index_pos] == 'h')
		s = S_S;

	if (s == 0)
		*x = index_pos - 1;
	else
		*x = index_pos;

	return (s);
}
