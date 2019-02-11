/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochaar <ochaar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/06 10:19:44 by ochaar            #+#    #+#             */
/*   Updated: 2019/01/21 13:19:26 by ochaar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "frac.h"

void		*ft_algo(t_worker_arg *arg)
{
	t_complex		c;
	int				x;
	int				y;
	const t_data	*frac = arg->frac;

	y = arg->start_y - 1;
	while (++y < arg->end_y)
	{
		x = -1;
		while (++x < SCREEN_X)
		{
			c = (x / (double)frac->zoom + (frac->screenx)) + ((y
			/ (double)frac->zoom + (frac->screeny)) * I);
			ft_loop(frac, &c, x, y);
		}
	}
	return (NULL);
}

int			render(t_data *frac)
{
	pthread_t		threads[NBR_THREADS];
	t_worker_arg	args[NBR_THREADS];
	int				i;

	frac->screeny = -(SCREEN_Y / (double)(frac->zoom * 2) + frac->position_y)
		+ frac->ymouse / 2;
	frac->screenx = -(SCREEN_X / (double)(frac->zoom * 2) + frac->position_x)
		+ frac->xmouse / 2;
	i = 0;
	while (i < NBR_THREADS)
	{
		args[i] = (t_worker_arg)
		{
			.frac = frac,
			.start_y = i * (SCREEN_Y / (float)NBR_THREADS),
			.end_y = (i + 1) * (SCREEN_Y / (float)NBR_THREADS)
		};
		pthread_create(&(threads[i]), NULL, (void*)ft_algo, args + i);
		i++;
	}
	while (i--)
		pthread_join(threads[i], NULL);
	mlx_put_image_to_window(frac->mlx, frac->win, frac->img, 0, 0);
	return (0);
}

static int	deal_key(int key, t_data *frac)
{
	if (key == KEY_PLUS)
	{
		frac->iter++;
		printf("%d\n", frac->iter);
	}
	if (key == 49)
		frac->lock = frac->lock == 0 ? 1 : 0;
	if (key == KEY_UP)
		frac->position_y += (20 / frac->zoom);
	if (key == KEY_DOWN)
		frac->position_y -= (20 / frac->zoom);
	if (key == KEY_RIGHT)
		frac->position_x += (20 / frac->zoom);
	if (key == KEY_LEFT)
		frac->position_x -= (20 / frac->zoom);
	if (key == KEY_ESC)
		exit(0);
	mlx_destroy_image(frac->mlx, frac->img);
	frac->img = mlx_new_image(frac->mlx, SCREEN_X, SCREEN_Y);
	frac->img_ptr = (int*)mlx_get_data_addr(frac->img, &key, &key, &key);
	render(frac);
	return (0);
}

static int	mouse_hook(int button, int x, int y, t_data *frac)
{
	if (button == 4 || button == 1)
	{
		frac->xmouse = x / (double)frac->zoom - (SCREEN_X
		/ (double)(frac->zoom * 2) + frac->position_x) + frac->xmouse;
		frac->ymouse = y / (double)frac->zoom - (SCREEN_Y
		/ (double)(frac->zoom * 2) + frac->position_y) + frac->ymouse;
		frac->position_y = 0;
		frac->position_x = 0;
		frac->zoom = frac->zoom * 2;
	}
	if (button == 5 || button == 2)
		frac->zoom = frac->zoom * 0.5;
	render(frac);
	return (0);
}

int			main(int argc, char **argv)
{
	t_data	frac;
	int		i;

	i = 5;
	if (argc == 2)
	{
		ft_verif(argv, &frac);
		ft_init(&frac);
		frac.img_ptr = (int *)mlx_get_data_addr(frac.img, &i, &i, &i);
		render(&frac);
		mlx_key_hook(frac.win, deal_key, &frac);
		mlx_mouse_hook(frac.win, mouse_hook, &frac);
		mlx_hook(frac.win, 6, (1L << 6), funct, &frac);
		mlx_loop(frac.mlx);
	}
	else
		ft_error(1);
	return (0);
}
