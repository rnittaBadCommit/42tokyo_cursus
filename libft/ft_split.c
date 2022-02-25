/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnitta <rnitta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 17:33:47 by rnitta            #+#    #+#             */
/*   Updated: 2020/07/20 20:39:23 by rnitta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**check(char **ss, int i)
{
	int		j;

	j = 0;
	while (ss[j])
		j++;
	if (j == i)
		return (ss);
	j = 0;
	while (j <= i)
		free(ss[j++]);
	free(ss);
	return (NULL);
}

static int	count(const char *s, char c)
{
	int		i;

	i = 0;
	while (*s)
	{
		if (*s != c && (*(s + 1) == c || *(s + 1) == '\0'))
			i++;
		s++;
	}
	return (i);
}

char		**ft_split(char const *s, char c)
{
	char	*end;
	char	*pc;
	char	**ss;
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	if (!(ss = (char **)malloc(sizeof(char *) * count(s, c) + 1)))
		return (0);
	end = (char *)s + ft_strlen(s);
	while (*s)
	{
		pc = (char *)ft_memchr(s, c, end - s);
		if (!pc)
			ss[i++] = ft_strdup((char *)s);
		else if (s != pc)
			ss[i++] = ft_substr(s, 0, pc - s);
		s = pc ? pc + 1 : end;
	}
	ss[i] = NULL;
	return (check(ss, i));
}
