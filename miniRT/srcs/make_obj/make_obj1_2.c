/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_obj1_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 21:50:37 by marvin            #+#    #+#             */
/*   Updated: 2020/12/16 22:44:44 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../minirt.h"

int	make_obj5(char **s, t_all *all, int *flag, t_objects **tail)
{
	if (**s == 'c' && *(*s + 1) == 'y' &&
		(*(*s + 2) == ' ' || *(*s + 2) == '\t') && (*s += 3))
	{
		if (!(tail[3]->next = (t_objects *)malloc(sizeof(t_objects))))
			return (-2);
		tail[3] = tail[3]->next;
		obj_input_3(tail[3]->pos, s, flag);
		obj_input_3(tail[3]->vec, s, flag);
		tail[3]->r = ft_atoi(s, flag);
		tail[3]->size = ft_atoi(s, flag);
		obj_input_3(tail[3]->rgb, s, flag);
		tail[3]->next = NULL;
		tail[3]->type = 3;
		tail[3]->num = all->obj_num;
		all->obj_num++;
		while (**s != 0 && **s != '\n')
		{
			(*s)++;
			if (**s != ' ' && **s != '\t' && **s != '\n')
				return (-200);
		}
	}
	else
		return (-200);
	return (0);
}

int	make_obj4_2(char **s, t_all *all, int *flag, t_objects **tail)
{
	if (**s == 's' && *(*s + 1) == 'q' &&
		(*(*s + 2) == ' ' || *(*s + 2) == '\t') && (*s += 3))
	{
		if (!(tail[2]->next = (t_objects *)malloc(sizeof(t_objects))))
			return (-2);
		tail[2] = tail[2]->next;
		obj_input_3(tail[2]->pos, s, flag);
		obj_input_3(tail[2]->vec, s, flag);
		tail[2]->size = ft_atoi(s, flag);
		obj_input_3(tail[2]->rgb, s, flag);
		tail[2]->next = NULL;
		tail[2]->type = 2;
		make_square_vert(tail[2]);
		tail[2]->num = all->obj_num;
		all->obj_num++;
		while (**s != 0 && **s != '\n')
		{
			(*s)++;
			if (**s != ' ' && **s != '\t' && **s != '\n')
				return (-200);
		}
	}
	else
		return (make_obj5(s, all, flag, tail));
	return (0);
}

int	make_obj4(char **s, t_all *all, int *flag, t_objects **tail)
{
	if (**s == 'p' && *(*s + 1) == 'l' &&
		(*(*s + 2) == ' ' || *(*s + 2) == '\t'))
	{
		*s += 3;
		if (!(tail[1]->next = (t_objects *)malloc(sizeof(t_objects))))
			return (-2);
		tail[1] = tail[1]->next;
		obj_input_3(tail[1]->pos, s, flag);
		obj_input_3(tail[1]->vec, s, flag);
		obj_input_3(tail[1]->rgb, s, flag);
		tail[1]->next = NULL;
		tail[1]->type = 1;
		tail[1]->num = all->obj_num;
		all->obj_num++;
		while (**s != 0 && **s != '\n')
		{
			(*s)++;
			if (**s != ' ' && **s != '\t' && **s != '\n')
				return (-200);
		}
	}
	else
		return (make_obj4_2(s, all, flag, tail));
	return (0);
}
