#include "main.h"

/** unsgnd num print **/

/**
 * unsgnd_prnt - Prints an unsigned number
 *
 * @type: arg list
 * @bff: arr buff to handle print
 * @flg: actv flag calc
 * @width: width
 * @prcsn: prcsn spec
 * @s: size
 *
 * Return: num chars printed
 */
int unsgnd_prnt(va_list type, char bff[],
	int flg, int width, int prcsn, int s)
{
	int x = BFF_S - 2;
	unsigned long int n = va_arg(type, unsigned long int);

	num = unsgnd_conv_s(n, s);

	if (n == 0)
		bff[x--] = '0';

	bff[BFF_S - 1] = '\0';

	while (n > 0)
	{
		bff[x--] = (num % 10) + '0';
		n /= 10;
	}

	x++;

	return (unsgnd_w(0, x, bff, flg, width, prcsn, s));
}

/** unsgnd octal print**/
/**
 * octal_print - Prints an unsigned number in octal notation
 *
 * @type: arg list
 * @bff: arr buff to handle print
 * @flg: actv flag calc
 * @width: width
 * @prcsn: prcsn spec
 * @s: size
 *
 * Return: num chars printed
 */
int octal_print(va_list type, char bff[],
	int flg, int width, int prcsn, int s)
{

	int x = BFF_S - 2;
	unsigned long int n = va_arg(type, unsigned long int);
	unsigned long int num_start = n;

	UNUSED(width);

	n = unsgnd_conv_s(n, s);

	if (n == 0)
		bff[x--] = '0';

	bff[BFF_S - 1] = '\0';

	while (n > 0)
	{
		bff[x--] = (n % 8) + '0';
		n /= 8;
	}

	if (flg & F_H && num_start != 0)
		bff[x--] = '0';

	x++;

	return (unsgnd_w(0, x, bff, flg, width, prcsn, s));
}

/** hexadecial unsignd print**/
/**
 * hexdec_print - print unsignd in hexdec
 *
 * @type: arg list
 * @bff: arr buff to handle print
 * @flg: actv flag calc
 * @width: width
 * @prcsn: prcsn spec
 * @s: size
 *
 * Return: num chars printed
 */
int hexdec_print(va_list type, char bff[],
	int flg, int width, int prcsn, int s)
{
	return (hex_print(type, "0123456789abcdef", bff,
		flg, 'x', width, prcsn, s));
}

/** unsgnd print in upper hexdec**/
/**
 * upper_hexdec_print - Prints an unsigned number in upper hexadecimal notation
 *
 * @type: arg list
 * @bff: arr buff to handle print
 * @flg: actv flag calc
 * @width: width
 * @prcsn: prcsn spec
 * @s: size
 *
 * Return: num chars printed
 */
int upper_hexdec_print(va_list type, char bff[],
	int flg, int width, int prcsn, int s)
{
	return (hex_print(type, "0123456789ABCDEF", bff,
		flg, 'X', width, prcsn, s));
}

/** unsgnd print in upper or lower hexdec **/
/**
 * hex_print - Prints a hexadecimal number in lower or upper
 *
 * @arr_map: value arr to map num
 *
 * @type: arg list
 * @bff: arr buff to handle print
 * @flg: actv flag calc
 * @width: width
 * @prcsn: prcsn spec
 * @s: size
 * @act_flg: Calculates active flg
 *
 * Return: Number of chars printed
 */
int hex_print(va_list type, char arr_map[], char bff[],
	int flg, char act_flg, int width, int prcsn, int s)
{
	int x = BFF_S - 2;
	unsigned long int n = va_arg(type, unsigned long int);
	unsigned long int num_start = num;

	UNUSED(width);

	n = unsgnd_conv_s(n, s);

	if (n == 0)
		bff[x--] = '0';

	bff[BFF_S - 1] = '\0';

	while (n > 0)
	{
		bff[x--] = arr_map[n % 16];
		n /= 16;
	}

	if (flg & F_H && num_start != 0)
	{
		bff[x--] = act_flg;
		bff[x--] = '0';
	}

	x++;

	return (unsgnd_w(0, x, bff, flg, width, prcsn, s));
}
