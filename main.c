/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmesgari <mmesgari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/05 21:26:59 by mmesgari          #+#    #+#             */
/*   Updated: 2026/04/15 15:25:45 by mmesgari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	clean_exit(t_data *data)
{
	if (data->img)
		mlx_destroy_image(data->mlx, data->img);
	if (data->win)
		mlx_destroy_window(data->mlx, data->win);
#ifdef __linux__
	if (data->mlx)
	{
		mlx_destroy_display(data->mlx);
		free(data->mlx);
	}
#endif
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
		data->color_shift += 10;
	else if (keycode == 120)
		data->color_shift -= 10;
	else
		return (0);
	render(data);
	return (0);
}

int	mouse_hooks(int button, int x, int y, t_data *data)
{
	double	m_re;
	double	m_im;

	m_re = (x - WIDTH / 2.0) * (4.0 / (WIDTH * data->zoom)) + data->shift_x;
	m_im = (y - HEIGHT / 2.0) * (4.0 / (HEIGHT * data->zoom)) + data->shift_y;
	if (button == 4)
		data->zoom *= 1.2;
	else if (button == 5)
		data->zoom /= 1.2;
	else
		return (0);
	data->shift_x = m_re - (x - WIDTH / 2.0) * (4.0 / (WIDTH * data->zoom));
	data->shift_y = m_im - (y - HEIGHT / 2.0) * (4.0 / (HEIGHT * data->zoom));
	render(data);
	return (0);
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

static int	parse_args(t_data *data, int ac, char **av)
{
	if (ac < 2)
		return (0);
	if (!ft_strcmp(av[1], "mandelbrot"))
		data->name = "mandelbrot";
	else if (!ft_strcmp(av[1], "burning_ship"))
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

static int	init_mlx(t_data *data)
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

int	main(int ac, char **av)
{
	t_data	data;

	data.mlx = NULL;
	data.win = NULL;
	data.img = NULL;
	data.addr = NULL;
	data.zoom = 1.0;
	data.shift_x = 0.0;
	data.shift_y = 0.0;
	data.color_shift = 0;
	if (!parse_args(&data, ac, av))
	{
		print_usage();
		return (1);
	}
	if (!init_mlx(&data))
	{
		write(2, "Error: mlx init failed\n", 23);
		clean_exit(&data);
	}
	render(&data);
	mlx_key_hook(data.win, (int (*)())key_hooks, &data);
	mlx_mouse_hook(data.win, (int (*)())mouse_hooks, &data);
	mlx_hook(data.win, 17, 0, (int (*)())clean_exit, &data);
	mlx_loop(data.mlx);
	return (0);
}
