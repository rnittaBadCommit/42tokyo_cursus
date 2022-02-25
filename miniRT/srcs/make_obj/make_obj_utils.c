/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_obj_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 21:27:55 by marvin            #+#    #+#             */
/*   Updated: 2020/12/20 01:59:49 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../minirt.h"

double	ft_atoi2(char **s, int *flag)
{
	double	ret;
	int		neg;
	int		i;

	neg = 1;
	i = 0;
	ret = 0;
	if (**s == '-' && (*s)++)
		neg = -1;
	if (**s < '0' || **s > '9')
		*flag = -1;
	while (**s >= '0' && **s <= '9' && ret > -999999999 && ret < 999999999)
		ret = ret * 10 + *((*s)++) - '0';
	if ((**s == '.' && (*s)++) || ret <= -999999999 || ret >= 999999999)
	{
		if (**s < '0' || **s > '9' || ret <= -999999999 || ret >= 999999999)
			*flag = -1;
		while (**s >= '0' && **s <= '9')
		{
			ret += (**s - '0') * pow(0.1, ++i);
			(*s)++;
		}
	}
	return (neg * ret);
}

void	obj_input_3(double *i, char **s, int *flag)
{
	while (**s == ' ' || **s == '\t')
		(*s)++;
	i[0] = ft_atoi2(s, flag);
	if (*((*s)++) != ',')
		*flag -= 2;
	i[1] = ft_atoi2(s, flag);
	if (*((*s)++) != ',')
		*flag -= 4;
	i[2] = ft_atoi2(s, flag);
}

double	ft_atoi(char **s, int *flag)
{
	while ((**s == ' ' || **s == '\t') && **s)
		(*s)++;
	return (ft_atoi2(s, flag));
}

int		check_alpha(char *s)
{
	if (*s >= 'a' && *s <= 'z')
		return (1);
	if (*s >= 'A' && *s <= 'Z')
		return (1);
	return (0);
}

void	make_triangle_vec(t_objects *obj)
{
	double	vec[2][3];
	int		i;
	int		j;

	i = -1;
	j = -1;
	while (++i < 2)
	{
		while (++j < 3)
		{
			vec[i][j] = obj->vert[i + 1][j] - obj->vert[i][j];
		}
		j = -1;
	}
	cross_product(obj->vec, vec[0], vec[1]);
	normalize_vec(obj->vec);
}
