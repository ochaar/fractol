/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_verif.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochaar <ochaar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 13:42:32 by ochaar            #+#    #+#             */
/*   Updated: 2019/01/21 13:25:44 by ochaar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "frac.h"

void	ft_verif(char **argv, t_data *frac)
{
	if (ft_strcmp(argv[1], "mandel") == 0)
		frac->frac = 1;
	else if (ft_strcmp(argv[1], "julia") == 0)
		frac->frac = 2;
	else if (ft_strcmp(argv[1], "bonus2") == 0)
		frac->frac = 3;
	else if (ft_strcmp(argv[1], "bonus1") == 0)
		frac->frac = 4;
	else if (ft_strcmp(argv[1], "bonus3") == 0)
		frac->frac = 5;
	else
		ft_error(1);
}

void	ft_init(t_data *frac)
{
	frac->xmouse = 0;
	frac->ymouse = 0;
	frac->zoom = (SCREEN_X + SCREEN_Y) / 8;
	frac->julia = 0;
	frac->position_x = 0;
	frac->position_y = 0;
	frac->iter = 100;
	frac->lock = 1;
	frac->mlx = mlx_init();
	frac->win = mlx_new_window(frac->mlx, SCREEN_X, SCREEN_Y, "FRACTOL");
	frac->img = mlx_new_image(frac->mlx, SCREEN_X, SCREEN_Y);
}
