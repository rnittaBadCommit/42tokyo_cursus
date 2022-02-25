/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 22:06:31 by marvin            #+#    #+#             */
/*   Updated: 2020/12/17 01:28:17 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	ini2(t_all *all, int n)
{
	int display_size[2];

	all->mlx = mlx_init();
	if (n == 2)
	{
		mlx_get_screen_size(all->mlx, &(display_size[0]), &(display_size[1]));
		if (all->rx > display_size[0])
			all->rx = display_size[0];
		if (all->ry > display_size[1])
			all->ry = display_size[1];
		all->mlx_win = mlx_new_window(all->mlx,
			(int)all->rx, (int)all->ry, "miniRT");
	}
	all->img = mlx_new_image(all->mlx, all->rx, all->ry);
	all->addr = mlx_get_data_addr(all->img, &all->bpp,
		&all->line, &all->endian);
}

void	ini(t_all *all, char *file_name, int n)
{
	char	*s;
	int		tmp;
	int		fd;

	all->ambi_light.ratio = -1;
	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		err_exit(-3, *all);
	s = read_file(fd);
	tmp = make_obj(s, all);
	free(s);
	if (tmp)
		err_exit(tmp, *all);
	if ((tmp = check_file(all)))
		err_exit(tmp, *all);
	if (all->camera.fov > 179.8)
		all->camera.fov = 179.8;
	all->camera = *(all->camera_save.next);
	ini2(all, n);
}

int		re_paste_hook(t_all *all)
{
	mlx_put_image_to_window(all->mlx, all->mlx_win,
		all->img, 0, 0);
	return (0);
}

void	screen_main(t_all all)
{
	mlx_clear_window(all.mlx, all.mlx_win);
	make_screen(&all);
	mlx_put_image_to_window(all.mlx, all.mlx_win, all.img, 0, 0);
	mlx_hook(all.mlx_win, 2, 1L << 0, handle_key, &all);
	mlx_hook(all.mlx_win, 17, 1L << 17, ft_exit0, &all);
	mlx_hook(all.mlx_win, 9, 1L << 21, re_paste_hook, &all);
	mlx_loop(all.mlx);
}

int		main(int argc, char **argv)
{
	t_all all;

	ft_bzero(&all, sizeof(t_all));
	if (argc < 2 || argc > 3)
		err_exit(-20, all);
	if (check_file_name(argv[1]))
		err_exit(-21, all);
	if (argc == 3 && ft_strcmp(argv[2], "--save"))
		err_exit(-22, all);
	ini(&all, argv[1], argc);
	if (argc == 2)
		screen_main(all);
	if (argc == 3)
		bpm_main(all);
}
