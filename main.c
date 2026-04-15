/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmesgari <mmesgari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/05 21:26:59 by mmesgari          #+#    #+#             */
/*   Updated: 2026/04/15 16:46:18 by mmesgari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int ac, char **av)
{
	t_data	data;

	data_init(&data);
	if (!parse_args(&data, ac, av))
	{
		print_usage();
		return (1);
	}
	if (!init_mlx(&data))
	{
		write(2, "Error: mlx init failed\n", 23);
		return (1);
	}
	render(&data);
	setup_hooks(&data);
	mlx_loop(data.mlx);
	return (0);
}
