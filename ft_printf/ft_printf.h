/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnitta <rnitta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/25 12:09:46 by rnitta            #+#    #+#             */
/*   Updated: 2020/08/25 13:33:51 by rnitta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <math.h>
# include <limits.h>
# include <stdarg.h>

# define STR_F   "-,0,0,#, ,+,"
# define STR_LF  "hh,h,ll,l,"
# define STR_CM  "c,s,d,i,u,x,X,p,%,n,f,g,e,o,"

typedef	struct		s_para
{
	int				f;
	int				min_ll;
	int				min_l;
	int				lf;
	int				cm;
}					t_para;

typedef	union		u_db
{
	long long int	d;
	double			b;
}					t_db;

typedef	struct		s_rn
{
	long long int	s;
	long long int	k;
	int				f;
}					t_rn;

typedef	struct		s_hissan
{
	char			s[6000];
	int				cnt;
}					t_hissan;

int					out_s(char *s, t_para p);
int					out_c(char c, t_para p);
int					putn(unsigned long long int un, long long int t,
					t_para *p, int log);
int					put_d2(unsigned long long int un, int log, t_para p, int t);
int					out_pudx(long long int n, t_para p, char **args,
					unsigned long long int tmp);
int					put_g(t_para p, t_rn rn, t_hissan s, long long int tmp);
int					put_feg2(t_para p, t_rn rn, t_hissan s, long long int tmp);
int					put_feg(t_para p, t_rn rn, t_hissan s, long long int tmp);
int					out_feg(t_db b, t_para p);
int					check(const char **ss, char *src, t_para *p, int ff);
int					ft_atoi(const char **ss, va_list *args, int i, t_para *p);
int					ft_convert(const char **ss, va_list *args, int n, t_para p);
int					ft_printf(const char *s, ...);
int					kakezan(t_hissan *s, t_hissan *ss);
int					excep(t_para p, t_db b);
void				marume(t_para *p, t_rn rn, t_hissan *s, long long tmptmp);
int					put_e2(t_para p, t_rn rn, t_hissan s, long long int tmp);
int					put_e(t_para p, t_rn rn, t_hissan s, long long int tmp);

#endif
