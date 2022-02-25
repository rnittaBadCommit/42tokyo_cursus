/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnitta <rnitta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/01 03:12:59 by rnitta            #+#    #+#             */
/*   Updated: 2020/09/03 17:05:37 by rnitta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>

typedef struct	s_s
{
	struct s_s	*next;
	char		*s;
	int			fd;
}				t_s;

int				get_next_line(int fd, char **line);
int				get_next_line2(int fd, char **line, char *s);
int				ft_njoin(char **line, char *s, int n, int tmpi);
int				ft_ini(char **line, char *s, t_s *ss, int fd);
int				search(char *s, t_s *ss, int fd);
int				ft_save(t_s *ss, char *s, int fd, int *f);

#endif
