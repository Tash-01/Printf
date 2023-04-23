#include "main.h"

/**
 * g_flg - act flg calc
 *
 * @format: str to prnt arg
 * @i: param.
 * 
 * Return: flg
 */

int g_flg(const char *format, int *x)
{
	int x, i_pnt;
	int flg = 0;

	const int FLG_ARR[] = {F_M, F_P, F_Z, F_H, F_S, 0};
	const char FLG_CH[] = {'-', '+', '0', '#', ' ', '\0'};

	for (i_pnt = *i + 1; format[i_pnt] != '\0'; i_pnt++)
	{
		for (x = 0; FLG_CH[x] != '\0'; x++)
			if (format[i_pnt] == FLG_CH[x])
			{
				flg |= FLG_ARR[x];
				break;
			}

		if (FLG_CH[x] == 0)
			break;
	}

	*i = i_pnt - 1;

	return (flg);
}
