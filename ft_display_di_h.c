/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_di_hh.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguerand <vguerand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 16:36:11 by vguerand          #+#    #+#             */
/*   Updated: 2018/01/18 21:45:39 by mbarthe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_display_di_h(va_list *ap, p_f parse)
{
	int		sa;
	char	*str;

	sa = 0;
	str = NULL;
	if (!(ft_cchr("DdiuoO", parse.type)))
		return (0);
	if (!(ft_cchr("h", parse.flag.val)))
		return (0);
	if (parse.flag.width == 1)
	{
		(parse.type == 'u') ? sa = (unsigned short)va_arg(*ap, int) : sa;
		(parse.type == 'o' || parse.type == 'O') ? sa = (unsigned short)va_arg(*ap, int) : sa;
		(parse.type == 'd' || parse.type == 'i') ? sa = (short)va_arg(*ap, int) : sa;
		(sa < 0) ? (parse.space.width = 1) : (parse.space.width = 0);
		(parse.space.width) ? sa = -sa : sa;
		(parse.type == 'd' || parse.type == 'i' || parse.type == 'u') ? str = ft_itoa_base(sa, 10, 0) : str;
		(parse.type == 'o' || parse.type == 'O') ? str = ft_itoa_base(sa, 8, 0) : str;
	}
	else
		return (0);
	parse.val_ret = aff_struct((int)ft_strlen(str), &parse);
	parse.val_ret = ft_display_char(str, parse);
	if (parse.neg.val && parse.precision.width <= parse.neg.width)
		parse.val_ret += ft_display_c(find_nbr(parse, parse.neg.width - parse.htag.width + parse.plus, (int)ft_strlen(str)), 32);
	ft_strdel(&str);
	return (parse.val_ret);
}
