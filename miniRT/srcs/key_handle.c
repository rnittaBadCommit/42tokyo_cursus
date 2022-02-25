/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 22:06:47 by marvin            #+#    #+#             */
/*   Updated: 2020/12/16 22:06:47 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	keyhook_right(t_all *all)
{
	if (!all->camera.next)
		ft_exit(*all);
	all->camera = *(all->camera.next);
	make_screen(all);
	mlx_clear_window(all->mlx, all->mlx_win);
	mlx_put_image_to_window(all->mlx, all->mlx_win,
		all->img, 0, 0);
}

int		handle_key(int k, t_all *all)
{
	if (k == KEYCODE_RIGHT)
		keyhook_right(all);
	if (k == KEYCODE_ESCAPE)
		ft_exit(*all);
	return (0);
}

void	ft_exit1(t_all all)
{
	int i;

	i = -1;
	while (++i < 5)
		destroy_liner_obj(&(all.object[i]));
	if (all.mlx && all.img)
		mlx_destroy_image(all.mlx, all.img);
	if (all.mlx && all.mlx_win)
		mlx_destroy_window(all.mlx, all.mlx_win);
	exit(0);
}

int		ft_exit0(int k, t_all *all)
{
	if (k || 1)
		ft_exit1(*all);
	return (0);
}
