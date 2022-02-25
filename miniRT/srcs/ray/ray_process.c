/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_process.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 21:56:29 by marvin            #+#    #+#             */
/*   Updated: 2020/12/20 14:14:32 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../minirt.h"

double	screen_val_set(t_all *all, double *screen_yx_pos,
	double screen_yx_vec[2][3], double *t)
{
	*t = all->rx / 2 / sqrt(dist_sq(all->camera.vec, NULL))
		/ tan(PI * all->camera.fov / 360);
	make_screen_yx_vec(all, screen_yx_vec[0], screen_yx_vec[1]);
	screen_yx_pos[0] = -1 * ((int)all->ry / 2)
		- 1 + 0.5 * !((int)all->rx % 2);
	screen_yx_pos[1] = -1 * ((int)all->rx / 2)
		- 1 + 0.5 * !((int)all->ry % 2);
	return (screen_yx_pos[0]);
}

void	ray_process(t_all *all, double *screen_yx_pos,
	double screen_yx_vec[2][3], double t)
{
	make_ray(all, screen_yx_pos, screen_yx_vec, t);
	if (collision_detect_main(*all, &(all->ray)))
	{
		if (zero(all->ray.min_distance))
		{
			all->ray.rgb[0] = 0;
			all->ray.rgb[1] = 0;
			all->ray.rgb[2] = 0;
		}
		else
		{
			make_ambi_light(all);
			make_ray_to_light(all);
			make_images(all);
		}
	}
	else
	{
		all->ray.rgb[0] = 30;
		all->ray.rgb[1] = 30;
		all->ray.rgb[2] = 30;
		make_images(all);
	}
}

void	make_screen(t_all *all)
{
	double screen_yx_pos[2];
	double screen_yx_vec[2][3];
	double t;
	double save;

	save = screen_val_set(all, screen_yx_pos, screen_yx_vec, &t);
	ft_bzero((void *)all->image_yx, 2 * sizeof(int));
	while (++screen_yx_pos[1] <= all->rx / 2)
	{
		while (++screen_yx_pos[0] <= all->ry / 2)
		{
			ray_process(all, screen_yx_pos, screen_yx_vec, t);
			all->image_yx[0]++;
		}
		all->image_yx[1]++;
		screen_yx_pos[0] = save;
		all->image_yx[0] = 0;
	}
}
