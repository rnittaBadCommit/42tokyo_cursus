/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnitta <rnitta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 17:50:12 by rnitta            #+#    #+#             */
/*   Updated: 2020/07/20 20:39:23 by rnitta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	char	*ft_strcpy(char *dest, char *src)
{
	char		*tmp;

	tmp = dest;
	while (*src != '\0')
		*dest++ = *src++;
	*dest = '\0';
	return (tmp);
}

char			*ft_strdup(const char *str)
{
	int			i;
	char		*new;

	i = 0;
	while (str[i])
		i++;
	if (!(new = (char *)malloc(sizeof(char) * (i + 1))))
		return (0);
	return (ft_strcpy(new, (char *)str));
}
