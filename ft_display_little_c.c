/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_little_c.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguerand <vguerand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 17:12:33 by vguerand          #+#    #+#             */
/*   Updated: 2018/01/18 22:24:29 by mbarthe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_display_little_c(va_list *ap, t_f parse)
{
	char	str;

	if (!(ft_cchr("c", parse.type)))
		return (0);
	str = (char)va_arg(*ap, int);
	if (str)
	{
		parse.val_ret = aff_struct(1, &parse);
		parse.val_ret += ft_putnchar(str, 1);
		if (parse.neg.val && parse.precision.width <= parse.neg.width)
			parse.val_ret += ft_display_c(find_nbr(parse, parse.neg.width, \
						1), 32);
	}
	else
	{
		parse.val_ret = aff_struct(1, &parse);
		parse.val_ret += ft_putnchar('\0', 1);
		if (parse.neg.val && parse.precision.width <= parse.neg.width)
			parse.val_ret += ft_display_c(find_nbr(parse, parse.neg.width, \
						1), 32);
	}
	return (parse.val_ret);
}
