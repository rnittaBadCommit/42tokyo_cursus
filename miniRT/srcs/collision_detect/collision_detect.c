/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision_detect.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 21:23:31 by marvin            #+#    #+#             */
/*   Updated: 2020/12/16 22:26:21 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../minirt.h"

void	collision_detect3(t_all all, t_ray *ray)
{
	t_objects *obj;

	if (all.object[4].next)
	{
		obj = all.object[4].next;
		while (obj)
		{
			collision_triangle(*obj, ray);
			obj = obj->next;
		}
	}
}

void	collision_detect2(t_all all, t_ray *ray)
{
	t_objects *obj;

	if (all.object[2].next)
	{
		obj = all.object[2].next;
		while (obj)
		{
			collision_square(*obj, ray);
			obj = obj->next;
		}
	}
	if (all.object[3].next)
	{
		obj = all.object[3].next;
		while (obj)
		{
			collision_cylinder(*obj, ray);
			obj = obj->next;
		}
	}
}

void	collision_detect1(t_all all, t_ray *ray)
{
	t_objects *obj;

	if (all.object[0].next)
	{
		obj = all.object[0].next;
		while (obj)
		{
			collision_sphere(*obj, ray);
			obj = obj->next;
		}
	}
	if (all.object[1].next)
	{
		obj = all.object[1].next;
		while (obj)
		{
			collision_plane(*obj, ray);
			obj = obj->next;
		}
	}
}

int		collision_detect_main(t_all all, t_ray *ray)
{
	collision_detect1(all, ray);
	collision_detect2(all, ray);
	collision_detect3(all, ray);
	if (ray->colli_obj.type == -1)
		return (0);
	else
		return (1);
}
