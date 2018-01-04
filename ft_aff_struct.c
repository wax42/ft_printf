/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_aff_struct.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguerand <vguerand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 15:54:28 by vguerand          #+#    #+#             */
/*   Updated: 2018/01/04 15:55:48 by vguerand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int aff_struct(int str, p_f parse)
{
	if (parse.space.val)
	{
		if (parse.space.width == 0)
		{
			ft_putchar(' ');
			parse.val_ret++;
		}
	}
	if (parse.plus == 1)
	{
		if (parse.space.width == 1)
			ft_putchar('-');
		else
			ft_putchar('+');
		parse.space.width = 1;
		parse.val_ret++;
	}
	else if (parse.space.width == 1)
		parse.val_ret += ft_putnchar('-', 1);
	if (parse.htag)
		parse.val_ret += ft_display_htag(parse);
	if (parse.zero.val == 1 && parse.neg.val == 0 && parse.precision.val == 0)
		parse.val_ret += ft_display_c(find_nbr(parse, parse.zero.width, str), '0');
	if (parse.width.val == 1 || (parse.zero.val == 1 && parse.neg.val == 0 && parse.precision.val == 0))
		parse.val_ret += ft_display_c(find_nbr(parse, parse.width.width, str), 32);
	return (parse.val_ret);
}
