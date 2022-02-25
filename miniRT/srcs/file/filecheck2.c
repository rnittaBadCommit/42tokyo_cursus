/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filecheck2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 21:11:37 by marvin            #+#    #+#             */
/*   Updated: 2020/12/16 21:11:37 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../minirt.h"

int		check_obj6(t_all *all)
{
	t_objects	*obj;
	int			i;

	if (all->light.next)
	{
		obj = all->light.next;
		while (obj)
		{
			i = -1;
			while (++i < 3)
			{
				if (obj->rgb[i] < 0 || obj->rgb[i] > 255 ||
					obj->rgb[i] - (int)obj->rgb[i])
					return (-10);
			}
			if (obj->ratio < 0 || obj->ratio > 1)
				return (-12);
			obj = obj->next;
		}
	}
	return (0);
}

int		check_obj5(t_all *all)
{
	t_objects	*obj;
	int			i;

	if (all->camera_save.next)
	{
		obj = all->camera_save.next;
		while (obj)
		{
			if (dist_sq(obj->vec, NULL) == 0)
				return (-13);
			i = -1;
			while (++i < 3)
				if (obj->vec[i] < -1 || obj->vec[i] > 1)
					return (-13);
			if (obj->fov <= 0 || obj->fov > 180)
				return (-16);
			obj = obj->next;
		}
	}
	else
		return (-17);
	return (check_obj6(all));
}

int		check_file(t_all *all)
{
	int i;

	if (all->r_flag == 0)
		return (-30);
	if (all->a_flag == 0)
		return (-31);
	if (all->rx - (int)all->rx || all->ry - (int)all->ry)
		return (-11);
	if (!(all->ambi_light.ratio >= 0 && all->ambi_light.ratio <= 1))
		return (-12);
	i = -1;
	while (++i < 3)
		if (all->ambi_light.rgb[i] < 0 || all->ambi_light.rgb[i] > 255 ||
			all->ambi_light.rgb[i] - (int)all->ambi_light.rgb[i])
			return (-10);
	return (check_obj0(all));
}
