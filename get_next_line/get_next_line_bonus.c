/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnitta <rnitta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/25 14:42:12 by rnitta            #+#    #+#             */
/*   Updated: 2020/08/25 14:42:12 by rnitta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	get_next_line2(int fd, char **line, char *s)
{
	static	t_s	ss;
	int			f;
	int			i;
	int			tmpi;

	if ((i = ft_ini(line, s, &ss, fd)) < 0)
	{
		if (i == -1)
			return (-1);
		else
			return (!s[BUFFER_SIZE + 1] && !s[0] ? 0 : 1);
	}
	while (1)
	{
		if ((tmpi = read(fd, s, BUFFER_SIZE)) == -1)
			return (-1);
		s[tmpi] = '\0';
		s[BUFFER_SIZE + 1] = (tmpi > 0);
		i += tmpi;
		if (!tmpi || (f = ft_njoin(line, s, i, tmpi) + ft_save(&ss, s, fd, &f)))
			return (!tmpi ? 0 : 2 * (f > 0) - 1);
	}
}

int	get_next_line(int fd, char **line)
{
	char	*s;
	int		tmp;

	if (!(s = (char *)malloc(BUFFER_SIZE + 2)))
		return (-1);
	tmp = get_next_line2(fd, line, s);
	free(s);
	return (tmp);
}
