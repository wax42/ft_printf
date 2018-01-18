/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_di_j.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguerand <vguerand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 16:36:11 by vguerand          #+#    #+#             */
/*   Updated: 2018/01/18 21:47:53 by mbarthe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_display_di_j(va_list *ap, p_f parse)
{
	intmax_t	sa;
	uintmax_t	la;
	char		*str;

	sa = 0;
	la = 0;
	str = NULL;
	if (!(ft_cchr("diuoxX", parse.type)))
		return (0);
	if (!(ft_cchr("j", parse.flag.val)))
		return (0);
	sa = (uintmax_t)va_arg(*ap, long long int);
	(sa < 0 && parse.type != 'u') ? (parse.space.width = 1) : (parse.space.width = 0);
	(parse.space.width) ? la = -sa : sa;
	(parse.space.width && (parse.type == 'o' || parse.type == 'x' || parse.type == 'X')) ? (parse.space.width = 0) : sa;
	(parse.type == 'd' || parse.type == 'i' || parse.type == 'u') ? str = ft_itoa_base_max(sa, 10, 0) : str;
	(parse.type == 'o') ? str = ft_itoa_base_max(sa, 8, 0) : str;
	(parse.type == 'x') ? str = ft_itoa_base_max(sa, 16, 0) : str;
	if (parse.type == 'X' && parse.space.width)
	{
		str = ft_itoa_base_max(18446744073709551615U - sa, 16, 1);
		parse.space.width = 0;
	}
	else
		(parse.type == 'X' ? str = ft_itoa_base_max(sa, 16, 1) : str);
	parse.val_ret = aff_struct((int)ft_strlen(str), &parse);
	parse.val_ret = ft_display_char(str, parse);
	if (parse.neg.val && parse.precision.width <= parse.neg.width)
		parse.val_ret += ft_display_c(find_nbr(parse, parse.neg.width - parse.htag.width + parse.plus, (int)ft_strlen(str)), 32);
	if (str[0] != '\0')
		ft_strdel(&str);
	return (parse.val_ret);
}
