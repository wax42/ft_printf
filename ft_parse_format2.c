/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_format2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguerand <vguerand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 01:23:17 by vguerand          #+#    #+#             */
/*   Updated: 2018/01/19 01:44:44 by vguerand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_parse_format2_0(const char *restrict format, t_f *parse,\
va_list *ap)
{
	parse->zero.val = 1;
	while (format[parse->i] == '0')
		parse->i++;
	if (format[parse->i] == '*')
		parse->zero.width = va_arg(*ap, int);
}

static void	ft_parse_format2_plus(const char *restrict format, t_f *parse)
{
	char *tmp;

	tmp = NULL;
	parse->zero.width = ft_atoi(format + parse->i);
	tmp = ft_itoa(parse->zero.width);
	parse->i += ft_strlen(tmp);
	if (!parse->zero.width)
		parse->i--;
	ft_strdel(&tmp);
}

void		ft_parse_format2(const char *restrict format, t_f *parse, \
	va_list *ap)
{
	char *tmp;

	tmp = NULL;
	if (format[parse->i] == '0')
	{
		ft_parse_format2_0(format, parse, ap);
		if (format[parse->i] == '+')
		{
			parse->plus = 1;
			while (format[parse->i] == '+')
				parse->i++;
			if ((ft_isdigit(format[parse->i])))
			{
				parse->zero.width = ft_atoi(format + parse->i);
				tmp = ft_itoa(parse->zero.width);
				parse->i += ft_strlen(tmp);
				if (!parse->zero.width)
					parse->i--;
				ft_strdel(&tmp);
			}
		}
		else
			ft_parse_format2_plus(format, parse);
	}
}
