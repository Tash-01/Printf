#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

#define UNUSED(x) (void)(x)
#define BUFF_SIZE 1024

int _printf(const char *format, ...);

/** Functions **/

/* char and str */
int prnt_char(va_list type, char bff[],
		int flg, int s, int width, int prcsn);
int prnt_string(va_list type, char bff[],
	int flg, int s, int width, int prcsn);
int prnt_percent(va_list type, char bff[],
	int flg, int width, int prcsn, int s);

/* numbers */
int prnt_int(va_list type, char bff[],
	int flg, int prcsn, int width, int s);
int prnt_bin(va_list type, char bff[],
	int flg, int prcsn, int width, int s);
	/**************************************/
int print_unsgnd(va_list type, char bff[],
	int flg, int prcsn, int width, int s);
int print_octal(va_list type, char bff[],
	int flg, int prcsn, int width, int s);
int print_hxdec(va_list type, char bff[],
	int flg, int prcsn, int width, int s);
int print_hx_upper(va_list type, char bff[],
	int flg, int prcsn, int width, int s);

int print_hexa(va_list type, char map_to[],
char bff[], int flg, char flag_ch, int prcsn, int width, int s);
/**************************************************/
/* non printable characters */
int print_nprnt(va_list type, char bff[],
	int flg, int width, int prcsn, int s);

/* print mem addr */
int print_pnt(va_list type, char bff[],
	int flg, int width, int prcsn, int s);

/* specifiers */
int g_flg(const char *format, int *i);
int g_width(const char *format, int *x, va_list list);
int g_prcsn(const char *format, int *x, va_list list);
int g_s(const char *format, int *x);

/*reverse str*/
int print_rev(va_list type, char bff[],
	int flg, int width, int prcsn, int s);

/*print in rot 13*/
int print_rot13(va_list type, char bff[],
		 int flg, int width, int prcsn, int s);

/* width handler */
int char_hndl_w(char c, char bff[],
	int flg, int width, int prcsn, int s);
int num_writer(int is_neg, int index, char bff[],
	int flgs, int width, int prcsn, int s);
int w_num(int index, char bff[],
	int flg, int width, int prcsn, int length, char ch, char ch_rem);
int pntr_w(char bff[], int index, int len,
	int width, int flg, char ch, char ch_rem, int ch_start);
int unsgnd_w(int is_neg, int index,
	char bff[], int flg, int width, int prcsn, int s);

/** extra **/
int can_prnt(char c);
int app_hx_code(char, ascii_code, char bff[], int x);
int is_dgt(char c);

long int conv_s_num(long int num, int s);
long int conv_s_unsgnd(unsigned long int n, int s);

#endif
