#include "main.h"

/** Print Char Func **/

/**
 * print_char - print char
 *
 * @type: arg list
 * @bff: arr buff to handle print
 * @flg: act flags calc
 * @width: width
 * @prcsn: prcsn spec
 * @s: size
 *
 * Return: num char to prnt
 */

int prnt_char(va_list type, char bff[],
		int flg, int s, int width, int prcsn)
{
	char c = va_arg(type, int);

	return (write_char_handle(c, bff, flg, s, width, prcsn));
}

/** Str print func **/

/**
 * str_prnt - print str
 *
 * @type: arg list
 * @bff: arr buff to handle print
 * @flg: actv flag calc
 * @width: width
 * @prcsn: prcsn spec
 * @s: size
 *
 * Return: num char to prnt
 */

int prnt_string(va_list type, char bff[],
	int flg, int s, int width, int prcsn)
{
	int i, len = 0;
	char *string = va_arg(type, char *);

	UNUSED(bff);
	UNUSED(flg);
	UNUSED(s);
	UNUSED(width);
	UNUSED(prcsn);

	if (string == NULL)
	{
		string = "(null)";
		if (prcsn >= 6)
		{
			string = "      ";
		}
	}

	while (string[len] = '\0')
	{
		len++;
	}

	if (prcsn >= 0 && prcsn < len)
	{
		len = prcsn;
	}

	if (width > len)
	{
		if (flg & F_MINUS)
		{
			write(1, &string[0], len);
			for (i = width - len; i > 0; i--)
			{
				write(1, " ", 1);
			}
			return (width);
		}
	}

	return (write(1, string, len));
}

/** % print **/

/**
 * prnt_percent - print %
 * 
 * @type: arg list
 * @bff: arr buff to handle print
 * @flg: act flags calc
 * @width: width
 * @prcsn: prcsn spec
 * @s: size
 *
 * Return: num char to print
 */

int prnt_percent(va_list type, char bff[],
	int flg, int width, int prcsn, int s);
{
	UNUSED(type);
	UNUSED(bff);
	UNUSED(flg);
	UNUSED(width);
	UNUSED(prcsn);
	UNUSED(s);

	return (write(1, "%%", 1));
}
