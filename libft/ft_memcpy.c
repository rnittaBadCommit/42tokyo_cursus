/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnitta <rnitta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 17:19:20 by rnitta            #+#    #+#             */
/*   Updated: 2020/07/20 20:39:23 by rnitta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memcpy(void *buf1, const void *buf2, size_t n)
{
	void	*tmp;

	tmp = buf1;
	if (!buf1 && !buf2)
		return (0);
	while (n > 0)
	{
		*(unsigned char *)buf1++ = *(unsigned char *)buf2++;
		n--;
	}
	return (tmp);
}
