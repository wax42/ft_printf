/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_diox_hh.c                                       :+:      :+:  */
/*                                                    +:+ +:+         +:+     */
/*   By: vguerand <vguerand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 16:36:11 by vguerand          #+#    #+#             */
/*   Updated: 2017/12/18 15:59:58 by vguerand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_display_di_ll(va_list *ap, p_f parse)
{
	int nbr;
  long long int sa;
	unsigned long long int la;
	char *str;


  sa = 0;
	nbr = 0;
  str = NULL;
	if (!(ft_cchr("DdiouxX", parse.type)))
		return (0);
	if (!(ft_cchr("lz", parse.flag.val)))
		return (0);
	if (parse.flag.width == 2)
	{
		(parse.type == 'u' || parse.type == 'o' || parse.type == 'x') ? sa = va_arg(*ap, unsigned long long) : sa;
		(parse.type == 'd' || parse.type == 'i' || parse.type == 'X') ? sa = va_arg(*ap, long long int) : sa;
		(sa < 0) ? (parse.space.width = 1) : (parse.space.width = 0);
		if (parse.type == 'u' && parse.space.width)
		{
			 str = ft_itoa_base_max(18446744073709551615U - sa, 10, 0);
			 parse.space.width = 0;
		}
		if (parse.type == 'o' && parse.space.width)
		{
			 str = ft_itoa_base_max(18446744073709551615U - sa, 8, 0);
			 parse.space.width = 0;
		}
	  (parse.space.width) ? (la = -sa) : (la = sa);
	  (parse.type == 'd' || parse.type == 'i' || (parse.type == 'u' && !parse.space.width)) ? str = ft_itoa_base_max(la, 10, 0) : str;
		(parse.type == 'o') ? str = ft_itoa_base_max(la, 8, 0) : str;
		(parse.type == 'x' ? str = ft_itoa_base_max(la, 16, 0) : str);
		(parse.type == 'X' ? str = ft_itoa_base_max(la, 16, 1) : str);
		parse.val_ret = aff_struct((int)ft_strlen(str), &parse);
		parse.val_ret = ft_display_char(str, parse);
		if (parse.neg.val && parse.precision.width <= parse.neg.width)
			parse.val_ret += ft_display_c(find_nbr(parse, parse.neg.width - parse.htag.width + parse.plus, (int)ft_strlen(str)), 32);
	}
	return (parse.val_ret);
}
