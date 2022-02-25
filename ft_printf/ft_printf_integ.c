/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_integ.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnitta <rnitta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/25 13:35:51 by rnitta            #+#    #+#             */
/*   Updated: 2020/08/25 13:35:51 by rnitta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	out_s(char *s, t_para p)
{
	int i;
	int ii;
	int l;
	int ret;

	p.min_l += (1 << (8 * sizeof(int) - 1)) * (p.min_l < 0);
	i = 0;
	if (!(ret = 0) && !s)
		s = "(null)";
	if ((l = 0) || p.f & 1)
	{
		while (i < p.min_l && s[i])
			ret += write(1, s + i++, 1);
		while (i++ < p.min_ll)
			ret += write(1, " ", 1);
		return (ret);
	}
	while (s[l])
		l++;
	ii = l < p.min_l ? l : p.min_l;
	while ((l = 0) || (i < p.min_ll - ii && ++i))
		ret += write(1, &" 0"[!!(p.f & 2)], 1);
	while (l++ < ii)
		ret += write(1, s++, 1);
	return (ret);
}

int	out_c(char c, t_para p)
{
	int i;

	i = 0;
	if (p.f & 1)
	{
		write(1, &c, 1);
		while (++i < p.min_ll)
			write(1, " ", 1);
	}
	else
	{
		while (++i < p.min_ll)
			write(1, " ", 1);
		write(1, &c, 1);
	}
	return (i);
}

int	putn(unsigned long long int un, long long int t, t_para *p, int log)
{
	char	c;
	int		ret;

	ret = 0;
	if (log > 0 || un > 0)
		ret = putn(un / t, t, p, log - 1);
	else
		return (0);
	un %= t;
	c = '0' + un % 10 + (un > 9) * ('a' - '0' +
		(p->cm >= 64 && p->cm != 128) * ('A' - 'a'));
	write(1, &c, 1);
	return (ret + 1);
}

int	put_d2(unsigned long long int un, int log, t_para p, int t)
{
	int i;
	int ret;

	p.f &= ~(((!un) && p.cm != 128) << 3);
	if ((ret = 0) || !(p.f & 1))
	{
		i = ((t < 0 && p.cm < 9) || p.f / 16) + (p.f / 4 % 4);
		if (!(p.f / 2 % 2))
			while (i++ + log < p.min_ll)
				ret += write(1, " ", 1);
		ret += write(1, (char *)"- +" + (t >= 0) * p.f / 16,
			((t < 0 && p.cm < 9) || p.f / 16));
		ret += write(1, (char *)"0x0X" + (2 & p.cm / 32), p.f / 4 % 4);
		if (p.f / 2 % 2)
			while (ret + log < p.min_ll)
				ret += write(1, "0", 1);
		return (ret + putn(un, (t < 0 ? -1 * t : t), &p, log));
	}
	ret += write(1, (char *)"- +" + (t >= 0) * p.f / 16,
		((t < 0 && p.cm < 9) || p.f / 16));
	ret += write(1, (char *)"0x0X" + 2 * (p.cm == 64), p.f / 4 % 4);
	ret += putn(un, (t < 0 ? -1 * t : t), &p, log);
	while (ret < p.min_ll)
		ret += write(1, " ", 1);
	return (ret);
}

int	out_pudx(long long int n, t_para p, char **args, unsigned long long int tmp)
{
	int						log;
	int						t;
	unsigned long long int	un;

	if ((t = 10) && (p.lf == 4))
		tmp = n * (p.cm < 16) < 0 ? n * -1 * !!(t *= -1) : n;
	else if (p.lf == 1 && (*args -= 0))
		tmp = (unsigned char)((char)n * (p.cm < 16) < 0 ? (char)n * -1
		* !!(t *= -1) : n);
	else if (p.lf == 2 && (*args -= 0))
		tmp = (unsigned short)((short)n * (p.cm < 16) < 0 ? (short)n
		* -1 * !!(t *= -1) : n);
	else if (p.lf == 8 && (*args -= 0))
		tmp = (unsigned long int)((long int)n * (p.cm < 16) < 0 ?
		(long int)n * -1 * !!(t *= -1) : n);
	else if (*args -= sizeof(long long int) - sizeof(long long int))
		tmp = (unsigned int)((int)n * (p.cm < 16) < 0 ? (int)n *
		-1 * !!(t *= -1) : n);
	un = (unsigned long long int)tmp;
	if (!(log = 0) && p.cm >= 32 && (t += 6))
		p.f = p.cm == 128 ? p.f | 8 : p.f & (-1 - 48);
	t -= 8 * (p.cm == 8192);
	while (tmp > 0 && ++log)
		tmp /= (t > 0 ? t : -1 * t);
	return (put_d2(un, (log > p.min_l ? log : p.min_l), p, t));
}
