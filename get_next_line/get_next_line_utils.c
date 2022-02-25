/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnitta <rnitta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/25 14:41:53 by rnitta            #+#    #+#             */
/*   Updated: 2020/09/28 12:05:12 by rnitta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_njoin(char **line, char *s, int n, int tmpi)
{
	char	*tmp;
	int		i;
	int		ii;
	int		l;
	int		c;

	c = 0;
	tmp = *line;
	while ((i = -1) && s[c] && s[c] != '\n')
		c++;
	l = n - (c - tmpi ? tmpi - c : 0);
	if (!(*line = (char *)malloc(l)))
		return (-1);
	while ((ii = 0) || tmp[++i])
		*(*line + i) = tmp[i];
	while (i < l - 1)
		*(*line + i++) = s[ii++];
	*(*line + i) = '\0';
	l = c;
	i = 0;
	while (++l <= tmpi)
		s[i++] = s[l];
	s[i] = '\0';
	free(tmp);
	return (c == tmpi ? 0 : 1);
}

int	search(char *s, t_s *ss, int fd)
{
	int	i;
	t_s	*tmp;

	tmp = ss->next;
	if (tmp && tmp->fd == fd)
	{
		i = -1;
		while ((tmp->s)[++i])
			s[i] = (tmp->s)[i];
		s[i] = '\0';
		s[BUFFER_SIZE + 1] = (tmp->s)[BUFFER_SIZE + 1];
		tmp = tmp->next;
		free((ss->next)->s);
		free(ss->next);
		ss->next = tmp;
		return (-1);
	}
	if (tmp)
		return (search(s, ss->next, fd));
	s[0] = '\0';
	s[BUFFER_SIZE + 1] = 0;
	return (-1);
}

int	ft_ini(char **line, char *s, t_s *ss, int fd)
{
	int	i;
	int	ii;

	i = search(s, ss, fd);
	while (s[++i])
		if (s[i] == '\n' && (ii = i) + 1)
		{
			if (!(*line = (char *)malloc(i + 1)))
				return (-1);
			*(*line + ii) = '\0';
			while (--i >= 0)
				*(*line + i) = s[i];
			i = 0;
			while (s[++ii])
				s[i++] = s[ii];
			s[i] = '\0';
			return (-2 + ft_save(ss, s, fd, &i));
		}
	ii = i + 1;
	if (!(*line = (char *)malloc(ii)))
		return (-1);
	*(*line + i) = '\0';
	while (--i >= 0)
		*(*line + i) = s[i];
	return (ii);
}

int	ft_save(t_s *ss, char *s, int fd, int *f)
{
	int i;
	t_s *tmp;

	tmp = ss->next;
	if (!(ss->next = (t_s *)malloc(sizeof(t_s))))
	{
		*f = -1;
		return (1);
	}
	if (!((ss->next)->s = (char *)malloc(BUFFER_SIZE + 2)))
	{
		*f = -1;
		return (1);
	}
	(ss->next)->next = tmp;
	(ss->next)->fd = fd;
	i = -1;
	while (s[++i])
		(ss->next)->s[i] = s[i];
	(ss->next)->s[i] = s[i];
	(ss->next)->s[BUFFER_SIZE + 1] = s[BUFFER_SIZE + 1];
	return (0);
}
