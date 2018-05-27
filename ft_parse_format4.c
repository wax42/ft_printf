/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_format4.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguerand <vguerand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 01:23:36 by vguerand          #+#    #+#             */
/*   Updated: 2018/01/19 01:23:37 by vguerand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_parse_format4_htag(const char *restrict format, t_f *parse)
{
	if (format[parse->i] == '#')
	{
		parse->htag.val = 1;
		parse->htag.width = 2;
		while (format[parse->i] == '#')
			parse->i++;
	}
}

void		ft_parse_format4(const char *restrict format, t_f *parse,\
	va_list *ap)
{
	ft_parse_format4_htag(format, parse);
	if (format[parse->i] == 32)
	{
		parse->space.val = 1;
		while (format[parse->i] == 32)
			parse->i++;
	}
	if (format[parse->i] == '+')
	{
		parse->plus = 1;
		while (format[parse->i] == '+')
			parse->i++;
	}
	if (format[parse->i] == '*')
	{
		parse->width.val = 1;
		while (format[parse->i] == '*')
			parse->i++;
		parse->zero.width = va_arg(*ap, int);
	}
}
