/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnitta <rnitta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/25 13:39:32 by rnitta            #+#    #+#             */
/*   Updated: 2020/08/25 14:10:01 by rnitta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	check(const char **ss, char *src, t_para *p, int ff)
{
	int i;
	int ii;
	int cnt;
	int f;
	int ret;

	ret = 0;
	f = 1;
	while (f && (cnt = -1))
	{
		i = 0;
		while (src[i] && (ii = -1) && ++cnt | 1)
		{
			f = 1;
			while (src[i + ++ii] != ',' && src[i + ii] != 0)
				f *= (*(*ss + ii) == src[i + ii]);
			if (f && (ret |= (1 << cnt)) && (*ss += ii))
				break ;
			i += ii + 1;
		}
		if (f && ff)
			break ;
	}
	p->lf = ret == 128 ? 4 : p->lf;
	return (ret);
}

int	ft_atoi(const char **ss, va_list *args, int i, t_para *p)
{
	int ret;

	ret = 0;
	if (i && *(*ss) != '.')
		return (-1);
	else if (i && ((p->cm >= 4 && p->cm <= 128) || p->cm == 8192))
		p->f &= ~(p->f & 2);
	if (*(*ss + i) == '*' && (*ss += i + 1))
	{
		ret = va_arg(*args, int);
		if (ret < 0)
			p->f |= 1;
		if (i && ret < 0)
			return (-1);
		return (ret > 0 ? ret : ret * -1);
	}
	while (*(*ss + i) >= '0' && *(*ss + i) <= '9')
		ret = ret * 10 + *(*ss + i++) - '0';
	*ss += i;
	return (ret);
}

int	ft_convert(const char **ss, va_list *args, int n, t_para p)
{
	p.f = check(ss, STR_F, &p, 0);
	p.min_ll = ft_atoi(ss, args, 0, &p);
	p.min_l = ft_atoi(ss, args, 1, &p);
	p.lf = check(ss, STR_LF, &p, 1);
	p.cm = check(ss, STR_CM, &p, 1);
	p.f &= ~(2 * (p.cm >= 4 && p.cm <= 256 && p.min_l >= 0));
	p.f = p.cm < 32 ? p.f & ~8 : p.f;
	if (p.cm == 1)
		return (out_c((char)va_arg(*args, int), p));
	else if (p.cm == 2)
		return (out_s(va_arg(*args, char *), p));
	p.f &= ~((p.f & 1 || (p.min_l >= 0 && (p.cm < 1024
		|| p.cm == 8192))) << 1) & ~((p.f & (1 << 5)) >> 1);
	if (p.cm >= 1024 && p.cm < 8192)
		return (out_feg((t_db)va_arg(*args, double), p));
	else if (((p.min_l += 2 * (p.min_l < 0)) || 1) &&
		(p.cm <= 128 || p.cm == 8192) * p.cm)
		return (out_pudx(va_arg(*args, long long int), p, (char **)args, 0));
	if (p.cm == 256 && (p.cm = 4) && ((p.min_ll -= (p.min_ll != 0)) || 1)
		&& (p.lf = 4) && !(p.min_l &= 0))
		return (write(1, "%%", p.f & 1) + out_pudx(0, p, (char **)args, 0)
			+ write(1, "%%", !(p.f & 1)));
	else if (p.cm == 512 && p.cm)
		*va_arg(*args, int *) = n;
	return (0);
}

int	ft_printf(const char *s, ...)
{
	va_list	args;
	int		ret;
	t_para	p;

	va_start(args, s);
	ret = 0;
	p.f = 0;
	while (*s)
	{
		if (*s == '%')
		{
			s++;
			ret += ft_convert(&s, &args, ret, p);
		}
		else
			ret += write(1, s++, 1);
	}
	va_end(args);
	return (ret);
}
