/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguerand <vguerand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/09 19:38:40 by vguerand          #+#    #+#             */
/*   Updated: 2017/12/12 14:35:20 by vguerand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FT_PRINTF_H
# define _FT_PRINTF_H
# include <stdarg.h>
# include "libft/libft.h"
# include <stdio.h>  //// nepas oublier de virer ce fdp

int ft_printf(const char * restrict format, ...);

typedef struct 		s_l
{
	unsigned int 	val;
	int 	width;
}					p_l;


typedef struct		s_f
{
	unsigned int htag;
	unsigned int space;
	p_l	zero;
	p_l	neg;
	unsigned int plus;
	unsigned int i;
	unsigned int neg_int;
	p_l	width;
	p_l precision;
}					p_f;

int ft_printf(const char * restrict format, ...);

int ft_display(const char *restrict format, va_list *ap, p_f parse);

unsigned char            *ft_itoa_long(long long int n);

int ft_display_neg(p_f parse, unsigned char *var_char);

p_f		ft_init_struct(void);

#endif
