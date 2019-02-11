/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bonus.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochaar <ochaar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 13:21:04 by ochaar            #+#    #+#             */
/*   Updated: 2019/01/16 12:47:46 by ochaar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "frac.h"

int		ft_div_leaf(t_complex c, int iter)
{
	t_complex	z;
	int			i;

	i = 0;
	z = 0;
	while (i < iter && cabs(z) <= 2)
	{
		z = ccos(z / c);
		i++;
	}
	return (i);
}

int		ft_div_burning(t_complex c, int iter)
{
	t_complex	z;
	int			i;

	i = 0;
	z = 0;
	while (cabs(z) <= 2 && i < iter)
	{
		z = z * z + c;
		z = fabs(creal(z)) + I * fabs(cimag(z));
		i++;
	}
	return (i);
}

int		ft_div_feigen(t_complex c, int iter)
{
	int			i;
	t_complex	z;
	t_complex	c3;

	i = 0;
	z = 0;
	c3 = c * c * c;
	while (cabs(z) <= 2 && i < iter)
	{
		z = z * z + c3 - 1.401155;
		i++;
	}
	return (i);
}
