/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmesgari <mmesgari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/05 21:26:02 by mmesgari          #+#    #+#             */
/*   Updated: 2026/04/15 15:34:26 by mmesgari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	put_pixel(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	get_color(t_data *data, int iter)
{
	double	t;
	int		r;
	int		g;
	int		b;

	if (iter == MAX_ITER)
		return (0x000000);
	t = (double)iter / MAX_ITER;
r = ((int)(9 * (1 - t) * t * t * t * 255) + data->color_shift) % 256;
g = ((int)(15 * (1 - t) * (1 - t) * t * t * 255) + data->color_shift * 2) % 256;
b = ((int)(8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255) + data->color_shift * 3) % 256;	if (r < 0)
		r += 256;
	if (g < 0)
		g += 256;
	if (b < 0)
		b += 256;
	return (r << 16 | g << 8 | b);
}

static int	mandelbrot_or_julia(double *zx, double *zy, double *cx, double *cy,
		t_data *d)
{
	if (!ft_strcmp(d->name, "julia"))
	{
		*zx = *cx;
		*zy = *cy;
		*cx = d->julia_x;
		*cy = d->julia_y;
	}
	else
	{
		*zx = 0;
		*zy = 0;
	}
	return (0);
}

static int	fractal_iter(double cx, double cy, t_data *d)
{
	double	zx;
	double	zy;
	double	tmp;
	double	azx;
	double	azy;
	int		i;

	mandelbrot_or_julia(&zx, &zy, &cx, &cy, d);
	i = 0;
	while (i < MAX_ITER && (zx * zx + zy * zy) < 4.0)
	{
		if (!ft_strcmp(d->name, "burning_ship"))
		{
			azx = fabs(zx);
			azy = fabs(zy);
			tmp = azx * azx - azy * azy + cx;
			zy = 2 * azx * azy + cy;
			zx = tmp;
		}
		else
		{
			tmp = zx * zx - zy * zy + cx;
			zy = 2 * zx * zy + cy;
			zx = tmp;
		}
		i++;
	}
	return (i);
}

void	render(t_data *data)
{
	int		x;
	int		y;
	double	cx;
	double	cy;
	int		iter;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			cx = (x - WIDTH / 2.0) * (4.0 / (WIDTH * data->zoom))
				+ data->shift_x;
			cy = (y - HEIGHT / 2.0) * (4.0 / (HEIGHT * data->zoom))
				+ data->shift_y;
			iter = fractal_iter(cx, cy, data);
			put_pixel(data, x, y, get_color(data, iter));
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
}