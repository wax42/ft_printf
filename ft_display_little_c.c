/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_little_c.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguerand <vguerand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 17:12:33 by vguerand          #+#    #+#             */
/*   Updated: 2018/01/04 23:30:33 by vguerand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_display_little_c(const char *restrict format, va_list *ap, p_f parse)
{
	int nbr;
	char str;


	nbr = 0;
	while((parse.flag = ft_cchr("l", format[parse.i])))
	{
		nbr++;
		parse.i++;
	}
	if (!(parse.type = ft_cchr("c", format[parse.i])))
		return (0);
	if (nbr == 0)
	{
		str = (char)va_arg(*ap, int);
		if (str)
		{
			parse.val_ret = aff_struct(1, parse);
			parse.val_ret += ft_putnchar(str, 1);
			if (parse.neg.val)
				parse.val_ret += ft_display_c(find_nbr(parse, parse.neg.width, 1), 32);
		}
		else
		{
			parse.val_ret = aff_struct(1, parse);
			parse.val_ret += ft_putnchar('\0', 1);
			if (parse.neg.val)
				parse.val_ret += ft_display_c(find_nbr(parse, parse.neg.width, 1), 32);
		}
	}
	return(parse.val_ret);
}
