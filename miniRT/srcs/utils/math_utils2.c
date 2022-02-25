/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 21:24:31 by marvin            #+#    #+#             */
/*   Updated: 2020/12/16 22:04:30 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../minirt.h"

void	normalize_vec(double *vec)
{
	double tmp;

	tmp = sqrt(dist_sq(vec, NULL));
	if (!tmp)
		return ;
	vec[0] /= tmp;
	vec[1] /= tmp;
	vec[2] /= tmp;
}

void	vec_diff(double *dest, double *from1, double *from2)
{
	dest[0] = from1[0] - from2[0];
	dest[1] = from1[1] - from2[1];
	dest[2] = from1[2] - from2[2];
}

void	reverse_vec(double *vec)
{
	vec[0] *= -1;
	vec[1] *= -1;
	vec[2] *= -1;
}

void	copy_vec(double *dest, double *src)
{
	dest[0] = src[0];
	dest[1] = src[1];
	dest[2] = src[2];
}
