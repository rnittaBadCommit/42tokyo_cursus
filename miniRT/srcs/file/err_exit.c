/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_exit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 21:20:10 by marvin            #+#    #+#             */
/*   Updated: 2020/12/19 21:31:08 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../minirt.h"

void	err_exit3(int n)
{
	ft_write("Error\n");
	if (n == -300)
		ft_write("empty file\n");
	exit(0);
}

void	err_exit2(int n)
{
	if (n == -20)
		ft_write("bad arg num");
	else if (n == -21)
		ft_write("bad file name");
	else if (n == -22)
		ft_write("bad arg");
	else if (n == -200)
		ft_write("file error");
	else if (n == -4)
		ft_write("cannot make new bmp");
	else if (n == -30)
		ft_write("no resolution");
	else if (n == -31)
		ft_write("no ambi light");
	else if (n == -32)
		ft_write("too many resolutions");
	else if (n == -33)
		ft_write("too many ambi light");
	else if (n == -300)
		ft_write("empty file");
}

void	err_exit(int n, t_all all)
{
	ft_write("Error\n");
	if (n == -2)
		ft_write("malloc fail");
	else if (n == -3)
		ft_write("cannot open rt file");
	else if (n == -10)
		ft_write("bad rgb");
	else if (n == -11)
		ft_write("resolution not integer");
	else if (n == -12)
		ft_write("bad ratio");
	else if (n == -13)
		ft_write("bad vector");
	else if (n == -14)
		ft_write("bad size/hight/r");
	else if (n == -15)
		ft_write("not triangle");
	else if (n == -16)
		ft_write("bad fov");
	else if (n == -17)
		ft_write("no camera");
	else
		err_exit2(n);
	write(1, "\n", 1);
	ft_exit(all);
}
