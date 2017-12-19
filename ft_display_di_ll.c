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

int ft_display_di_ll(const char *restrict format, va_list *ap, p_f parse)
{
	int nbr;
  int sa;
	char *str;

  sa = 0;
	nbr = 0;
  str = NULL;
	while((parse.flag = ft_cchr("l", format[parse.i])))
	{
		nbr++;
		parse.i++;
	}
	if (!(parse.type = ft_cchr("dDi", format[parse.i])) || nbr == 0)
		return (0);
	if (nbr >= 1)
	{
		sa = va_arg(*ap, long long);
    (sa < 0) ? (parse.space.width = 1) : (parse.space.width = 0);
    (parse.space.width) ? sa = -sa : sa;
    (parse.type == 'd' || parse.type == 'D') ? str = (char *)ft_itoa_long(sa) : str;
    (parse.type == 'i') ? str = (char *)ft_itoa_long(sa) : str;
	}
  parse.val_ret += aff_struct((int)ft_strlen(str), parse);
  parse.val_ret += ft_display_char(str, parse);
  if (parse.neg.val)
    parse.val_ret += ft_display_c(find_nbr(parse, parse.neg.width, (int)ft_strlen(str)), 32);
	return (parse.val_ret);
}