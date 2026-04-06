/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmesgari <mmesgari@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/05 21:26:02 by mmesgari          #+#    #+#             */
/*   Updated: 2026/04/05 21:26:13 by mmesgari         ###   ########.fr       */
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
	if (iter == MAX_ITER)
		return (0x000000);
	return (iter * 0x00080402);
}

void	render(t_data *data)
{
	int		x;
	int		y;
	int		i;
	double	zx;
	double	zy;
	double	cx;
	double	cy;
	double	tmp;

	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			cx = (x - WIDTH / 2.0) * (4.0 / (WIDTH * data->zoom)) + data->shift_x;
			cy = (y - HEIGHT / 2.0) * (4.0 / (HEIGHT * data->zoom)) + data->shift_y;
			if (data->name[0] == 'm')
			{
				zx = 0; zy = 0;
			}
			else
			{
				zx = cx; zy = cy;
				cx = data->julia_x; cy = data->julia_y;
			}
			i = -1;
			while (++i < MAX_ITER && (zx * zx + zy * zy) < 4.0)
			{
				tmp = zx * zx - zy * zy + cx;
				zy = 2 * zx * zy + cy;
				zx = tmp;
			}
			put_pixel(data, x, y, get_color(i));
		}
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
}