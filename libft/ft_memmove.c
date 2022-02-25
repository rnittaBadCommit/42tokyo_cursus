/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnitta <rnitta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 17:20:45 by rnitta            #+#    #+#             */
/*   Updated: 2020/07/20 20:39:23 by rnitta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memmove(void *buf1, const void *buf2, size_t n)
{
	void	*tmp;

	tmp = buf1;
	if (!buf1 && !buf2)
		return (0);
	if (buf1 < buf2)
		return (ft_memcpy(buf1, buf2, n));
	while (n > 0)
	{
		*(unsigned char *)(buf1 + n - 1) = *(unsigned char *)(buf2 + n - 1);
		n--;
	}
	return (tmp);
}
