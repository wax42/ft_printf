/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_aff_struct.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguerand <vguerand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 15:54:28 by vguerand          #+#    #+#             */
/*   Updated: 2017/12/18 15:54:48 by vguerand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int aff_struct(char *str, va_list *ap, p_f parse)
{
	if (parse.space.val)
	{
		if (parse.space.width == 0)
		{
			ft_putchar(' ');
			parse.val_ret++;
		}
	}
	if (parse.htag.val)
		parse.val_ret += ft_display_htag();
	if (parse.plus)
	{
		if (parse.space.witdh == 1)
			ft_putchar('-');
		else
			ft_putchar('+');
		parse.val_ret++;
	}
	if (parse.zero.val == 1 && parse.neg.val == 0 && parse.precision.val == 0)
		parse.valret += ft_display_zero();
	parse.val_ret += ft_affiche_char();
	if (parse.neg.val)
		ft_display_neg()
}
