/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 13:31:08 by marvin            #+#    #+#             */
/*   Updated: 2021/02/11 22:57:27 by rnitta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	unset_err(int err, char *cmd)
{
	if (err == BAD_ARGNAME)
	{
		ft_putstr_fd("bash: unset: `", 2);
		ft_putstr_fd(cmd, 2);
		ft_putstr_fd("\': not a valid identifier\n", 2);
	}
}

int		unset_name_check(char *cmd)
{
	if (!ft_isalpha(*cmd) && *cmd != '_')
		return (1);
	if (*cmd == '\0')
		return (1);
	while (*cmd)
	{
		if (!ft_isalnum(*cmd) && *cmd != '_')
			return (1);
		cmd++;
	}
	return (0);
}

int		ft_unset(char *argv[], t_arg_main *arg_main)
{
	int	ret;

	ret = 0;
	while (argv[1])
	{
		if (unset_name_check(argv[1]))
		{
			unset_err(BAD_ARGNAME, argv[1]);
			ret = 1;
		}
		else
			arg_delete(arg_main, argv[1]);
		argv++;
	}
	return (ret);
}
