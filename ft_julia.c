/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_julia.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochaar <ochaar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 13:09:04 by ochaar            #+#    #+#             */
/*   Updated: 2019/01/17 13:55:30 by ochaar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "frac.h"

int		ft_div_julia(t_complex z, int iter, t_complex c)
{
	int			i;

	i = 0;
	while (i < iter && cabs(z) <= 2)
	{
		z = z * z + c;
		i++;
	}
	return (i);
}

int		funct(int x, int y, t_data *frac)
{
	if (frac->lock == 0)
	{
		frac->julia = x / 200.0 - 2.5 + ((y / 200.0 - 2.5) * I);
		render(frac);
	}
	return (0);
}
