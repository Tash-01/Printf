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
int print_char(va_list type, char bff[],
		int flg, int s, int width, int prcsn);
int print_string(va_list type, char bff[],
	    int flg, int s, int width, int prcsn);
int print_percent(va_list type, char bff[],
	int flg, int width, int prcsn, int s);

/* numbers */
int print_int(va_list type, char bff[],
	int flg, int prcsn, int width, int s);
int print_bin(va_list type, char bff[],
	int flg, int prcsn, int width, int s);
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

/* non printable characters */
int print_nprnt(va_list type, char bff[],
	int flg, int prcsn, int width, int s);

/* print mem addr */
int print_pntr(va_list type, char bff[],
	int flg, int prcsn, int width, int s);

/* specifiers */
int g_flg(const char *format, int *i);
int g_widthw(const char *format, int *x, va_list list);
int g_prcsn(const char *format, int *i, va_list list);
int g_s(const char *format, int *x);

/*reverse str*/
int print_rev(va_list type, char bff[],
	int flg, int prcsn, int width, int s);

/*print in rot 13*/
int print_rot13(va_list type, char bff[],
	int flg, int prcsn, int width, int s);

/* width handler */
int handle_w_char(char c, char bff[],
	int flg, int prcsn, int width, int s);
int w_num(int is_positive, int ind, char bff[],
	int flg, int prcsn, int width, int s);
int w_num(int ind, char bff[], int prcsn, int flg, int width,
	int length, char padd, char extra_c);
int w_pntr(char bff[], int ind, int len,
	int width, int flg, char padd, char extra_c, int padd_start);

int w_unsgnd(int is_negative, int ind,
char bff[], int flg, int prcsn, int width, int size);

/** extra **/
int can_prnt(char);
int app_hx_code(char, char[], int);
int is_dgt(char);

long int conv_s_num(long int num, int s);
long int conv_s_unsgnd(unsigned long int num, int s);

#endif
