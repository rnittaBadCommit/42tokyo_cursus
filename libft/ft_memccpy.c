/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnitta <rnitta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 17:16:47 by rnitta            #+#    #+#             */
/*   Updated: 2020/07/20 20:39:23 by rnitta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *buf1, const void *buf2, int c, size_t n)
{
	void	*tmp;
	size_t	i;

	tmp = buf1;
	i = n;
	if (!buf1 && !buf2)
		return (0);
	while (n > 0)
	{
		*(unsigned char *)buf1 = *(unsigned char *)buf2;
		if (*(unsigned char *)(buf2) == (unsigned char)c)
			return (tmp + (i - n + 1));
		buf1++;
		buf2++;
		n--;
	}
	return (0);
}
