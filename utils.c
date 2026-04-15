/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmesgari <mmesgari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/06 14:37:40 by mmesgari          #+#    #+#             */
/*   Updated: 2026/04/15 15:26:14 by mmesgari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
		res = res * 10 + (*s++ - '0');
	if (*s == '.')
	{
		s++;
		while (*s >= '0' && *s <= '9')
		{
			res = res * 10 + (*s++ - '0');
			pow *= 10;
		}
	}
	return (res * sign / pow);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

int	is_valid_number(char *s)
{
	int	has_digit;

	has_digit = 0;
	if (*s == '+' || *s == '-')
		s++;
	while (*s >= '0' && *s <= '9')
	{
		has_digit = 1;
		s++;
	}
	if (*s == '.')
	{
		s++;
		while (*s >= '0' && *s <= '9')
		{
			has_digit = 1;
			s++;
		}
	}
	return (has_digit && *s == '\0');
}

void	print_usage(void)
{
	write(1, "Usage:\n", 7);
	write(1, "  ./fractol mandelbrot\n", 23);
	write(1, "  ./fractol julia <x> <y>\n", 26);
	write(1, "    examples: (-0.8, 0.156)  (-0.4, 0.6)  (0.285, 0.01)\n", 58);
	write(1, "  ./fractol burning_ship\n", 25);
}