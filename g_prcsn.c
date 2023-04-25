#include "main.h"

/**
 * g_prcsn - prcsn calc for print
 * @format: str to print to
 * @x: argument list to print.
 * @list: argument list.
 *
 * Return: prcsn.
 */
int g_prcsn(const char *format, int *x, va_list list)
{
	int index_pos = *x + 1;
	int prcsn = -1;

	if (format[index_pos] != '.')
	{
		return (prcsn);
	}

	prcsn = 0;

	for (index_pos += 1; format[index_pos] != '\0'; index_pos++)
	{
		if (is_dgt(format[index_pos]))
		{
			prcsn *= 10;
			prcsn += format[index_pos] - '0';
		}
		else if (format[index_pos] == '*')
		{
			index_pos++;
			prcsn = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*x = index_pos - 1;

	return (prcsn);
}
