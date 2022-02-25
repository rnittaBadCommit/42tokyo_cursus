/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision_sphere_cylinder.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 21:32:06 by marvin            #+#    #+#             */
/*   Updated: 2020/12/20 02:26:36 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../minirt.h"

void	collision_cylinder3(t_objects obj, t_ray *ray_save, double *t)
{
	double p[3];
	double tmp;
	double tmp_vec[3];

	p[0] = ray_save->s[0] + t[1] * ray_save->d[0];
	p[1] = ray_save->s[1] + t[1] * ray_save->d[1];
	p[2] = ray_save->s[2] + t[1] * ray_save->d[2];
	vec_diff(tmp_vec, p, obj.pos);
	tmp = inner_product(tmp_vec, obj.vec);
	if (tmp > MIN && tmp <= obj.size && t[1] > MIN &&
		t[1] < ray_save->min_distance && ray_save->obj_num != obj.num)
	{
		ray_save->colli_obj = obj;
		ray_save->inout_flag = 1;
		ray_save->min_distance = t[1];
	}
}

void	collision_cylinder2(t_objects obj, t_ray *ray_save, double *t)
{
	double p[3];
	double tmp;
	double tmp_vec[3];

	p[0] = ray_save->s[0] + t[0] * ray_save->d[0];
	p[1] = ray_save->s[1] + t[0] * ray_save->d[1];
	p[2] = ray_save->s[2] + t[0] * ray_save->d[2];
	vec_diff(tmp_vec, p, obj.pos);
	tmp = inner_product(tmp_vec, obj.vec);
	if (tmp > MIN && tmp <= obj.size && t[0] > MIN &&
		t[0] < ray_save->min_distance && ray_save->obj_num != obj.num)
	{
		ray_save->colli_obj = obj;
		ray_save->inout_flag = 0;
		ray_save->min_distance = t[0];
	}
	else
		collision_cylinder3(obj, ray_save, t);
}

void	collision_cylinder(t_objects obj, t_ray *ray_save)
{
	double tmp[4];
	double tmp_vec[3][3];
	double t[2];

	normalize_vec(obj.vec);
	vec_diff(tmp_vec[2], ray_save->s, obj.pos);
	cross_product(tmp_vec[0], ray_save->d, obj.vec);
	cross_product(tmp_vec[1], tmp_vec[2], obj.vec);
	if (!(tmp[0] = dist_sq(tmp_vec[0], NULL)))
		return ;
	tmp[1] = inner_product(tmp_vec[0], tmp_vec[1]);
	tmp[2] = dist_sq(tmp_vec[1], NULL) - obj.r * obj.r;
	if ((tmp[3] = tmp[1] * tmp[1] - tmp[0] * tmp[2]) < 0)
		return ;
	t[0] = (-1 * tmp[1] - sqrt(tmp[3])) / tmp[0];
	t[1] = (-1 * tmp[1] + sqrt(tmp[3])) / tmp[0];
	collision_cylinder2(obj, ray_save, t);
}

void	collision_sphere2(t_objects obj, t_ray *ray_save, double *tmp)
{
	tmp[4] = (-1 * tmp[1] - sqrt(tmp[3])) / tmp[0];
	if (tmp[4] >= MIN && ray_save->obj_num != obj.num)
	{
		if (tmp[4] < ray_save->min_distance)
		{
			ray_save->min_distance = tmp[4];
			ray_save->colli_obj = obj;
		}
		return ;
	}
	tmp[4] = (-1 * tmp[1] + sqrt(tmp[3])) / tmp[0];
	if (tmp[4] >= MIN)
	{
		ray_save->colli_obj = obj;
		ray_save->min_distance = 0;
	}
}

void	collision_sphere(t_objects obj, t_ray *ray_save)
{
	t_ray	ray;
	double	tmp[5];

	if (ray_save->obj_num == obj.num)
		return ;
	ray = *ray_save;
	ray.s[0] -= obj.pos[0];
	ray.s[1] -= obj.pos[1];
	ray.s[2] -= obj.pos[2];
	tmp[0] = dist_sq(ray.d, NULL);
	tmp[1] = inner_product(ray.s, ray.d);
	tmp[2] = dist_sq(ray.s, NULL) - pow(obj.r, 2);
	if ((tmp[3] = tmp[1] * tmp[1] - tmp[0] * tmp[2]) >= 0)
		collision_sphere2(obj, ray_save, tmp);
}
