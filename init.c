/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmesgari <mmesgari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 16:28:40 by mmesgari          #+#    #+#             */
/*   Updated: 2026/04/15 16:29:07 by mmesgari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	data_init(t_data *data)
{
	data->mlx = NULL;
	data->win = NULL;
	data->img = NULL;
	data->addr = NULL;
	data->zoom = 1.0;
	data->shift_x = 0.0;
	data->shift_y = 0.0;
	data->julia_x = 0.0;
	data->julia_y = 0.0;
	data->color_shift = 0;
	data->name = NULL;
}

static int	init_julia(t_data *data, int ac, char **av)
{
	if (ac != 4)
		return (0);
	if (!is_valid_number(av[2]) || !is_valid_number(av[3]))
		return (0);
	data->julia_x = ft_atof(av[2]);
	data->julia_y = ft_atof(av[3]);
	return (1);
}

int	parse_args(t_data *data, int ac, char **av)
{
	if (ac < 2)
		return (0);
	if (!ft_strcmp(av[1], "mandelbrot") && ac == 2)
		data->name = "mandelbrot";
	else if (!ft_strcmp(av[1], "burning_ship") && ac == 2)
		data->name = "burning_ship";
	else if (!ft_strcmp(av[1], "julia"))
	{
		data->name = "julia";
		if (!init_julia(data, ac, av))
			return (0);
	}
	else
		return (0);
	return (1);
}

int	init_mlx(t_data *data)
{
	data->mlx = mlx_init();
	if (!data->mlx)
		return (0);
	data->win = mlx_new_window(data->mlx, WIDTH, HEIGHT, "fract-ol");
	if (!data->win)
		return (0);
	data->img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	if (!data->img)
		return (0);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel,
			&data->line_length, &data->endian);
	return (1);
}

void	setup_hooks(t_data *data)
{
	mlx_key_hook(data->win, key_hooks, data);
	mlx_mouse_hook(data->win, mouse_hooks, data);
	mlx_hook(data->win, 17, 0, clean_exit, data);
}
