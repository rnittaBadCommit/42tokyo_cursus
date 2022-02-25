/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_obj2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 21:31:54 by marvin            #+#    #+#             */
/*   Updated: 2020/12/20 11:54:38 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../minirt.h"

int		make_obj3_2(char **s, t_all *all, int *flag, t_objects **tail)
{
	if (**s == 's' && *(*s + 1) == 'p' &&
		(*(*s + 2) == ' ' || *(*s + 2) == '\t'))
	{
		*s += 3;
		if (!(tail[0]->next = (t_objects *)malloc(sizeof(t_objects))))
			return (-2);
		tail[0] = tail[0]->next;
		obj_input_3(tail[0]->pos, s, flag);
		tail[0]->r = ft_atoi(s, flag) / 2;
		obj_input_3(tail[0]->rgb, s, flag);
		tail[0]->next = NULL;
		tail[0]->type = 0;
		tail[0]->num = all->obj_num;
		all->obj_num++;
		while (**s != 0 && **s != '\n')
		{
			(*s)++;
			if (**s != ' ' && **s != '\t' && **s != '\n')
				return (-200);
		}
	}
	else
		return (make_obj4(s, all, flag, tail));
	return (0);
}

void	make_yx_vec(double *vec, double *y, double *x)
{
	if (vec[0] || vec[1])
	{
		x[2] = 0;
		x[0] = pow(vec[1], 2) /
			(pow(vec[0], 2) + pow(vec[1], 2));
		x[0] = -1 * sqrt(x[0]);
		x[1] = (vec[1] ? x[0] * vec[0] * -1
			/ vec[1] : 1);
	}
	else
	{
		x[0] = 0;
		x[1] = pow(vec[2], 2) /
			(pow(vec[1], 2) + pow(vec[2], 2));
		x[1] = -1 * sqrt(x[1]);
		x[2] = (vec[2] ? x[1] * vec[1] * -1
			/ vec[2] : 1);
	}
	cross_product(y, x, vec);
	normalize_vec(y);
}

void	make_square_vert(t_objects *obj)
{
	int		i;
	double	yx_vec[2][3];

	make_yx_vec(obj->vec, yx_vec[0], yx_vec[1]);
	i = -1;
	while (++i < 3)
		obj->vert[1][i] = obj->pos[i] + obj->size /
			2 * (yx_vec[0][i] + yx_vec[1][i]);
	i = -1;
	while (++i < 3)
		obj->vert[0][i] = obj->pos[i] + obj->size /
			2 * (yx_vec[0][i] - yx_vec[1][i]);
	i = -1;
	while (++i < 3)
		obj->vert[2][i] = obj->pos[i] - obj->size /
			2 * (yx_vec[0][i] + yx_vec[1][i]);
}

int		make_obj(char *s, t_all *all)
{
	t_objects	*tail[7];
	int			i;
	int			flag;
	int			tmp;

	flag = 0;
	i = -1;
	while (++i < 5)
		tail[i] = &(all->object[i]);
	tail[5] = &(all->camera_save);
	tail[6] = &(all->light);
	while (*s > 2)
	{
		while ((*s == ' ' || *s == '\t' || *s == '\n') && *s)
			s++;
		if (!*s)
			return (0);
		if ((tmp = make_obj1(&s, all, &flag, tail)) < 0)
			return (tmp);
		if (flag < 0)
			return (-200);
	}
	if (*s == 1)
		return (-200);
	return (0);
}
