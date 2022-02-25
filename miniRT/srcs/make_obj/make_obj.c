/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_obj.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 21:50:41 by marvin            #+#    #+#             */
/*   Updated: 2020/12/16 22:42:14 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../minirt.h"

int	make_obj3(char **s, t_all *all, int *flag, t_objects **tail)
{
	if (**s == 'l' && (*(*s + 1) == ' ' || *(*s + 1) == '\t'))
	{
		*s += 2;
		if (!(tail[6]->next = (t_objects *)malloc(sizeof(t_objects))))
			return (-2);
		tail[6] = tail[6]->next;
		obj_input_3(tail[6]->pos, s, flag);
		tail[6]->ratio = ft_atoi(s, flag);
		obj_input_3(tail[6]->rgb, s, flag);
		tail[6]->next = NULL;
		tail[6]->type = 6;
		tail[6]->num = all->obj_num;
		all->obj_num++;
		while (**s != 0 && **s != '\n')
		{
			(*s)++;
			if (**s != ' ' && **s != '\t' && **s != '\n')
				return (-200);
		}
	}
	else
		return (make_obj3_2(s, all, flag, tail));
	return (0);
}

int	make_obj10(char **s, t_all *all, int *flag, t_objects **tail)
{
	if (**s == 'c' && (*(*s + 1) == ' ' || *(*s + 1) == '\t'))
	{
		*s += 2;
		if (!(tail[5]->next = (t_objects *)malloc(sizeof(t_objects))))
			return (-2);
		tail[5] = tail[5]->next;
		obj_input_3(tail[5]->pos, s, flag);
		obj_input_3(tail[5]->vec, s, flag);
		tail[5]->fov = ft_atoi(s, flag);
		tail[5]->next = NULL;
		tail[5]->type = 5;
		while (**s != 0 && **s != '\n')
		{
			(*s)++;
			if (**s != ' ' && **s != '\t' && **s != '\n')
				return (-200);
		}
	}
	else
		return (make_obj3(s, all, flag, tail));
	return (0);
}

int	make_obj2(char **s, t_all *all, int *flag, t_objects **tail)
{
	if (**s == 'A' && (*(*s + 1) == ' ' || *(*s + 1) == '\t'))
	{
		*s += 2;
		if (all->a_flag)
			return (-33);
		all->a_flag = 1;
		all->ambi_light.ratio = ft_atoi(s, flag);
		obj_input_3(all->ambi_light.rgb, s, flag);
		while (**s != 0 && **s != '\n')
		{
			(*s)++;
			if (**s != ' ' && **s != '\t' && **s != '\n')
				return (-200);
		}
	}
	else
		return (make_obj10(s, all, flag, tail));
	return (0);
}

int	make_obj1_2(char **s, t_all *all, int *flag, t_objects **tail)
{
	if (**s == 't' && *(*s + 1) == 'r' &&
		(*(*s + 2) == ' ' || *(*s + 2) == '\t') && (*s += 3))
	{
		if (!(tail[4]->next = (t_objects *)malloc(sizeof(t_objects))))
			return (-2);
		tail[4] = tail[4]->next;
		obj_input_3(tail[4]->vert[0], s, flag);
		obj_input_3(tail[4]->vert[1], s, flag);
		obj_input_3(tail[4]->vert[2], s, flag);
		obj_input_3(tail[4]->rgb, s, flag);
		tail[4]->next = NULL;
		tail[4]->type = 4;
		tail[4]->num = all->obj_num;
		all->obj_num++;
		make_triangle_vec(tail[4]);
		while (**s != 0 && **s != '\n')
		{
			(*s)++;
			if (**s != ' ' && **s != '\t' && **s != '\n')
				return (-200);
		}
	}
	else
		return (make_obj2(s, all, flag, tail));
	return (0);
}

int	make_obj1(char **s, t_all *all, int *flag, t_objects **tail)
{
	if (**s == 'R' && (*(*s + 1) == ' ' || *(*s + 1) == '\t'))
	{
		*s += 2;
		if (all->r_flag)
			return (-32);
		all->r_flag = 1;
		all->rx = ft_atoi(s, flag);
		all->ry = ft_atoi(s, flag);
		if (all->rx < 1 || all->ry < 1)
			return (-200);
		while (**s != 0 && **s != '\n')
		{
			(*s)++;
			if (**s != ' ' && **s != '\t' && **s != '\n')
				return (-200);
		}
	}
	else
		return (make_obj1_2(s, all, flag, tail));
	return (0);
}
