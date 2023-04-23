include "main.h"
/**
 * hndl_prnt - print argument based on type
 *
 * @str_fmt: str to print to
 * @list: argument list
 * @index: index
 * @bff: buffer array to handle print.
 * @flg: flags
 * @width: g_w.
 * @prcsn: precision 
 * @s: size
 *
 * Return: 1 or 2;
 */
int hndl_prnt(const char *str_fmt, int *index, va_list list, char bff[],
	int flg, int width, int prcsn, int s)
{
	int x, uknwn_len, char_prntd;
	ukwnn_len = 0;
	char_prntd = -1;
	
	str_fmt_t str_fmt_types[] = {
		{'c', prnt_char}, {'s', prnt_str}, {'%', prnt_percent},
		{'i', prnt_int}, {'d', prnt_int}, {'b', prnt_bin},
		{'u', prnt_unsgnd}, {'o', prnt_octal}, {'x', prnt_hxdec},
		{'X', prnt_hx_upper}, {'p', print_pntr}, {'S', prnt_nprnt},
		{'r', prnt_rev}, {'R', print_rot13string}, {'\0', NULL}
	};
	for (i = 0; str_fmt_types[i].str_fmt != '\0'; i++)
		if (str_fmt[*index] == str_fmt_types[i].str_fmt)
			return (str_fmt_types[i].fn(list, bff, flg, width, prcsn, s));

	if (str_fmt_types[i].str_fmt == '\0')
	{
		if (str_fmt[*index] == '\0')
			return (-1);
		uknwn_len += write(1, "%%", 1);
		if (str_fmt[*index - 1] == ' ')
			uknwn_len += write(1, " ", 1);
		else if (width)
		{
			--(*index);
			while (str_fmt[*index] != ' ' && str_fmt[*index] != '%')
				--(*index);
			if (str_fmt[*index] == ' ')
				--(*index);
			return (1);
		}
		uknwn_len += write(1, &str_fmt[*index], 1);
		return (uknwn_len);
	}
	return (char_prntd);
}
