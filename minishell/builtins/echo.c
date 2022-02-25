/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syudai <syudai@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 17:58:19 by syudai            #+#    #+#             */
/*   Updated: 2021/02/15 23:45:55 by rnitta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		valid_option(char *now)
{
	int i;

	if (now[0] != '-' || !now[1])
		return (0);
	i = 1;
	while (now[i])
	{
		if (now[i] != 'n')
			return (0);
		i++;
	}
	if (i <= 0)
		return (0);
	return (1);
}

int		ft_echo(char *args[])
{
	int i;
	int is_n;

	i = 1;
	is_n = 0;
	if (ft_len(args) != 1)
	{
		while (args[i] && valid_option(args[i]))
		{
			is_n = 1;
			i++;
		}
		while (args[i])
		{
			ft_putstr_fd(args[i], 1);
			if (args[i + 1])
				write(1, " ", 1);
			i++;
		}
	}
	if (!is_n)
		write(1, "\n", 1);
	return (0);
}
