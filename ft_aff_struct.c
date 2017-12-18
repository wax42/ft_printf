/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_aff_struct.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguerand <vguerand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 15:54:28 by vguerand          #+#    #+#             */
/*   Updated: 2017/12/18 17:18:36 by vguerand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int find_nbr(p_f parse, int size, char *str)
{
	if (ft_strchr("s,S", parse.type))
		return (parse.precision.width > (int)ft_strlen(str)) ? ft_strlen(str) : parse.precision.width;
	else
		return (size - parse.precision.width);
}

int aff_struct(char *str, p_f parse)
{
	if (parse.space.val)
	{
		if (parse.space.width == 0)
		{
			ft_putchar(' ');
			parse.val_ret++;
		}
	}
	if (parse.plus)
	{
		if (parse.space.width == 1)
			ft_putchar('-');
		else
			ft_putchar('+');
		parse.val_ret++;
	}
	else if (parse.space.width == 1)
	{
		ft_putchar('-');
		parse.val_ret++;
	}
	if (parse.htag)
		parse.val_ret += ft_display_htag(parse);
	if (parse.zero.val == 1 && parse.neg.val == 0 && parse.precision.val == 0)
		parse.val_ret += ft_display_c(find_nbr(parse, parse.zero.width, str), '0');

	if (parse.width.val == 1 || (parse.zero.val == 1 && parse.neg.val == 0 && parse.precision.val == 0))
		parse.val_ret += ft_display_c(find_nbr(parse, parse.width.width, str), '0');
	parse.val_ret += ft_display_char(str, parse);
	if (parse.neg.val)
		parse.val_ret += ft_display_c(find_nbr(parse, parse.neg.width, str), '0');
	return (parse.val_ret);
}
