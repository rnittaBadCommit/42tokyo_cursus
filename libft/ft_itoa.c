/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnitta <rnitta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 17:08:33 by rnitta            #+#    #+#             */
/*   Updated: 2020/07/20 20:39:23 by rnitta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long	count(long tmp, int f)
{
	long	ftlog10;

	if (tmp == 0)
		return (1);
	ftlog10 = f;
	while (tmp > 0)
	{
		tmp /= 10;
		ftlog10++;
	}
	return (ftlog10);
}

char		*convert_nb(char *str, long tmp, long ftlog10, int f)
{
	str[ftlog10] = '\0';
	if (tmp == 0)
		str[0] = '0';
	else
	{
		while (ftlog10 > 0 && tmp)
		{
			str[ftlog10 - 1] = tmp % 10 + '0';
			ftlog10--;
			tmp /= 10;
		}
		if (f == 1)
			str[0] = '-';
	}
	return (str);
}

char		*ft_itoa(int n)
{
	char	*str;
	long	tmp;
	long	ftlog10;
	int		f;

	f = 0;
	if (n < 0)
	{
		tmp = (long)n * -1;
		f = 1;
	}
	else
		tmp = (long)n;
	ftlog10 = count(tmp, f);
	if (!(str = (char *)malloc(sizeof(char) * (ftlog10 + 1))))
		return (0);
	return (convert_nb(str, tmp, ftlog10, f));
}
