/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_float2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnitta <rnitta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/25 13:39:42 by rnitta            #+#    #+#             */
/*   Updated: 2020/08/25 13:39:42 by rnitta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	put_g(t_para p, t_rn rn, t_hissan s, long long int tmp)
{
	int l;
	int tmp2;

	if ((s.cnt - tmp < 0 ? tmp - s.cnt : 0) > 4 || s.cnt - tmp > p.min_l)
	{
		tmp2 = 0;
		l = 0;
		while (++l < 1 + p.min_l)
			if (s.s[s.cnt - l])
				tmp2 = l;
		if (p.min_l > 0)
			p.min_l = tmp2 - 1;
		return (put_e(p, rn, s, tmp));
	}
	tmp2 = 0;
	l = -1;
	while (s.cnt - tmp + ++tmp2 < p.min_l)
		if (s.s[tmp - tmp2])
			l = tmp2;
	p.min_l = l;
	p.cm = 1023;
	return (put_feg(p, rn, s, tmp));
}

int	put_feg2(t_para p, t_rn rn, t_hissan s, long long int tmp)
{
	int ret;
	int l;
	int i;

	if (s.cnt + 1 - tmp <= 0 && (s.cnt += -s.cnt + tmp))
		tmp = s.cnt;
	l = (rn.f < 0 || p.f / 16) + s.cnt + 1 - tmp + p.min_l;
	if (!((p.f / 2) % 2))
		while (++l < p.min_ll)
			write(1, " ", 1);
	ret = write(1, &"- +"[(rn.f > 0) * p.f / 16], (rn.f < 0 || p.f / 16));
	if ((p.f / 2) % 2)
		while (++l < p.min_ll)
			write(1, "0", 1);
	i = -1;
	while (++i < s.cnt + 1 - tmp && (s.s[s.cnt - i] += '0'))
		ret += write(1, s.s + s.cnt - i, 1);
	ret += write(1, ".", p.min_l >= 0 || p.f & 8);
	i--;
	while (++i < s.cnt + 1 - tmp + p.min_l && s.cnt - i >= 0
		&& (s.s[s.cnt - i] += '0'))
		ret += write(1, s.s + s.cnt - i, 1);
	while (++i <= s.cnt + 1 - tmp + p.min_l)
		ret += write(1, "0", 1);
	return (ret);
}

int	put_feg(t_para p, t_rn rn, t_hissan s, long long int tmp)
{
	int i;
	int ret;

	marume(&p, rn, &s, tmp);
	if ((i = -1) && p.cm > 1024)
		return (p.cm == 2048 ? put_g(p, rn, s, tmp) : put_e(p, rn, s, tmp));
	if (!(p.f & 1))
		return (put_feg2(p, rn, s, tmp));
	ret = write(1, &"- +"[(rn.f > 0) * p.f / 16], (rn.f < 0 || p.f / 16));
	if (s.cnt + 1 - tmp <= 0 && (s.cnt += -s.cnt + tmp) * 0 + 1)
		tmp = s.cnt;
	while (++i < s.cnt + 1 - tmp && (s.s[s.cnt - i] += '0'))
		ret += write(1, s.s + s.cnt - i, 1);
	ret += write(1, ".", p.min_l >= 0 || p.f & 8);
	i--;
	while (++i < s.cnt + 1 - tmp + p.min_l && s.cnt - i >= 0
		&& (s.s[s.cnt - i] += '0'))
		ret += write(1, s.s + s.cnt - i, 1);
	while (++i <= s.cnt + 1 - tmp + p.min_l)
		ret += write(1, "0", 1);
	while (ret < p.min_ll)
		ret += write(1, " ", 1);
	return (ret);
}

int	out_feg(t_db b, t_para p)
{
	t_rn			rn;
	int				i;
	t_hissan		s[2];
	long long int	tmp;

	i = -1;
	rn.s = 0;
	rn.k = ((b.b != 0) * ((long long int)1 << (23 + 29)) * (b.b != 0));
	while (++i < 23 + 29)
		rn.k += b.d & (long long int)1 << i;
	tmp = rn.k * 10;
	while (i++ < 31 + 32)
		rn.s += (b.d & (long long int)1 << (i - 1)) >> (23 + 29);
	rn.f = 1 - 2 * (b.d < 0);
	i = 0;
	while ((tmp /= 10))
		s[0].s[i++] = tmp % 10;
	s[0].cnt = i - 1;
	s[1].s[0] = rn.s < 150 + 925 ? 5 : 2;
	s[1].cnt = 0;
	while ((rn.s < 150 + 925 ? rn.s++ : rn.s--) - 150 - 925)
		tmp += (s[1].s[0] == 5) * kakezan(s, s + 1);
	p.min_l += 7 * (p.min_l < 0);
	return (b.b == INFINITY || b.b * -1 == INFINITY || isnan(b.b)
		? excep(p, b) : put_feg(p, rn, s[0], tmp));
}
