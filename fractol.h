/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmesgari <mmesgari@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/05 21:25:11 by mmesgari          #+#    #+#             */
/*   Updated: 2026/04/05 21:25:15 by mmesgari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "minilibx-linux/mlx.h"
# include <stdlib.h>
# include <math.h>
# include <unistd.h>

# define WIDTH 800
# define HEIGHT 800
# define MAX_ITER 100

typedef struct s_data
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	double	zoom;
	double	shift_x;
	double	shift_y;
	double	julia_x;
	double	julia_y;
	char	*name;
}	t_data;

/* Render */
void	render(t_data *data);
int		get_color(int iter);
void	put_pixel(t_data *data, int x, int y, int color);

/* Events */
int		key_hooks(int keycode, t_data *data);
int		mouse_hooks(int button, int x, int y, t_data *data);
int		clean_exit(t_data *data);

/* Utils */
double	ft_atof(char *s);

#endif