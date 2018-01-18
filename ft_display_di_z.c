/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_di_z.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguerand <vguerand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 16:36:11 by vguerand          #+#    #+#             */
/*   Updated: 2018/01/18 21:43:02 by mbarthe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_display_di_z(va_list *ap, p_f parse)
{
	size_t		sa;
	intmax_t	la;
	char		*str;

	sa = 0;
	la = 0;
	str = NULL;
	if (!(ft_cchr("DUdiuoOxX", parse.type)))
		return (0);
	if (!(ft_cchr("z", parse.flag.val)))
		return (0);
	(parse.type == 'd' || parse.type == 'i') ? la = (intmax_t)va_arg(*ap, long long) : sa;
	(parse.type == 'o') ? sa = (size_t)va_arg(*ap, long long) : sa;
	(parse.type == 'u') ? sa = (size_t)va_arg(*ap, int) : sa;
	(parse.type == 'x' || parse.type == 'X') ? sa = (size_t)va_arg(*ap, long int) : sa;
	(la < 0) ? (parse.space.width = 1) : parse.space.width;
	(parse.space.width) ? (la = -la) : la;
	(parse.type == 'd' || parse.type == 'i') ? str = ft_itoa_base_max(la, 10, 0) : str;
	(parse.type == 'u') ? str = ft_itoa_base(sa, 10, 0) : str;
	(parse.type == 'o') ? str = ft_itoa_base_max(sa, 8, 0) : str;
	(parse.type == 'x') ? str = ft_itoa_base_max(sa, 16, 0) : str;
	(parse.type == 'X') ? str = ft_itoa_base_max(sa, 16, 1) : str;
	parse.val_ret = aff_struct((int)ft_strlen(str), &parse);
	parse.val_ret = ft_display_char(str, parse);
	if (parse.neg.val && parse.precision.width <= parse.neg.width)
		parse.val_ret += ft_display_c(find_nbr(parse, parse.neg.width - parse.htag.width + parse.plus, (int)ft_strlen(str)), 32);
	if (str[0] != '\0')
		ft_strdel(&str);
	return (parse.val_ret);
}
