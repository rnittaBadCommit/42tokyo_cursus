/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_bpm.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 21:53:33 by marvin            #+#    #+#             */
/*   Updated: 2022/02/25 16:16:42 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./minirt.h"

void	insert_header(char *data, int width, int height)
{
	int		size;

	size = width * height * 3;
	data[0] = 'B';
	data[1] = 'M';
	*(unsigned int *)(data + 2) = (size + HEADER_SIZE);
	*(unsigned int *)(data + 6) = 0;
	*(unsigned int *)(data + 10) = HEADER_SIZE;
	*(unsigned int *)(data + 14) = HEADER_SIZE - 14;
	*(unsigned int *)(data + 18) = width;
	*(unsigned int *)(data + 22) = height;
	*(unsigned int *)(data + 26) = 1;
	*(unsigned int *)(data + 28) = 24;
	*(unsigned int *)(data + 30) = 0;
	*(unsigned int *)(data + 34) = (unsigned int)size;
	*(unsigned int *)(data + 38) = 3780;
	*(unsigned int *)(data + 42) = 3780;
	*(int *)(data + 46) = 0;
	*(int *)(data + 50) = 0;
}

int		insert_data(char *data, t_all all)
{
	int		i;
	int		j;
	int		x;
	int		y;
	int		k;

	insert_header(data, (int)all.rx, (int)all.ry);
	i = HEADER_SIZE;
	y = (int)all.ry + 1;
	while (y--)
	{
		x = -1;
		while (++x < (int)all.rx)
		{
			j = ((x * (all.bpp / 8)) + (y * all.line));
			*(data + i++) = *(all.addr + j++);
			*(data + i++) = *(all.addr + j++);
			*(data + i++) = *(all.addr + j++);
		}
		k = 0;
		while ((k++ + ((int)all.rx * 3)) % 4 != 0)
			*(data + i++) = 0;
	}
	return (i);
}

void	my_mlx_put_to_bmp(char *name, t_all all)
{
	int				fd;
	unsigned int	size;
	int				tmp;
	void			*data;

	tmp = (((int)all.rx) + 4) * (int)all.ry * 3;
	size = (unsigned int)tmp;
	data = malloc(size + HEADER_SIZE + 1000);
	if (!data)
		err_exit(-2, all);
	tmp = insert_data(data, all);
	if ((fd = open(name, O_CREAT | O_RDWR, 0644)) < 2)
		err_exit(-4, all);
	write(fd, data, tmp);
	free(data);
	close(fd);
}

void	make_name(char *dst, int n)
{
	dst[0] = 'p';
	dst[1] = 'i';
	dst[2] = 'c';
	dst[3] = '0' + (n / 100);
	dst[4] = '0' + (n / 10) % 10;
	dst[5] = '0' + (n % 10);
	dst[6] = '.';
	dst[7] = 'b';
	dst[8] = 'm';
	dst[9] = 'p';
	dst[10] = '\0';
}

void	bpm_main(t_all all)
{
	char	name[13];
	int		n;

	n = 0;
	all.camera = *(all.camera_save.next);
	while (1)
	{
		make_name(name, ++n);
		make_screen(&all);
		my_mlx_put_to_bmp(name, all);
		if (!all.camera.next || n == 900)
			ft_exit(all);
		all.camera = *(all.camera.next);
	}
}
