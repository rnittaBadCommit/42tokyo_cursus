/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_float.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnitta <rnitta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/25 13:39:37 by rnitta            #+#    #+#             */
/*   Updated: 2020/08/25 13:39:37 by rnitta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		kakezan(t_hissan *s, t_hissan *ss)
{
	t_hissan	tmp;
	int			i;
	int			ii;
	int			iii;

	i = -1;
	while (++i < 6000)
		tmp.s[i] = 0;
	i = -1;
	while (++i <= s->cnt && (ii = -1))
		while (++ii <= ss->cnt)
		{
			tmp.s[i + ii] += s->s[i] * ss->s[ii];
			iii = -1;
			while (tmp.s[i + ii + ++iii] / 10)
			{
				tmp.s[i + ii + iii + 1] += tmp.s[i + ii + iii] / 10;
				tmp.s[i + ii + iii] %= 10;
			}
		}
	s->cnt = i + ii - 1 - !tmp.s[i + ii - 1];
	i = 6000;
	while (--i >= 0)
		s->s[i] = tmp.s[i];
	return (1);
}

int		excep(t_para p, t_db b)
{
	int ret;
	int l;

	l = isnan(b.b) ? 3 : 3 + (b.b != INFINITY || p.f / 16);
	if ((ret = 0) || !(p.f & 1))
	{
		while (ret + l < p.min_ll)
			ret += write(1, " ", 1);
		if (isnan(b.b))
			return (ret + write(1, "nan", 3));
		ret += write(1, &"- +"[(b.b == INFINITY) * p.f / 16],
			(b.b != INFINITY || p.f / 16));
		return (ret + write(1, "inf", 3));
	}
	if (isnan(b.b))
		ret = write(1, "nan", 3);
	else
	{
		ret = write(1, &"- +"[(b.b == INFINITY) * p.f / 16],
			(b.b != INFINITY || p.f / 16));
		ret += write(1, "inf", 3);
	}
	while (ret < p.min_ll)
		ret += write(1, " ", 1);
	return (ret);
}

void	marume(t_para *p, t_rn rn, t_hissan *s, long long tmptmp)
{
	int				i;
	long long int	tmp;

	i = -1;
	tmp = p->cm == 1024 ? tmptmp : s->cnt;
	if ((rn.s = 0) || p->cm == 2048)
	{
		if ((s->cnt - tmp < 0 ? tmp - s->cnt : 0) > 4 ||
			s->cnt - tmp > p->min_l)
			tmp = tmptmp;
		else
			tmp = s->cnt;
	}
	while (++i < tmp - 1 - p->min_l)
		rn.s += s->s[i];
	s->s[tmp - p->min_l] += s->s[tmp - 1 - p->min_l] > 4 +
		(!rn.s && !(s->s[tmp - p->min_l] % 2));
	s->s[tmp + (i -= i + 1) - p->min_l] = 0;
	while (s->s[tmp - p->min_l + ++i] / 10)
	{
		s->s[tmp - p->min_l + i + 1]++;
		s->s[tmp - p->min_l + i] %= 10;
	}
	s->cnt += !s->s[s->cnt];
	p->min_l -= (p->min_l == 0 && !(p->f & 8));
}

int		put_e2(t_para p, t_rn rn, t_hissan s, long long int tmp)
{
	int ret;
	int i;
	int l;
	int tmp2;

	tmp2 = s.cnt - tmp < 0 ? tmp - s.cnt : s.cnt - tmp;
	tmp2 *= !(s.cnt - tmp == -1076 && !s.s[s.cnt]);
	ret = 0;
	l = (rn.f < 0 || p.f / 16) + 2 + p.min_l + 2 + 2 + (tmp2 > 99);
	while (l++ < p.min_ll)
		ret += write(1, " ", 1);
	ret += write(1, &"- +"[(rn.f > 0) * p.f / 16], (rn.f < 0 || p.f / 16));
	s.s[s.cnt] += '0';
	ret += write(1, s.s + s.cnt, 1);
	ret += write(1, ".", (p.min_l >= 0 || p.f & 8));
	i = -1;
	while (++i < p.min_l && s.cnt - i > 0 && (s.s[s.cnt - i - 1] += '0'))
		ret += write(1, s.s + s.cnt - i - 1, 1);
	while (++i <= p.min_l)
		ret += write(1, "0", 1);
	ret += write(1, &"e+e-"[2 * (s.cnt - tmp < 0 && tmp2)], 2);
	ret += putn((unsigned long long int)tmp2, 10, &p, 2);
	return (ret);
}

int		put_e(t_para p, t_rn rn, t_hissan s, long long int tmp)
{
	int				ret;
	int				i;
	long long int	tmp2;

	tmp2 = s.cnt - tmp < 0 ? tmp - s.cnt : s.cnt - tmp;
	tmp2 *= !(s.cnt - tmp == -1076 && !s.s[s.cnt]);
	if (p.f & 1 && (s.s[s.cnt] += '0'))
	{
		ret = write(1, &"- +"[(rn.f > 0) * p.f / 16], (rn.f < 0 || p.f / 16));
		ret += write(1, s.s + s.cnt, 1);
		ret += write(1, ".", (p.min_l >= 0 || p.f & 8));
		i = -1;
		while (++i < p.min_l && s.cnt - i >= 1 && (s.s[s.cnt - i - 1] += '0'))
			ret += write(1, s.s + s.cnt - i - 1, 1);
		while (++i <= p.min_l)
			ret += write(1, "0", 1);
		ret += write(1, &"e+e-"[2 * (s.cnt - tmp < 0 && tmp2)], 2);
		ret += putn((unsigned long long int)tmp2, 10, &p, 2);
		while (ret < p.min_ll)
			ret += write(1, " ", 1);
		return (ret);
	}
	else
		return (put_e2(p, rn, s, tmp));
}
