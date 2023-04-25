#include "main.h"

/**
 * can_prnt - check if char can print
 * @c: Char 
 *
 * Return: 1 if c is printable, 0 otherwise
 */
 
int can_prnt(char c)
{
	if (c >= 32 && c < 127)
		return (1);

	return (0);
}

/**
 * app_hx_code - app hx cde to bff
 *
 * @bff: char arr
 * @index: Index 
 * @ascii_code: ASSCI CODE.
 *
 * Return: Always 3
 */
 
int app_hx_code(char ascii_code, char bff[], int x)
{
	char arr_map[] = "0123456789ABCDEF";
	
	if (ascii_code < 0)
		ascii_code *= -1;

	bff[x++] = '\\';
	bff[x++] = 'x';

	bff[x++] = arr_map[ascii_code / 16];
	bff[x] = arr_map[ascii_code % 16];

	return (3);
}

/**
 * is_dgt - Verifies if a char is a digit
 * @c: Char to be evaluated
 *
 * Return: 1 if true, 0 if fals
 */
 
int is_dgt(char c)
{
	if (c >= '0' && c <= '9')
		return (1);

	return (0);
}

/**
 * conv_s_num - Casts a number to the specified size
 *
 * @num: Num
 * @s: size
 *
 * Return: val num
 */
 
long int conv_s_num(long int num, int s)
{
	if (s == S_L)
		return (num);
	else if (s == S_S)
		return ((short)num);

	return ((int)num);
}

/**
 * conv_s_unsgnd - conv num to size
 *
 * @n: Number to be casted
 * @s: Number indicating the type to be casted
 *
 * Return: Casted value of num
 */
 
long int conv_s_unsgnd(unsigned long int n, int s)
{
	if (s == S_L)
		return (n);
	else if (s == S_S)
		return ((unsigned short)n);

	return ((unsigned int)n);
}
