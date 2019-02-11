/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frac.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochaar <ochaar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/29 13:58:31 by ochaar            #+#    #+#             */
/*   Updated: 2019/01/21 13:20:42 by ochaar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAC_H
# define FRAC_H

# include <math.h>
# include <pthread.h>
# include "mlx.h"
# include "libft/libft.h"
# include <complex.h>
#include <stdio.h>

# define NBR_THREADS 60
# define KEY_PLUS 69
# define KEY_UP 125
# define KEY_DOWN 126
# define KEY_LEFT 123
# define KEY_RIGHT 124
# define KEY_ESC 53
# define SCREEN_X 1000
# define SCREEN_Y 1000

typedef _Complex double	t_complex;

typedef struct			s_data
{
	void		*mlx;
	void		*win;
	void		*img;
	int			*img_ptr;

	double		zoom;
	double		position_y;
	double		position_x;
	int			frac;
	t_complex	julia;
	int			lock;

	double		xmouse;
	double		ymouse;
	int			x;
	int			y;
	double		screeny;
	double		screenx;
	int			iter;
}						t_data;

typedef struct			s_worker_arg
{
	t_data		*frac;
	int			start_y;
	int			end_y;
}						t_worker_arg;

void					ft_error(int x);
int						ft_div_mandel(t_complex c, int iter);
int						ft_div_julia(t_complex z, int iter, t_complex c);
int						funct(int x, int y, t_data *frac);
void					*ft_algo(t_worker_arg *arg);
int						ft_div_leaf(t_complex c, int iter);
int						ft_div_burning(t_complex c, int iter);
int						ft_div_feigen(t_complex c, int iter);
int						render(t_data *frac);
void					ft_loop(const t_data *frac, t_complex *c, int x, int y);
void					ft_verif(char **argv, t_data *frac);
void					ft_init(t_data *frac);

#endif
