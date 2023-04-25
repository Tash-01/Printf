#include "main.h"

/**
 * g_flg - act flg calc
 *
 * @format: str to prnt arg
 * @x: param.
 *
 * Return: flg
 */

int g_flg(const char *format, int *x)
{
	int y, i_pnt;
	int flg = 0;

	const int FLG_ARR[] = {F_M, F_P, F_Z, F_H, F_S, 0};
	const char FLG_CH[] = {'-', '+', '0', '#', ' ', '\0'};

	for (i_pnt = *x + 1; format[i_pnt] != '\0'; i_pnt++)
	{
		for (y = 0; FLG_CH[y] != '\0'; y++)
			if (format[i_pnt] == FLG_CH[y])
			{
				flg |= FLG_ARR[y];
				break;
			}

		if (FLG_CH[y] == 0)
			break;
	}

	*x = i_pnt - 1;

	return (flg);
}
