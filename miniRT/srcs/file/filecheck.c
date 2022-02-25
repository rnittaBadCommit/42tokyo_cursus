/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filecheck.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 21:19:28 by marvin            #+#    #+#             */
/*   Updated: 2020/12/16 21:19:28 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../minirt.h"

int	check_obj4(t_all *all)
{
	t_objects	*obj;
	int			i;
	double		tmp_vec[3];

	if (all->object[4].next)
	{
		obj = all->object[4].next;
		while (obj)
		{
			i = -1;
			while (++i < 3)
			{
				if (obj->rgb[i] < 0 || obj->rgb[i] > 255 ||
					obj->rgb[i] - (int)obj->rgb[i])
					return (-10);
				vec_diff(tmp_vec, obj->vert[i],
					obj->vert[(i + 1 <= 2 ? i + 1 : 0)]);
				if (dist_sq(tmp_vec, NULL) == 0)
					return (-15);
			}
			obj = obj->next;
		}
	}
	return (check_obj5(all));
}

int	check_obj3(t_all *all)
{
	t_objects	*obj;
	int			i;

	if (all->object[3].next)
	{
		obj = all->object[3].next;
		while (obj && (i = -1))
		{
			if (dist_sq(obj->vec, NULL) == 0)
				return (-13);
			while (++i < 3)
			{
				if (obj->rgb[i] < 0 || obj->rgb[i] > 255 ||
					obj->rgb[i] - (int)obj->rgb[i])
					return (-10);
				if (obj->vec[i] < -1 || obj->vec[i] > 1)
					return (-13);
			}
			if (obj->size <= 0 || obj->r <= 0)
				return (-14);
			obj = obj->next;
		}
	}
	return (check_obj4(all));
}

int	check_obj2(t_all *all)
{
	t_objects	*obj;
	int			i;

	if (all->object[2].next)
	{
		obj = all->object[2].next;
		while (obj && (i = -1))
		{
			if (dist_sq(obj->vec, NULL) == 0)
				return (-13);
			while (++i < 3)
			{
				if (obj->rgb[i] < 0 || obj->rgb[i] > 255 ||
					obj->rgb[i] - (int)obj->rgb[i])
					return (-10);
				if (obj->vec[i] < -1 || obj->vec[i] > 1)
					return (-13);
			}
			if (obj->size <= 0)
				return (-14);
			obj = obj->next;
		}
	}
	return (check_obj3(all));
}

int	check_obj1(t_all *all)
{
	t_objects	*obj;
	int			i;

	if (all->object[1].next)
	{
		obj = all->object[1].next;
		while (obj)
		{
			if (dist_sq(obj->vec, NULL) == 0)
				return (-13);
			i = -1;
			while (++i < 3)
			{
				if (obj->rgb[i] < 0 || obj->rgb[i] > 255 ||
					obj->rgb[i] - (int)obj->rgb[i])
					return (-10);
				if (obj->vec[i] < -1 || obj->vec[i] > 1)
					return (-13);
			}
			obj = obj->next;
		}
	}
	return (check_obj2(all));
}

int	check_obj0(t_all *all)
{
	t_objects	*obj;
	int			i;

	if (all->object[0].next)
	{
		obj = all->object[0].next;
		while (obj)
		{
			if (obj->r <= 0)
				return (-14);
			i = -1;
			while (++i < 3)
				if (obj->rgb[i] < 0 || obj->rgb[i] > 255 ||
					obj->rgb[i] - (int)obj->rgb[i])
					return (-10);
			obj = obj->next;
		}
	}
	return (check_obj1(all));
}
