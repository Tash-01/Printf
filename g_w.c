#include "main.h"

/**
 * g_width - Calculates the width for printing
 * @format: Formatted string in which to print the arguments.
 * @x: List of arguments to be printed.
 * @list: list of arguments.
 *
 * Return: width.
 */
int g_width(const char *format, int *x, va_list list)
{
	int index_pos;
	int width = 0;

	for (index_pos = *x + 1; format[index_pos] != '\0'; index_pos++)
	{
		if (is_dgt(format[index_pos]))
		{
			width *= 10;
			width += format[index_pos] - '0';
		}
		else if (format[index_pos] == '*')
		{
			index_pos++;
			width = va_arg(list, int);
			break;
		}
		else
		{
			break;
		}
	}

	*x = index_pos - 1;

	return (width);
}
