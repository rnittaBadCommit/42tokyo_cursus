/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision_plane.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 21:12:38 by marvin            #+#    #+#             */
/*   Updated: 2020/12/20 02:17:04 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../minirt.h"

void	collision_plane(t_objects obj, t_ray *ray_save)
{
	t_ray	ray;
	double	tmp;

	if (ray_save->obj_num == obj.num)
		return ;
	ray = *ray_save;
	ray.s[0] -= obj.pos[0];
	ray.s[1] -= obj.pos[1];
	ray.s[2] -= obj.pos[2];
	normalize_vec(obj.vec);
	if ((tmp = inner_product(ray.d, obj.vec)))
	{
		tmp = -1 * inner_product(ray.s, obj.vec) / tmp;
		if (tmp <= 0 + MIN || tmp > ray_save->min_distance)
			return ;
		ray_save->min_distance = tmp;
		ray_save->colli_obj = obj;
	}
}
