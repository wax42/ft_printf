/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_di_l.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguerand <vguerand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 16:36:11 by vguerand          #+#    #+#             */
/*   Updated: 2018/01/18 21:52:19 by mbarthe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_display_di_l(va_list *ap, p_f parse)
{
	long int				sa;
	unsigned long long int	la;
	char					*str;

	la = 0;
	sa = 0;
	str = NULL;
	if (ft_cchr("DUO", parse.type))
	{
		parse.flag.val = 'l';
		parse.flag.width = 1;
	}
	if (!(ft_cchr("DUdiuoOxX", parse.type)))
		return (0);
	if (!(ft_cchr("l", parse.flag.val)))
		return (0);
	if (parse.flag.width >= 1)
	{
		(parse.type == 'u' || parse.type == 'U' || parse.type == 'x' || parse.type == 'X') ? la = va_arg(*ap, unsigned long int) : sa;
		(parse.type == 'o' || parse.type == 'O') ? la = va_arg(*ap, unsigned long int) : sa;
		(parse.type == 'd' || parse.type == 'i' || parse.type == 'D') ? sa = va_arg(*ap, long int) : sa;
		(sa < 0) ? (parse.space.width = 1) : (parse.space.width = 0);
		if (sa == 0)
		{
			if (parse.type != 'x')
			{
				(parse.precision.val == 1 && parse.precision.width == 0) ? (str = ""): str;
				parse.neutral = 1;
				if ((parse.type == 'o' || parse.type == 'O') && parse.htag.val)
					parse.neutral = 0;
			}
		}
		else
			(parse.space.width) ? (la = -sa) : (la = sa);
		(parse.type == 'x' ? str = ft_itoa_base_max(la, 16, 0) : str);
		(parse.type == 'X' ? str = ft_itoa_base_max(la, 16, 1) : str);
		(parse.type == 'd' || parse.type == 'i' || parse.type == 'u' || parse.type == 'D' || parse.type == 'U') ? str = ft_itoa_base_max(la, 10, 0) : str;
		((parse.type == 'o' || parse.type == 'O') && str == NULL) ? str = ft_itoa_base_max(la, 8, 0) : str;
		parse.val_ret = aff_struct((int)ft_strlen(str), &parse);
		parse.val_ret = ft_display_char(str, parse);
		if (parse.neg.val && parse.precision.width <= parse.neg.width)
			parse.val_ret += ft_display_c(find_nbr(parse, parse.neg.width - parse.htag.width + parse.plus, (int)ft_strlen(str)), 32);
	}
	if (str[0] != '\0')
		ft_strdel(&str);
	return (parse.val_ret);
}
