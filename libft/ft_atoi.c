/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnitta <rnitta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 17:06:43 by rnitta            #+#    #+#             */
/*   Updated: 2020/07/20 20:39:23 by rnitta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int i;
	int num;

	i = 0;
	num = 0;
	while (*str == '\f' || *str == '\t' || *str == ' ' ||
					*str == '\n' || *str == '\r' || *str == '\v')
		str++;
	if (*str == '-')
		i++;
	if (*str == '+' || *str == '-')
		str++;
	if (*str == '\0' || *str < '0' || *str > '9')
		return (0);
	while (*str >= '0' && *str <= '9')
	{
		num = num * 10 + (*str - '0');
		str++;
	}
	if (i == 1)
		return (-num);
	return (num);
}
