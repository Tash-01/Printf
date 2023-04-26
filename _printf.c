#include "main.h"

/**
 * _printf - printf func
 * @format: format
 *
 * Return: printed char
 */

int _printf(const char *format, ...)
{
	int i, flg, width, s, prcsn;
	int prnt = 0, char_prnt = 0, bff_i = 0;
	char bff[BUFF_SIZE];
	va_list list;

	if (format == NULL)
		return (-1);

	va_start(list, format);

	for (i = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			bff[bff_i++] = format[i];
			if (bff_i == BUFF_SIZE)
				prnt_b(bff, &bff_i);
			char_prnt++;
		}
		else
		{
			prnt_b(bff, &bff_i);
			flg = g_flg(format, &i);
			width = g_width(format, &i, list);
			prcsn = g_prcsn(format, &i, list);
			s = g_s(format, &i);
			++i;
			prnt = prnt_h(format, &i, list, bff,
				flg, width, prcsn, s);
			if (prnt == -1)
				return (-1);
			char_prnt += prnt;
		}
	}

	prnt_b(bff, &bff_i);

	va_end(list);

	return (char_prnt);
}

/**
* prnt_b - print buffer
* @bff: char arr
* @bff_i: index to show where to insert next char
*/

void prnt_b(char bff[], int *bff_i)
{
	if (*bff_i > 0)
		write(1, bff[0], *bff_i);

	*bff_i = 0;
}
