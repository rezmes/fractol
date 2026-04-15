/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmesgari <mmesgari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 16:29:50 by mmesgari          #+#    #+#             */
/*   Updated: 2026/04/15 16:30:22 by mmesgari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	clean_exit(t_data *data)
{
	if (data->img)
		mlx_destroy_image(data->mlx, data->img);
	if (data->win)
		mlx_destroy_window(data->mlx, data->win);
	if (data->mlx)
	{
		mlx_destroy_display(data->mlx);
		free(data->mlx);
	}
	exit(0);
	return (0);
}

int	key_hooks(int keycode, t_data *data)
{
	if (keycode == 65307)
		clean_exit(data);
	else if (keycode == 65361)
		data->shift_x -= 0.1 / data->zoom;
	else if (keycode == 65363)
		data->shift_x += 0.1 / data->zoom;
	else if (keycode == 65362)
		data->shift_y -= 0.1 / data->zoom;
	else if (keycode == 65364)
		data->shift_y += 0.1 / data->zoom;
	else if (keycode == 99)
		data->color_shift += 25;
	else if (keycode == 120)
		data->color_shift -= 25;
	else
		return (0);
	render(data);
	return (0);
}

int	mouse_hooks(int button, int x, int y, t_data *data)
{
	double	mx;
	double	my;

	mx = (x - WIDTH / 2.0) * (4.0 / (WIDTH * data->zoom)) + data->shift_x;
	my = (y - HEIGHT / 2.0) * (4.0 / (HEIGHT * data->zoom)) + data->shift_y;
	if (button == 4)
		data->zoom *= 1.2;
	else if (button == 5)
		data->zoom /= 1.2;
	else
		return (0);
	data->shift_x = mx - (x - WIDTH / 2.0) * (4.0 / (WIDTH * data->zoom));
	data->shift_y = my - (y - HEIGHT / 2.0) * (4.0 / (HEIGHT * data->zoom));
	render(data);
	return (0);
}
