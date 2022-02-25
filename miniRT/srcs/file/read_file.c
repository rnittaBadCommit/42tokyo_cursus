/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 21:09:32 by marvin            #+#    #+#             */
/*   Updated: 2020/12/19 21:26:47 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../minirt.h"

void	ft_strlncat(char *dest, char *src, int n, int srcn)
{
	int		i;

	if (!src)
		return ;
	i = -1;
	while (++i < srcn)
		dest[n + i] = src[i];
	dest[n + i] = '\0';
}

char	*read_file(int fd)
{
	char	*s;
	char	*tmpp;
	char	buf[10];
	int		n;
	int		tmpn;

	n = 0;
	s = NULL;
	while ((tmpn = read(fd, buf, 10)))
	{
		tmpp = s;
		s = (char *)malloc(n + tmpn + 10);
		ft_strlncat(s, tmpp, 0, n);
		ft_strlncat(s, buf, n, tmpn);
		n += tmpn;
		free(tmpp);
	}
	if (!s)
		err_exit3(-300);
	tmpn = n;
	while (n < tmpn + 9)
		s[++n] = -1;
	return (s);
}
