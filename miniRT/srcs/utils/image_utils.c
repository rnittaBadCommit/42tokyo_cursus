/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 21:33:05 by marvin            #+#    #+#             */
/*   Updated: 2020/12/16 21:33:05 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../minirt.h"

void	make_images(t_all *all)
{
	char	*dest;

	dest = all->addr + (all->image_yx[0] * all->line
		+ all->image_yx[1] * (all->bpp / 8));
	*(unsigned int*)dest = rgb_to_int(all->ray.rgb);
}

int		rgb_to_int(double *rgb)
{
	int r;
	int g;
	int b;

	if ((r = (int)rgb[0]) >= 255)
		r = 255;
	if ((b = (int)rgb[2]) >= 255)
		b = 255;
	if ((g = (int)rgb[1]) >= 255)
		g = 255;
	if (r < 0)
		r = 0;
	if (b < 0)
		b = 0;
	if (g < 0)
		g = 0;
	return (r * pow(2, 16) + g * pow(2, 8) + b);
}
