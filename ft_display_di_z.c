/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_di_z.c                                       :+:      :+:  */
/*                                                    +:+ +:+         +:+     */
/*   By: vguerand <vguerand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 16:36:11 by vguerand          #+#    #+#             */
/*   Updated: 2017/12/18 15:59:58 by vguerand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_display_di_z(const char *restrict format, va_list *ap, p_f parse)
{
	int nbr;
  unsigned long long int sa;
	char *str;

  sa = 0;
	nbr = 0;
  str = NULL;
	while((parse.flag = ft_cchr("z", format[parse.i])))
	{
		nbr++;
		parse.i++;
	}
	if (!(parse.type = ft_cchr("dDuioO", format[parse.i])) || nbr == 0)
		return (0);

	if (nbr >= 1)
	{
		(parse.type == 'd' || parse.type == 'i') ? sa = va_arg(*ap, unsigned long long) : sa;
		(parse.type == 'u') ? sa = (size_t)va_arg(*ap, int) : sa;
		(parse.type == 'd' || parse.type == 'i') ? str = ft_itoa_base_max(sa, 10, 0) : str;
		(parse.type == 'u') ? str = ft_itoa_base(sa, 10, 0) : str;
		
	}
  parse.val_ret += aff_struct((int)ft_strlen(str), parse);
  parse.val_ret += ft_display_char(str, parse);
  if (parse.neg.val)
    parse.val_ret += ft_display_c(find_nbr(parse, parse.neg.width, (int)ft_strlen(str)), 32);
	return (parse.val_ret);
}
