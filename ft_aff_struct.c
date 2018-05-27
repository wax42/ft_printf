/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_aff_struct.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguerand <vguerand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 15:54:28 by vguerand          #+#    #+#             */
/*   Updated: 2018/01/18 22:48:27 by vguerand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int	aff_struct2(int str, t_f *parse)
{
	if ((parse->width.val == 1) || (parse->zero.val == 1 && parse->neg.val == 0\
		&& parse->precision.val == 0))
		parse->val_ret += ft_display_c(find_nbr(*parse, parse->width.width - \
			parse->htag.width, str), 32);
	if (parse->plus == 1)
	{
		if (parse->space.width == 1)
			ft_putchar('-');
		else
			ft_putchar('+');
		parse->space.width = 1;
		parse->val_ret++;
	}
	else if (parse->space.width == 1)
		parse->val_ret += ft_putnchar('-', 1);
	if (parse->htag.val)
		parse->val_ret += ft_display_htag(*parse);
	if (parse->zero.val == 1 && parse->neg.val == 0 && \
		(parse->precision.val == 0 || parse->type == 's' || parse->type == 'S'))
		parse->val_ret += ft_display_c(find_nbr(*parse, parse->zero.width -\
			parse->space.val - parse->htag.width + parse->plus, str), '0');
	return (parse->val_ret);
}

int			aff_struct(int str, t_f *parse)
{
	if (parse->precision.val && parse->zero.val && !parse->plus && parse->type \
		!= 's' && parse->type != 'S')
	{
		parse->width.val = 1;
		parse->width.width = parse->zero.width;
	}
	if (parse->space.val && parse->precision.width >= parse->width.width)
	{
		if (parse->space.width == 0 || parse->neutral)
			parse->val_ret += ft_putnchar(' ', 1);
	}
	if (parse->type == 'p')
	{
		parse->htag.val = 1;
		parse->htag.width = 2;
	}
	(parse->neutral) ? (parse->htag.width = 0) : str;
	if ((parse->type == 'O' || parse->type == 'o') && parse->htag.val == 1)
		parse->htag.width = 1;
	return (aff_struct2(str, parse));
}
