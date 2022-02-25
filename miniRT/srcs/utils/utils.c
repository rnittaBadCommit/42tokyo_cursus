/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 21:22:12 by marvin            #+#    #+#             */
/*   Updated: 2020/12/19 19:22:18 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../minirt.h"

void	ft_write(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	write(1, s, i);
}

void	ft_bzero(void *s, int n)
{
	char	*str;
	int		i;

	str = (char *)s;
	i = -1;
	while (++i < n)
		str[i] = 0;
}

int		ft_strcmp(char *s1, char *s2)
{
	while (*s1)
		if (*(s1++) != *(s2++))
			return (-1);
	return (0);
}

void	destroy_liner_obj(t_objects *obj)
{
	if (obj == NULL)
		return ;
	if (obj->next)
		destroy_liner_obj(obj->next);
	else
		return ;
	free(obj->next);
}

void	ft_exit(t_all all)
{
	int i;

	i = -1;
	while (++i < 5)
		destroy_liner_obj(&(all.object[i]));
	destroy_liner_obj(&(all.camera_save));
	destroy_liner_obj(&(all.light));
	if (all.mlx && all.img)
		mlx_destroy_image(all.mlx, all.img);
	if (all.mlx && all.mlx_win)
		mlx_destroy_window(all.mlx, all.mlx_win);
	exit(0);
}
