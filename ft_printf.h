/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguerand <vguerand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/09 19:38:40 by vguerand          #+#    #+#             */
/*   Updated: 2018/01/19 01:45:43 by vguerand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FT_PRINTF_H
# define _FT_PRINTF_H
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# define TIME_OUT 50

typedef	struct		s_l
{
	unsigned int	val;
	int				width;
}					t_l;

typedef	struct		s_f
{
	int				neutral;
	int				pourcent;
	char			type;
	t_l				flag;
	t_l				htag;
	t_l				space;
	t_l				zero;
	t_l				neg;
	unsigned int	plus;
	unsigned int	i;
	t_l				width;
	t_l				precision;
	int				val_ret;
}					t_f;

char				*ft_itoa_unsigned(unsigned int n);

void				ft_print_struct(t_f parse);

int					ft_printf(const char *restrict format, ...);

int					ft_display_capital_s(va_list *ap, t_f parse);

int					ft_display(va_list *ap, t_f parse);

int					ft_putnchar(char c, int n);

void				ft_putchar(char c);

void				ft_strdel(char **as);

char				*ft_strdup(const char *s1);

char				*ft_strcpy(char *dst, const char *src);

size_t				ft_strlen(const char *s);

char				*ft_strchr(const char *s, int c);

int					ft_atoi(const char *str);

int					ft_isdigit(int c);

char				*ft_itoa(int n);

char				**ft_strsplit(char const *s, char c);

int					ft_nb_ltr(char *str, int mot, char separateur);

int					ft_nb_mots(char *str, char separateur);

int					ft_index_mot(char *str, int mot, char separateur);

void				ft_memdel(void **ap);

unsigned char		*ft_itoa_long(unsigned long long int n);

int					ft_nbrlen(int n, int base);

char				ft_cchr(const char *s, int c);

char				*ft_itoa_base(int n, int base, int uppercase);

char				*ft_itoa_base_max(unsigned long long int n, int ba,\
int uppercase);

int					ft_atoi_base(char *nb, int base);

void				ft_putwchar(wchar_t c);

int					find_nbr(t_f parse, int size, int str);

int					ft_display_s(va_list *ap, t_f parse);

int					ft_display_di_h(va_list *ap, t_f parse);

int					ft_display_di_hh(va_list *ap, t_f parse);

int					ft_display_di_l(va_list *ap, t_f parse);

int					ft_display_di_ll(va_list *ap, t_f parse);

int					ft_display_di_j(va_list *ap, t_f parse);

int					ft_display_p(va_list *ap, t_f parse);

int					ft_display_di_none(va_list *ap, t_f parse);

int					ft_display_little_c(va_list *ap, t_f parse);

int					ft_display_capital_c(va_list *ap, t_f parse);

int					ft_display_di_z(va_list *ap, t_f parse);

int					ft_display_c(int size, int c);

int					ft_display_char(char *str, t_f parse);

int					ft_putstr_len(char const *s, int len);

int					ft_len_unicode(wchar_t str, int precision);

t_f					ft_init_struct(void);

char				*ft_strrev(char *str);

size_t				ft_wstrlen(wchar_t *str);

size_t				ft_wstrlen_byte(wchar_t *str, int precision);

int					ft_display_wchar(wchar_t *str, t_f parse);

size_t				ft_putwstr_len(wchar_t *s, size_t len);

int					aff_struct(int str, t_f *parse);

int					ft_display_htag(t_f parse);

void				ft_parse_regle(t_f *parse);

void				ft_parse_regle_2(t_f *parse);

void				ft_parse_format3(const char *restrict format, t_f *parse,\
va_list *ap);

void				ft_parse_format2(const char *restrict format, t_f *parse,\
va_list *ap);

void				ft_parse_format1(const char *restrict format, t_f *parse,\
va_list *ap);

void				ft_parse_format4(const char *restrict format, t_f *parse,\
va_list *ap);

void				ft_parse_format0(const char *restrict format, t_f *parse,\
va_list *ap);

void				ft_parse_format_ltr(const char *restrict format,\
t_f *parse);

int					ft_parse_format_pourcent(const char *restrict format,\
		t_f *parse);

#endif
