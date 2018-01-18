/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_capital_c.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguerand <vguerand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 17:12:33 by vguerand          #+#    #+#             */
/*   Updated: 2018/01/12 17:06:35 by vguerand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


int ft_display_capital_c(va_list *ap, p_f parse)
{
	wchar_t str;

	if (parse.flag.val == 'l' && parse.type == 'c')
		parse.type = 'C';
	if (parse.type != 'C')
		return (0);
	str = va_arg(*ap, long int);
	if (str > 0  && str < 128 && MB_CUR_MAX >= 1)
	{
		parse.val_ret = aff_struct(1, &parse);
		parse.val_ret += ft_putnchar(str, 1);
		if (parse.neg.val)
		{
			parse.precision.val = 1;
			parse.val_ret += ft_display_c(find_nbr(parse, parse.neg.width - 1, 1), 32);
		}
		return(parse.val_ret);
	}
	else if (str >= 128 && str < 2048 && MB_CUR_MAX >= 2)
	{
		parse.val_ret = aff_struct(2, &parse);
		parse.val_ret += 2;
		ft_putwchar(str);
		if (parse.neg.val)
		{
			parse.precision.val = 1;
			parse.val_ret += ft_display_c(find_nbr(parse, parse.neg.width - 2, 2), 32);
		}
		return(parse.val_ret);
	}
	else if (str >= 2048 && str < 65536 && MB_CUR_MAX >= 3)
	{
		parse.val_ret = aff_struct(3, &parse);
		parse.val_ret += 3;
		ft_putwchar(str);
		if (parse.neg.val)
		{
			parse.precision.val = 1;
			parse.val_ret += ft_display_c(find_nbr(parse, parse.neg.width - 3, 3), 32);
		}
		return(parse.val_ret);
	}
	else if (str >= 65536 && str < 263425 && MB_CUR_MAX == 4)
	{
		parse.val_ret = aff_struct(4, &parse);
		parse.val_ret += 4;
		ft_putwchar(str);
		if (parse.neg.val)
		{
			parse.precision.val = 1;
			parse.val_ret += ft_display_c(find_nbr(parse, parse.neg.width - 4, 4), 32);
		}
		return(parse.val_ret);
	}
	else if (str == 0)
	{
		parse.val_ret = aff_struct(1, &parse);
		parse.val_ret += ft_putnchar('\0', 1);
		if (parse.neg.val)
				parse.val_ret += ft_display_c(find_nbr(parse, parse.neg.width - 1, 1), 32);
		return(parse.val_ret);
	}
	else
		return (-1);
	return(parse.val_ret);
}
