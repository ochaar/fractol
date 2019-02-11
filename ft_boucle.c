/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_boucle.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochaar <ochaar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 13:29:28 by ochaar            #+#    #+#             */
/*   Updated: 2019/01/18 12:44:54 by ochaar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "frac.h"

void	ft_loop(const t_data *frac, t_complex *c, int x, int y)
{
	int			res;

	if (frac->frac == 1)
		res = (ft_div_mandel(*c, frac->iter));
	if (frac->frac == 2)
		res = (ft_div_julia(*c, frac->iter, frac->julia));
	if (frac->frac == 3)
		res = (ft_div_leaf(*c, frac->iter));
	if (frac->frac == 4)
		res = (ft_div_burning(*c, frac->iter));
	if (frac->frac == 5)
		res = (ft_div_feigen(*c, frac->iter));
	frac->img_ptr[y * SCREEN_X + x] = ((1.0 * res * 0xFFFFFF) / frac->iter);
}
