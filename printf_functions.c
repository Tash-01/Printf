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

/** int print **/

/**
 * prnt_int - Print int
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
int prnt_int(va_list type, char bff[],
	int flg, int prcsn, int width, int s)
{
	int i = BFF_S - 2;
	int is_neg = 0;
	long int num = va_arg(type, long int);
	unsigned long int x;

	n = conv_s_num(num, s);

	if (num == 0)
		bff[i--] = '0';

	bff[BFF_S - 1] = '\0';
	x = (unsigned long int)n;

	if (num < 0)
	{
		x = (unsigned long int)((-1) * n);
		is_neg = 1;
	}

	while (x > 0)
	{
		bff[i--] = (num % 10) + '0';
		x /= 10;
	}

	i++;

	return (w_num(is_neg, i, bff, flg, width, prcsn, s));
}

/** bin print **/

/**
 * prnt_bin - print unsgnd int
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

int prnt_bin(va_list type, char bff[],
	int flg, int prcsn, int width, int s)
{
	unsigned int i, x, y, sum;
	unsigned int z[32];
	int total;

	UNUSED(bff);
	UNUSED(flg);
	UNUSED(width);
	UNUSED(prcsn);
	UNUSED(s);

	i = va_arg(type, unsigned int);
	x = 2147483648;
	z[0] = i / x;

	for (y = 1; y < 32; y++)
	{
		x /= 2;
		z[y] = (i / x) % 2;
	}
	for (y = 0, sum = 0, total = 0; y < 32; y++)
	{
		sum += z[y];
		if (sum || y == 31)
		{
			char c = '0' + z[y];

			write(1, &c, 1);
			total++;
		}
	}
	return (total);
}
