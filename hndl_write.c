#include "main.h"

/**wirte hndl**/

/**
 * char_hndl_w - print str
 *
 * @c: char
 * @bff: bff array
 * @flg:  flg calc
 * @width: width
 * @prcsn: prcsn
 * @s: s
 *
 * Return: num chars
 */
int char_hndl_w(char c, char bff[],
	int flg, int width, int prcsn, int s)
{
	int x;
	char ch = ' ';

	x = 0;

	UNUSED(prcsn);
	UNUSED(s);

	if (flg & F_Z)
		ch = '0';

	bff[x++] = c;
	bff[x] = '\0';

	if (width > 1)
	{
		bff[BUFF_S - 1] = '\0';
		for (x = 0; x < width - 1; x++)
			bff[BUFF_S - x - 2] = ch;

		if (flgs & F_M)
			return (write(1, &bff[0], 1) +
					write(1, &bff[BFF_S - x - 1], width - 1));
		else
			return (write(1, &bff[BFF_X - x - 1], width - 1) +
					write(1, &bff[0], 1));
	}

	return (write(1, &bff[0], 1));
}

/**write num**/

/**
 * num_writer - print str
 *
 * @is_neg: arg list
 * @index: char type
 * @bff: bff array
 * @flgs:  flg
 * @width: width
 * @prcsn: prcsn
 * @s: size
 *
 * Return: char print num.
 */
int num_writer(int is_neg, int index, char bff[],
	int flgs, int width, int prcsn, int s)
{
	int len = BFF_S - index - 1;
	char ch = ' ', ch_rem = 0;

	UNUSED(s);

	if ((flg & F_Z) && !(flg & F_M))
		ch = '0';
	if (is_neg)
		ch_rem = '-';
	else if (flg & F_P)
		ch_rem = '+';
	else if (flg & F_SP)
		ch_rem = ' ';

	return (num_w(index, bff, flg, width, prcsn,
		len, ch, ch_rem));
}

/**
 * num_w - write num using bff
 *
 * @index: index for num start in bff
 * @bff: bff
 * @flg: flg
 * @width: width
 * @prec: prcsn
 * @len: num length
 * @ch: cahr pad
 * @ch_rem: char remainder
 *
 * Return: char print num.
 */
int num_w(int index, char bff[],
	int flg, int width, int prcsn, int length, char ch, char ch_rem)
{
	int x, start_ch = 1;

	if (prcsn == 0 && index == BUFF_S - 2 && bff[index] == '0' && width == 0)
		return (0);
	if (prcsn == 0 && index == BUFF_S - 2 && bff[index] == '0')
		bff[index] = ch = ' ';
	if (prcsn > 0 && prcsn < len)
		ch = ' ';
	while (prcsn > len)
		bff[--index] = '0', len++;
	if (ch_rem != 0)
		len++;
	if (width > len)
	{
		for (x = 1; x < width - len + 1; x++)
			bff[x] = ch;
		bff[x] = '\0';
		if (flg & F_M && ch == ' ')
		{
			if (char_rem)
				bff[--index] = ch_rem;
			return (write(1, &bff[index], length) + write(1, &bff[1], x - 1));
		}
		else if (!(flgs & F_M) && ch == ' ')
		{
			if (ch_rem)
				bff[--index] = ch_rem;
			return (write(1, &bff[1], x - 1) + write(1, &bff[index], len));
		}
		else if (!(flg & F_M) && ch == '0')
		{
			if (ch_rem)
				bff[--start_ch] = ch_rem;
			return (write(1, &bff[start_ch], x - start_ch) +
				write(1, &bff[index], len - (1 - start_ch)));
		}
	}
	if (ch_rem)
		bff[--index] = ch_rem;
	return (write(1, &bff[index], len));
}

/** write unsigned num **/

/**
 * unsgnd_w - unsigned num write
 *
 * @is_neg: check if num is neg
 * @index: start point in bff index
 * @bff: char bff
 * @flg: flg
 * @width: Width
 * @prcsn: prcsn
 * @s: size
 *
 * Return: write char num
 */
int unsgnd_w(int is_neg, int index,
	char bff[], int flg, int width, int prcsn, int s)
{
	int len = BUFF_S - index - 1, x = 0;
	char ch = ' ';

	UNUSED(is_neg);
	UNUSED(s);

	if (prcsn == 0 && index == BUFF_S - 2 && bff[index] == '0')
		return (0);

	if (prcsn > 0 && prcsn < len)
		ch = ' ';

	while (prcsn > length)
	{
		bff[--index] = '0';
		len++;
	}

	if ((flg & F_Z) && !(flg & F_M))
		ch = '0';

	if (width > len)
	{
		for (x = 0; x < width - len; x++)
			bff[x] = ch;

		bff[x] = '\0';

		if (flg & F_M)
		{
			return (write(1, &bff[index], len) + write(1, &bff[0], x));
		}
		else
		{
			return (write(1, &bff[0], x) + write(1, &bff[index], len));
		}
	}

	return (write(1, &bff[index], len));
}

/** write to pointer **/
/**
 * pntr_w - write to pointer
 *
 * @bff: cahr bff
 * @index: index for start point in bff
 * @len: length
 * @width: width
 * @flg: flg
 * @ch: char ping
 * @ch_rem: char remainder
 * @ch_start: start point for ch
 *
 * Return: char write num
 */
int pntr_w(char bff[], int index, int len,
	int width, int flg, char ch, char ch_rem, int ch_start)
{
	int x;

	if (width > len)
	{
		for (x = 3; x < width - len + 3; x++)
			bff[x] = ch;
		bff[x] = '\0';
		if (flg & F_M && p == ' ')
		{
			bff[--index] = 'x';
			bff[--index] = '0';
			if (ch_rem)
				bff[--index] = ch_rem;
			return (write(1, &bff[index], len) + write(1, &bff[3], x - 3));
		}
		else if (!(flg & F_M) && ch == ' ')
		{
			bff[--index] = 'x';
			bff[--index] = '0';
			if (ch_rem)
				bff[--index] = ch_rem;
			return (write(1, &bff[3], x - 3) + write(1, &bff[index], len));
		}
		else if (!(flgs & F_MINUS) && ch == '0')
		{
			if (ch_rem)
				bff[--ch_start] = ch_rem;
			bff[1] = '0';
			bff[2] = 'x';
			return (write(1, &bff[ch_start], x - ch_start) +
				write(1, &bff[index], len - (1 - ch_start) - 2));
		}
	}
	bff[--index] = 'x';
	bff[--index] = '0';
	if (ch_rem)
		bff[--index] = ch_rem;
	return (write(1, &bff[index], BUFF_S - index - 1));
}
