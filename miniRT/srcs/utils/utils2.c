/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 21:39:44 by marvin            #+#    #+#             */
/*   Updated: 2020/12/19 18:55:51 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../minirt.h"

int	check_file_name(char *s)
{
	int i;

	i = 0;
	while (s[i])
		i++;
	if (i < 4)
		return (-1);
	if (s[i - 3] != '.' || s[i - 2] != 'r' || s[i - 1] != 't')
		return (-1);
	return (0);
}

int	zero(double x)
{
	if (x < 2 * MIN && x > 0 - 2 * MIN)
		return (1);
	else
		return (0);
}
