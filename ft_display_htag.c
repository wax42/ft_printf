/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_htag.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguerand <vguerand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 15:55:25 by vguerand          #+#    #+#             */
/*   Updated: 2018/01/18 21:41:10 by mbarthe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_display_htag(t_f parse)
{
	if ((parse.type == 'o' || parse.type == 'O') && (!(parse.neutral)))
	{
		ft_putchar('0');
		return (1);
	}
	if (parse.type == 'x' && (!parse.neutral))
	{
		ft_putstr_len("0x", 2);
		return (2);
	}
	if (parse.type == 'p')
	{
		ft_putstr_len("0x", 2);
		return (2);
	}
	if (parse.type == 'X' && (!parse.neutral))
	{
		ft_putstr_len("0X", 2);
		return (2);
	}
	return (0);
}
