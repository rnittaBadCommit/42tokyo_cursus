/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnitta <rnitta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 17:56:29 by rnitta            #+#    #+#             */
/*   Updated: 2020/07/20 20:39:23 by rnitta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int							ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*ss;
	unsigned char	*ss2;

	ss = (unsigned char *)s1;
	ss2 = (unsigned char *)s2;
	if (n == 0)
		return (0);
	while (*ss == *ss2 && *ss != '\0' && --n != 0)
	{
		ss++;
		ss2++;
	}
	if (*ss == *ss2)
		return (0);
	else
		return (*ss - *ss2);
}
