/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 21:14:18 by marvin            #+#    #+#             */
/*   Updated: 2020/12/16 22:26:21 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../minirt.h"

double	inner_product(double a[3], double b[3])
{
	double ret;

	ret = a[0] * b[0];
	ret += a[1] * b[1];
	ret += a[2] * b[2];
	return (ret);
}

void	cross_product(double ret[3], double a[3], double b[3])
{
	ret[0] = a[1] * b[2] - a[2] * b[1];
	ret[1] = a[2] * b[0] - a[0] * b[2];
	ret[2] = a[0] * b[1] - a[1] * b[0];
}

double	ft_cos_sq(double *a, double *b)
{
	double ret;

	ret = a[0] * b[0] + a[1] * b[1] + a[2] * b[2];
	if (ret < 0)
		return (0);
	ret *= ret;
	ret /= dist_sq(a, NULL) * dist_sq(b, NULL);
	return (ret);
}

double	ft_cosr_sq(double *n, t_ray ray, t_ray new_ray)
{
	double tmp;
	double reflec_vec[3];
	double ret;

	tmp = 2 * inner_product(new_ray.d, n) / dist_sq(n, NULL);
	reflec_vec[0] = new_ray.d[0] - tmp * n[0];
	reflec_vec[1] = new_ray.d[1] - tmp * n[1];
	reflec_vec[2] = new_ray.d[2] - tmp * n[2];
	ret = inner_product(reflec_vec, ray.d);
	if (ret < 0)
		ret = 0;
	return (ret * ret / dist_sq(reflec_vec, NULL)) / dist_sq(ray.d, NULL);
}

double	dist_sq(double a[3], double *b)
{
	double ret;

	if (b)
	{
		ret = (a[0] - b[0]) * (a[0] - b[0]);
		ret += (a[1] - b[1]) * (a[1] - b[1]);
		ret += (a[2] - b[2]) * (a[2] - b[2]);
	}
	else
	{
		ret = a[0] * a[0];
		ret += a[1] * a[1];
		ret += a[2] * a[2];
	}
	return (ret);
}
