/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_to_light.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 22:03:26 by marvin            #+#    #+#             */
/*   Updated: 2020/12/19 18:59:57 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../minirt.h"

void	make_n_vec2(t_ray ray, t_ray new_ray, double *n)
{
	double tmp_vec[2][3];

	if (ray.colli_obj.type == 3)
	{
		vec_diff(tmp_vec[0], new_ray.s, ray.colli_obj.pos);
		cross_product(tmp_vec[1], tmp_vec[0], ray.colli_obj.vec);
		cross_product(n, ray.colli_obj.vec, tmp_vec[1]);
		if (ray.inout_flag == 1)
			reverse_vec(n);
	}
}

void	make_n_vec(t_ray ray, t_ray new_ray, double *n)
{
	if (ray.colli_obj.type == 0)
		vec_diff(n, new_ray.s, ray.colli_obj.pos);
	else if (ray.colli_obj.type == 1 ||
		ray.colli_obj.type == 2 || ray.colli_obj.type == 4)
	{
		copy_vec(n, ray.colli_obj.vec);
		if (inner_product(ray.d, ray.colli_obj.vec) > 0)
			reverse_vec(n);
	}
	else
		make_n_vec2(ray, new_ray, n);
}

void	ray_to_light(t_all *all, t_ray new_ray, t_objects light)
{
	t_objects	obj;
	double		n[3];
	double		cos_sq;
	double		cosr_sq;
	int			i;

	i = -1;
	obj = all->ray.colli_obj;
	make_n_vec(all->ray, new_ray, n);
	if (!collision_detect_main(*all, &new_ray))
	{
		cos_sq = sqrt(ft_cos_sq(n, new_ray.d));
		cosr_sq = ft_cosr_sq(n, all->ray, new_ray);
		while (++i < 3)
		{
			all->ray.rgb[i] += light.ratio * light.rgb[i] * obj.rgb[i] *
				cos_sq / 255;
			all->ray.rgb[i] += light.ratio * light.rgb[1] * obj.rgb[i] *
				pow(cosr_sq, 7) / 255;
		}
	}
}

void	make_ray_to_light(t_all *all)
{
	t_objects	*tmp_light;
	t_ray		new_ray;
	double		pos[3];

	pos[0] = all->ray.s[0] + all->ray.min_distance * all->ray.d[0];
	pos[1] = all->ray.s[1] + all->ray.min_distance * all->ray.d[1];
	pos[2] = all->ray.s[2] + all->ray.min_distance * all->ray.d[2];
	copy_vec(new_ray.s, pos);
	new_ray.obj_num = all->ray.colli_obj.num;
	if ((tmp_light = all->light.next))
		while (tmp_light)
		{
			vec_diff(new_ray.d, tmp_light->pos, pos);
			if (zero(dist_sq(new_ray.d, NULL)) && (all->err_flag = 1))
				return ;
			normalize_vec(new_ray.d);
			new_ray.colli_obj.type = -1;
			new_ray.min_distance =
				sqrt(dist_sq(new_ray.s, tmp_light->pos)) - MIN;
			ray_to_light(all, new_ray, *tmp_light);
			tmp_light = tmp_light->next;
		}
}

void	make_ambi_light(t_all *all)
{
	all->ray.rgb[0] = all->ray.colli_obj.rgb[0] *
		all->ambi_light.rgb[0] * all->ambi_light.ratio / 255;
	all->ray.rgb[1] = all->ray.colli_obj.rgb[1] *
		all->ambi_light.rgb[1] * all->ambi_light.ratio / 255;
	all->ray.rgb[2] = all->ray.colli_obj.rgb[2] *
		all->ambi_light.rgb[2] * all->ambi_light.ratio / 255;
}
