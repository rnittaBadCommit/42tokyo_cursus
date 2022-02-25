/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 21:59:24 by marvin            #+#    #+#             */
/*   Updated: 2020/12/16 22:03:49 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../minirt.h"

void	make_screen_yx_vec(t_all *all, double *y, double *x)
{
	if (all->camera.vec[0] || all->camera.vec[1])
	{
		x[2] = 0;
		x[0] = pow(all->camera.vec[1], 2) /
			(pow(all->camera.vec[0], 2) + pow(all->camera.vec[1], 2));
		x[0] = -1 * sqrt(x[0]);
		x[1] = (all->camera.vec[1] ? x[0] * all->camera.vec[0] * -1
			/ all->camera.vec[1] : 1);
	}
	else
	{
		x[0] = 0;
		x[1] = pow(all->camera.vec[2], 2) /
			(pow(all->camera.vec[1], 2) + pow(all->camera.vec[2], 2));
		x[1] = -1 * sqrt(x[1]);
		x[2] = (all->camera.vec[2] ? x[1] * all->camera.vec[1] * -1
			/ all->camera.vec[2] : 1);
	}
	cross_product(y, x, all->camera.vec);
	normalize_vec(y);
}

void	make_ray(t_all *all, double *screen_yx_pos,
	double screen_yx_vec[2][3], double t)
{
	int i;

	copy_vec(all->ray.s, all->camera.pos);
	i = -1;
	while (++i < 3)
	{
		all->ray.d[i] = all->camera.vec[i] * t;
		all->ray.d[i] += screen_yx_pos[0] * screen_yx_vec[0][i];
		all->ray.d[i] += screen_yx_pos[1] * screen_yx_vec[1][i];
	}
	normalize_vec(all->ray.d);
	all->ray.colli_obj.type = -1;
	all->ray.min_distance = INF;
	all->ray.obj_num = -1;
}
