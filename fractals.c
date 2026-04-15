/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmesgari <mmesgari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 16:31:47 by mmesgari          #+#    #+#             */
/*   Updated: 2026/04/15 16:32:17 by mmesgari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	init_values(t_complex *z, t_complex *c, t_data *data)
{
	if (!ft_strcmp(data->name, "julia"))
	{
		z->x = c->x;
		z->y = c->y;
		c->x = data->julia_x;
		c->y = data->julia_y;
	}
	else
	{
		z->x = 0.0;
		z->y = 0.0;
	}
}

static int	iterate_burning(t_complex z, t_complex c)
{
	double	tmp;
	int		i;

	i = 0;
	while (i < MAX_ITER && (z.x * z.x + z.y * z.y) < 4.0)
	{
		z.x = fabs(z.x);
		z.y = fabs(z.y);
		tmp = z.x * z.x - z.y * z.y + c.x;
		z.y = 2 * z.x * z.y + c.y;
		z.x = tmp;
		i++;
	}
	return (i);
}

static int	iterate_classic(t_complex z, t_complex c)
{
	double	tmp;
	int		i;

	i = 0;
	while (i < MAX_ITER && (z.x * z.x + z.y * z.y) < 4.0)
	{
		tmp = z.x * z.x - z.y * z.y + c.x;
		z.y = 2 * z.x * z.y + c.y;
		z.x = tmp;
		i++;
	}
	return (i);
}

int	fractal_iter(double cx, double cy, t_data *data)
{
	t_complex	z;
	t_complex	c;

	c.x = cx;
	c.y = cy;
	init_values(&z, &c, data);
	if (!ft_strcmp(data->name, "burning_ship"))
		return (iterate_burning(z, c));
	return (iterate_classic(z, c));
}
