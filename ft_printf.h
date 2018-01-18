/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguerand <vguerand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/09 19:38:40 by vguerand          #+#    #+#             */
/*   Updated: 2018/01/12 17:48:46 by vguerand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FT_PRINTF_H
# define _FT_PRINTF_H
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
//# include "libft/libft.h"
# include <stdio.h>  //// nepas oublier de virer ce fdp
# define TIME_OUT 50

typedef struct 		s_l
{
	unsigned int 	val;
	int 	width;
}					p_l;


typedef struct		s_f
{
	int neutral;
	int pourcent;
	char   		type;
	p_l			flag;
	p_l   htag;
	p_l space; // width prendra0 si l'argument est posstif et 1 si il est negatif
	p_l	zero;
	p_l	neg;
	unsigned int plus;
	unsigned int i;
	p_l		width;
	p_l 	precision;
	int 	val_ret;
}					p_f;

char		*ft_itoa_unsigned(unsigned int n);

void		ft_print_struct(p_f parse);

int 	ft_printf(const char * restrict format, ...);

int ft_display_capital_s(va_list *ap, p_f parse);

int 	ft_display(va_list *ap, p_f parse);

int			ft_putnchar(char c, int n);

void	ft_putchar(char c);

void	ft_strdel(char **as);

char	*ft_strdup(const char *s1);

char	*ft_strcpy(char *dst, const char *src);

size_t		ft_strlen(const char *s);

char	*ft_strchr(const char *s, int c);

int		ft_atoi(const char *str);

int		ft_isdigit(int c);

char		*ft_itoa(int n);

char		**ft_strsplit(char const *s, char c);

int		ft_nb_ltr(char *str, int mot, char separateur);

int	ft_nb_mots(char *str, char separateur);

int		ft_index_mot(char *str, int mot, char separateur);

void	ft_memdel(void **ap);

unsigned char  *ft_itoa_long(unsigned long long int n);

int   	ft_nbrlen(int n, int base);

char    ft_cchr(const char *s, int c);

char    *ft_itoa_base(int n, int base, int uppercase);

char    *ft_itoa_base_max(unsigned long long int n, int ba, int uppercase);

int		ft_atoi_base(char *nb, int base);

void	ft_putwchar(wchar_t c);

int find_nbr(p_f parse, int size, int str);

int ft_display_s(va_list *ap, p_f parse);

int ft_display_di_h(va_list *ap, p_f parse);

int ft_display_di_hh(va_list *ap, p_f parse);

int ft_display_di_l(va_list *ap, p_f parse);

int ft_display_di_ll(va_list *ap, p_f parse);

int ft_display_di_j(va_list *ap, p_f parse);

int ft_display_p(va_list *ap, p_f parse);

int ft_display_di_none(va_list *ap, p_f parse);

int ft_display_little_c(va_list *ap, p_f parse);

int ft_display_capital_c(va_list *ap, p_f parse);

int ft_display_di_z(va_list *ap, p_f parse);

int 	ft_display_c(int size, int c);

int 	ft_display_char(char *str, p_f parse);

int		ft_putstr_len(char const *s, int len);

int ft_len_unicode(wchar_t str, int precision);

p_f		ft_init_struct(void);

char 	*ft_strrev(char *str);

size_t	ft_wstrlen(wchar_t* str);

size_t	ft_wstrlen_byte(wchar_t* str, int precision);

int ft_display_wchar(wchar_t *str, p_f parse);

size_t ft_putwstr_len(wchar_t *s, size_t len);

int aff_struct(int str, p_f *parse);

int     ft_display_htag(p_f parse);

#endif
