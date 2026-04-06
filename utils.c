#include "fractol.h"

double	ft_atof(char *s)
{
	double	res;
	double	pow;
	int		sign;

	res = 0;
	sign = 1;
	pow = 1;
	while (*s == ' ' || (*s >= 9 && *s <= 13))
		s++;
	if (*s == '-')
		sign = -1;
	if (*s == '-' || *s == '+')
		s++;
	while (*s >= '0' && *s <= '9')
	{
		res = res * 10 + (*s - '0');
		s++;
	}
	if (*s == '.')
	{
		s++;
		while (*s >= '0' && *s <= '9')
		{
			res = res * 10 + (*s - '0');
			pow *= 10;
			s++;
		}
	}
	return (res * sign / pow);
}