/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_p.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguerand <vguerand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 16:36:11 by vguerand          #+#    #+#             */
/*   Updated: 2017/12/25 20:31:15 by vguerand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_display_p(const char *restrict format, va_list *ap, p_f parse)
{
	int nbr;
  long long sa;
	char *str;


  sa = 0;
	nbr = 0;
  str = NULL;
	if (!(parse.type = ft_cchr("p", format[parse.i])))
		return (0);

  sa = (long long)va_arg(*ap, void *);
  (sa < 0) ? (parse.space.width = 1) : (parse.space.width = 0);
  (parse.space.width) ? sa = -sa : sa;
  str = ft_itoa_base_max(sa, 16, 0);
  parse.val_ret += aff_struct((int)ft_strlen(str), parse);
	parse.val_ret = ft_display_char(str, parse);
  if (parse.neg.val)
    parse.val_ret += ft_display_c(find_nbr(parse, parse.neg.width, (int)ft_strlen(str)), 32);
	return (parse.val_ret);
}
