/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision_triangle_square.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 21:17:45 by marvin            #+#    #+#             */
/*   Updated: 2020/12/20 02:12:40 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../minirt.h"

int		collision_triangle2(t_objects obj, t_ray *ray_save)
{
	double e[3][3];
	double tmp;
	double tmpv[3];
	double uv[2];

	vec_diff(e[0], ray_save->s, obj.vert[0]);
	vec_diff(e[1], obj.vert[1], obj.vert[0]);
	vec_diff(e[2], obj.vert[2], obj.vert[0]);
	cross_product(tmpv, ray_save->d, e[2]);
	if (!(tmp = inner_product(tmpv, e[1])))
		return (0);
	cross_product(tmpv, ray_save->d, e[2]);
	uv[0] = inner_product(tmpv, e[0]) / tmp;
	cross_product(tmpv, e[0], e[1]);
	uv[1] = inner_product(tmpv, ray_save->d) / tmp;
	if (uv[0] >= 0 && uv[1] >= 0 && uv[0] + uv[1] <= 1)
		return (1);
	return (0);
}

void	collision_triangle(t_objects obj, t_ray *ray_save)
{
	t_ray	ray;
	double	tmp;

	if (ray_save->obj_num == obj.num)
		return ;
	ray = *ray_save;
	ray.s[0] -= obj.vert[0][0];
	ray.s[1] -= obj.vert[0][1];
	ray.s[2] -= obj.vert[0][2];
	if ((tmp = inner_product(ray.d, obj.vec)))
	{
		tmp = -1 * inner_product(ray.s, obj.vec) / tmp;
		if (tmp <= 0 || tmp > ray_save->min_distance)
			return ;
		if (collision_triangle2(obj, ray_save))
		{
			ray_save->min_distance = tmp;
			ray_save->colli_obj = obj;
		}
	}
}

int		collision_square2(t_objects obj, t_ray *ray_save)
{
	double e[3][3];
	double tmp;
	double tmpv[3];
	double uv[2];

	vec_diff(e[0], ray_save->s, obj.vert[0]);
	vec_diff(e[1], obj.vert[1], obj.vert[0]);
	vec_diff(e[2], obj.vert[2], obj.vert[0]);
	cross_product(tmpv, ray_save->d, e[2]);
	if (!(tmp = inner_product(tmpv, e[1])))
		return (0);
	cross_product(tmpv, ray_save->d, e[2]);
	uv[0] = inner_product(tmpv, e[0]) / tmp;
	cross_product(tmpv, e[0], e[1]);
	uv[1] = inner_product(tmpv, ray_save->d) / tmp;
	if (uv[0] >= 0 && uv[1] >= 0 && uv[0] <= 1 && uv[1] <= 1)
		return (1);
	return (0);
}

void	collision_square(t_objects obj, t_ray *ray_save)
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
		if (tmp <= 0 || tmp > ray_save->min_distance)
			return ;
		if (collision_square2(obj, ray_save))
		{
			ray_save->min_distance = tmp;
			ray_save->colli_obj = obj;
		}
	}
}
