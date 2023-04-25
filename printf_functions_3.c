#include "main.h"

/* print mem addr */
/**
 * print_pnt - Prints the value of a pointer variable
  *
 * @type: arg list
 * @bff: arr buff to handle print
 * @flg: actv flag calc
 * @width: width
 * @prcsn: prcsn spec
 * @s: s
 *
 * Return: num chars printed
 */
 
int print_pnt(va_list type, char bff[],
	int flg, int width, int prcsn, int s)
{
	char ch_rem = 0, padd = ' ';
	int i = BFF_S - 2, len = 2, init_padd = 1; 
	unsigned long num_pntr;
	char arr_map[] = "0123456789abcdef";
	void *p = va_arg(type, void *);

	UNUSED(width);
	UNUSED(s);

	if (p == NULL)
		return (write(1, "(nil)", 5));

	bff[BFF_S - 1] = '\0';
	UNUSED(prcsn);

	num_pntr = (unsigned long)p;

	while (num_pntr > 0)
	{
		bff[i--] = arr_map[num_pntr % 16];
		num_pntr /= 16;
		len++;
	}

	if ((flg & F_Z) && !(flg & F_M))
		padd = '0';
	if (flg & F_P)
		ch_rem = '+', len++;
	else if (flg & F_SP)
		ch_rem = ' ', len++;

	i++;

	return (pntr_w(bff, i, len,
		width, flg, padd, ch_rem, init_padd));
}

/**non priontable char**/
/**
 * print_nprnt - hex print of ascii codes
 *
 * @type: arg list
 * @bff: arr buff to handle print
 * @flg: actv flag calc
 * @width: width
 * @prcsn: prcsn spec
 * @s: s
 *
 * Return: num chars printed
 */
 
int print_nprnt(va_list type, char bff[],
	int flg, int width, int prcsn, int s)
{
	int x = 0, add_sp = 0;
	char *str = va_arg(type, char *);

	UNUSED(flg);
	UNUSED(width);
	UNUSED(prcsn);
	UNUSED(s);

	if (str == NULL)
		return (write(1, "(null)", 6));

	while (str[x] != '\0')
	{
		if (can_prnt(str[x]))
			bff[x + add_sp] = str[x];
		else
			add_sp += app_hx_code(str[x], bff, x + add_sp);

		x++;
	}

	bff[x + add_sp] = '\0';

	return (write(1, bff, x + add_sp));
}

/**reverse print**/
/**
 * print_rev - Prints reverse string.
 *
 * @type: arg list
 * @bff: arr buff to handle print
 * @flg: actv flag calc
 * @width: width
 * @prcsn: prcsn spec
 * @s: s
 *
 * Return: num chars printed
 */
 

int print_rev(va_list type, char bff[],
	int flg, int width, int prcsn, int s)
{
	char *str;
	int x, total = 0;

	UNUSED(bff);
	UNUSED(flg);
	UNUSED(width);
	UNUSED(s);

	str = va_arg(type, char *);

	if (str == NULL)
	{
		UNUSED(prcsn);

		str = ")Null(";
	}
	for (x = 0; str[x]; x++)
		;

	for (x = x - 1; x >= 0; x--)
	{
		char y = str[x];

		write(1, &y, 1);
		total++;
	}
	return (total);
}
/**rot13 print**/
/**
 * print_rot13 - Print a string in rot13.
 *
 * @type: arg list
 * @bff: arr buff to handle print
 * @flg: actv flag calc
 * @width: width
 * @prcsn: prcsn spec
 * @s: s
 *
 * Return: num chars printed
 */
 
int print_rot13(va_list type, char bff[],
	int flg, int width, int prcsn, int s)
{
	char c;
	char *str;
	unsigned int x, y;
	int total = 0;
	char origin[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char encoded[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	str = va_arg(type, char *);
	UNUSED(bff);
	UNUSED(flg);
	UNUSED(width);
	UNUSED(prcsn);
	UNUSED(s);

	if (str == NULL)
		str = "(AHYY)";
	for (x = 0; str[x]; x++)
	{
		for (y = 0; origin[y]; y++)
		{
			if (origin[y] == str[x])
			{
				c = encoded[y];
				write(1, &c, 1);
				total++;
				break;
			}
		}
		if (!origin[y])
		{
			c = str[x];
			write(1, &c, 1);
			total++;
		}
	}
	return (total);
}
