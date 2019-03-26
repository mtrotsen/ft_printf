/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrotsen <mtrotsen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 13:15:11 by mtrotsen          #+#    #+#             */
/*   Updated: 2019/02/25 13:15:13 by mtrotsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H
# include <stdio.h>
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

# define BASE(i, n, nb, l, b) i = 0; nb = n; l = length(n, b);
# define NB(nb, base, i) nb = nb / base; i++;
# define CHARSSS(pl, ha, si) pl = ' '; ha = ' '; si = ' ';
# define CHARSS(pr, dot, pl, ha, si) pr = ' '; dot = ' '; CHARSSS(pl, ha, si);
# define CHARRRS(in, fs, re) in = 0; fs = 0; re = 0;
# define CHARRS(pe, sp, in, fs, re) pe = ' '; sp = ' '; CHARRRS(in, fs, re);
# define CHAAARS(ch, nu, i) ch = 0; nu = 0; i = 0;
# define CHAARS(fo, dot, ch, nu, i) fo = 0; dot = 0; CHAAARS(ch, nu, i);
# define CHHHARS(hh, l, ll, bi) hh = 0; l = 0; ll = 0; bi = 0;
# define CHHARS(en, h, hh, l, ll, bi) en = 0; h = 0; CHHHARS(hh, l, ll, bi);
# define BREAK(a, ap, f, p) ft_branch(a, ap, f); p = ' '; break ;
# define R(fa) fa == 'u' || fa == 'o' || fa == 'f'
# define B(fa) fa == 'd' || fa == 'i' || fa == 'x' || fa == 'X' || R(fa)
# define BRAN(fa) fa == 'c' || fa == 's' || fa == 'p' || B(fa)
# define BRANCH(fa, a, ap, f, p) if (BRAN(fa)){BREAK(a, ap, f, p);}
# define PP(i, e, p) i++; e++; p = ' '; break ;
# define SLASHN(f, i, e, p) if (f == '\n'){ft_putchar('\n'); PP(i, e, p);}
# define EXIT(f, i, p, e) if (f == '\0') break ; i++; if (p != '%') e++;
# define IFN(fa, p) if (fa == '%' && p != '%') p = '%';
# define IFY(fa, p, a, ap, f) if (fa == '%' && p == '%'){BREAK(a, ap, f, p);}
# define IF(fa, p, a, ap, f) if (fa == '%'){IFY(fa, p, a, ap, f); IFN(fa, p);}
# define HH(hh, i){hh = 1; i++;}
# define LL(ll, i){ll = 1; i++;}
# define WTH(n, s, j, i) n = ft_atoi(s); j = 0; free(s); i--;
# define PRECN(r, j, d, i) r[j] = '\0'; d = ft_atoi(r); free(r); i--;
# define PRECC(r, j, f, c){r[j] = f[c]; c++; j++;}
# define DISSC(si, pr, sp) si = ' '; pr = ' '; sp = ' ';
# define DISC(pl, ha, si, pr, sp) pl = ' '; ha = ' '; DISSC(si, pr, sp);
# define DISSCI(fs, re, fo) fs = 0; re = 0; fo = 0;
# define DISCI(dot, in, fs, re, fo) dot = ' '; in = 0; DISSCI(fs, re, fo);
# define DISSI(nu, dot, h, hh) nu = 0; dot = 0; h = 0; hh = 0;
# define DISI(z, ch, nu, dot, h, hh) z = 0; ch = 0; DISSI(nu, dot, h, hh);
# define DISII(l, ll, bi, i, en) l = 0; ll = 0; bi = 0; i++; en++;
# define DISIID(l, ll, bi, i) l = 0; ll = 0; bi = 0; i++;
# define EDI(de, a, d) if (de == ' '){ft_eddi(d, a);} else {ft_neddi(d, a);}
# define DIDI(si, de, a, d) if (si == '-'){ft_md(d, a);} else {EDI(de, a, d);}
# define EDDI(e, a)ft_putchar('+'); e++; ft_putspaces(a);
# define EEDDI(e, a)ft_putspaces(a); ft_putchar('+'); e++;
# define EDDII(d, e, a)ft_putchar('-'); d = (d * -1); e++; ft_putspaces(a);
# define EEDDII(a, d, e)ft_putspaces(a); ft_putchar('-'); d = (d * -1); e++;
# define IINF(a) ft_putstr("inf"); ft_putspaces(a);
# define INF(p, e, a) if (p == '+'){ft_putchar('+'); e++;} IINF(a);
# define FREEF(d, f) if (d == 0) free(f);
# define ELSEONE(e, a) ft_putchar('+'); e++; ft_putspaces(args);
# define ELSETWO(e, a) ft_putspaces(args); ft_putchar('+'); e++;
# define ELSETHREE(e, a) ft_putchar('-'); e++; ft_putspaces(args);
# define ELSEFOUR(e, a) ft_putspaces(args); ft_putchar('-'); e++;
# define EE(e) e = e + 2;
# define E(a, i, p, e) if (i == 1){ft_puts(p, a); free(p); e++;} EE(e);
# define EDOTT(f, a, i, p, e) ft_putchar('.'); ft_puts(f, a); E(a, i, p, e);
# define DISMOVE(a, f, i, ai) ft_dottzero(a, f, i); i = ai;
# define ZERO(r, i) r++; free(i); i = ft_itoa(r);
# define MORE(r, i, f, d)ZERO(r, i); f = ft_memchr(f, d, '0');
# define DMORE(j, d, f) j = d; while (j > 0){f = f * 10; j--;}
# define RR(f, fo) fo = (unsigned long long)f % 10;
# define MR(f, z, fs, fo) fs = ft_itoaf(z); f = f * 10; RR(f, fo);
# define D(f, z, fs, fo) z = (unsigned long long)f; MR(f, z, fs, fo);
# define DD(j, d, af, f, z, fs, fo) DMORE(j, d, f); DMR(af, f, z, fs, fo);
# define DMR(af, f, z, fs, fo) if (af == 1) f = f * -1; D(f, z, fs, fo);
# define MOREF(f, af, ai, i) af = f; ai = i;
# define MORF(c, f, af, ai, i) c = c + ft_strlen(f); MOREF(f, af, ai, i);
# define ELSZ(z, p) z++; p = ft_itoaf(z);
# define IFP(p, z, f) p = ft_itoaf(z); free(f);
# define IFI(i, c, p) i = 1; c = ft_strlen(p);
# define OIF(c, e){c--; e--;}
# define WOIF(s, a, p){ft_puts(s, a); p = ' '; ft_putspaces(a);}

typedef struct	s_args
{
	int					i;
	int					num;
	int					chrn;
	int					endin;
	int					dott;
	int					h;
	int					hh;
	int					l;
	int					ll;
	int					bigl;
	int					fsign;
	int					ind;
	long long			remnum;
	unsigned long long	forf;
	unsigned long long	z;
	char				dot;
	char				pref;
	char				sign;
	char				plus;
	char				hash;
	char				percent;
	char				space;
	char				*fs;
	char				*fscp;
	char				*iscp;
	char				*p;
}				t_args;

int				ft_printf(const char *format, ...);
void			ft_print_to_procent(const char *format, t_args *args);
void			distribute_c(t_args *args, va_list ap);
void			distribute_s(t_args *args, va_list ap);
void			ft_putspaces(t_args *args);
void			ft_putdot(t_args *args);
void			ft_puts(char *s, t_args *args);
int				ft_atoi(const char *str);
void			ft_putchar(char c);
void			distribute_percent(t_args *args, va_list ap);
int				ft_strcmp(const char *s1, const char *s2);
void			distribute_p(t_args *args, va_list ap);
char			*itoa_base(unsigned long long n, int base);
char			*ft_lowc(char *s);
char			*ft_strdup(const char *s);
size_t			ft_strlen(const char *s);
void			distribute_di(t_args *args, va_list ap);
void			ft_putnbr(int n, t_args *args);
void			ft_putstr(char const *s);
char			*ft_itoa(int n);
void			ft_puth(short n, t_args *args);
void			ft_puthh(signed char n, t_args *args);
void			ft_putl(long n, t_args *args);
void			ft_putll(unsigned long long n, t_args *args);
void			distribute_x(t_args *args, va_list ap);
void			distribute_xx(t_args *args, va_list ap);
void			distribute_u(t_args *args, va_list ap);
void			distribute_o(t_args *args, va_list ap);
void			distribute_f(t_args *args, va_list ap);
char			*ft_memchr(char *fs, int dott, char c);
char			*ft_itoaf(unsigned long long n);
void			ft_precision(const char *format, t_args *args);
void			ft_width(const char *format, t_args *args);
void			ft_dicheck(long long d, t_args *args);
void			ft_inf(long double f, t_args *args);
void			ft_writeminusf(t_args *args, char *fs, char *is);
void			ft_writeelsef(t_args *args, char *fs, char *is);
void			ft_xwrite(unsigned long long x, char *s, t_args *args);
void			ft_xxwrite(unsigned long long x, char *s, t_args *args);
void			ft_xcut(unsigned long long x, t_args *args);

#endif
