/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmesgari <mmesgari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/05 21:25:11 by mmesgari          #+#    #+#             */
/*   Updated: 2026/04/15 16:26:36 by mmesgari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "minilibx-linux/mlx.h"
# include <stdlib.h>
# include <unistd.h>
# include <math.h>

# define WIDTH 800
# define HEIGHT 800
# define MAX_ITER 100

typedef struct s_complex
{
	double	x;
	double	y;
}	t_complex;

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
	int		color_shift;
	char	*name;
}	t_data;

void	data_init(t_data *data);
int		parse_args(t_data *data, int ac, char **av);
int		init_mlx(t_data *data);
void	setup_hooks(t_data *data);

int		clean_exit(t_data *data);
int		key_hooks(int keycode, t_data *data);
int		mouse_hooks(int button, int x, int y, t_data *data);

void	render(t_data *data);
void	put_pixel(t_data *data, int x, int y, int color);
int		get_color(t_data *data, int iter);
int		fractal_iter(double cx, double cy, t_data *data);

double	ft_atof(char *s);
int		ft_strcmp(char *s1, char *s2);
int		is_valid_number(char *s);
void	print_usage(void);

#endif