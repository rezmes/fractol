/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmesgari <mmesgari@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/05 21:26:02 by mmesgari          #+#    #+#             */
/*   Updated: 2026/04/06 15:34:45 by mmesgari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	put_pixel(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	get_color(int iter)
{
	double	t;
	int		r;
	int		g;
	int		b;

	if (iter == MAX_ITER)
		return (0x000000);
	t = (double)iter / MAX_ITER;
	r = (int)(9 * (1 - t) * t * t * t * 255);
	g = (int)(15 * (1 - t) * (1 - t) * t * t * 255);
	b = (int)(8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255);
	return (r << 16 | g << 8 | b);
}

static void	fractal_loop(int x, int y, t_data *d, double cx)
{
	double	zx;
	double	zy;
	double	cy;
	double	tmp;
	int		i;

	cy = (y - HEIGHT / 2.0) * (4.0 / (HEIGHT * d->zoom)) + d->shift_y;
	zx = 0;
	zy = 0;
	if (d->name[0] == 'j')
	{
		zx = cx;
		zy = cy;
		cx = d->julia_x;
		cy = d->julia_y;
	}
	i = -1;
	while (++i < MAX_ITER && (zx * zx + zy * zy) < 4.0)
	{
		tmp = zx * zx - zy * zy + cx;
		zy = 2 * zx * zy + cy;
		zx = tmp;
	}
	put_pixel(d, x, y, get_color(i));
}

void	render(t_data *data)
{
	int		x;
	int		y;
	double	pr;

	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			pr = (x - WIDTH / 2.0) * (4.0 / (WIDTH * data->zoom));
			fractal_loop(x, y, data, pr + data->shift_x);
		}
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
}
