/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmesgari <mmesgari@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/05 21:26:59 by mmesgari          #+#    #+#             */
/*   Updated: 2026/04/05 21:27:03 by mmesgari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	clean_exit(t_data *data)
{
	mlx_destroy_image(data->mlx, data->img);
	mlx_destroy_window(data->mlx, data->win);
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
	render(data);
	return (0);
}

int	mouse_hooks(int button, int x, int y, t_data *data)
{
	(void)x;
	(void)y;
	if (button == 4)
		data->zoom *= 1.2;
	else if (button == 5)
		data->zoom /= 1.2;
	render(data);
	return (0);
}

int	main(int ac, char **av)
{
	t_data	data;

	if (ac < 2 || (av[1][0] != 'm' && av[1][0] != 'j'))
	{
		write(1, "Usage: ./fractol mandelbrot OR julia\n", 37);
		return (1);
	}
	data.name = av[1];
	data.julia_x = -0.7;
	data.julia_y = 0.27;
	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, WIDTH, HEIGHT, "fract-ol");
	data.img = mlx_new_image(data.mlx, WIDTH, HEIGHT);
	data.addr = mlx_get_data_addr(data.img, &data.bits_per_pixel,
			&data.line_length, &data.endian);
	data.zoom = 1.0;
	data.shift_x = 0;
	data.shift_y = 0;
	render(&data);
	mlx_key_hook(data.win, (int (*)())key_hooks, &data);
	mlx_mouse_hook(data.win, (int (*)())mouse_hooks, &data);
	mlx_hook(data.win, 17, 0, (int (*)())clean_exit, &data);
	mlx_loop(data.mlx);
	return (0);
}