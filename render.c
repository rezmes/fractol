/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmesgari <mmesgari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/05 21:26:02 by mmesgari          #+#    #+#             */
/*   Updated: 2026/04/15 16:43:37 by mmesgari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	put_pixel(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x
			* (data->bits_per_pixel / 8));
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
	r = ((int)(9 * (1 - t) * t * t * t * 255)
			+ data->color_shift) % 256;
	g = ((int)(15 * (1 - t) * (1 - t) * t * t * 255)
			+ data->color_shift) % 256;
	b = ((int)(8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255)
			+ data->color_shift) % 256;
	if (r < 0)
		r += 256;
	if (g < 0)
		g += 256;
	if (b < 0)
		b += 256;
	return (r << 16 | g << 8 | b);
}

void	render(t_data *data)
{
	int		x;
	int		y;
	double	cx;
	double	cy;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			cx = (x - WIDTH / 2.0) * (4.0 / (WIDTH * data->zoom));
			cy = (y - HEIGHT / 2.0) * (4.0 / (HEIGHT * data->zoom));
			cx += data->shift_x;
			cy += data->shift_y;
			put_pixel(data, x, y, get_color(data, fractal_iter(cx, cy, data)));
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
}
