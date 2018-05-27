/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_format_pourcent.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguerand <vguerand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 01:24:24 by vguerand          #+#    #+#             */
/*   Updated: 2018/01/19 01:44:44 by vguerand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_parse_format_pourcent1(const char *restrict format, t_f *parse, \
	int i, int bol)
{
	parse->pourcent = 1;
	parse->precision.val = 0;
	parse->space.val = 0;
	parse->plus = 0;
	parse->val_ret = aff_struct(1, parse);
	if (!bol)
	{
		ft_putchar('%');
		parse->i = i + 1;
		parse->val_ret += 1;
	}
	else if (bol)
	{
		parse->val_ret += ft_putnchar(format[parse->i], 1);
		parse->i++;
	}
	if (parse->neg.val)
		parse->val_ret += ft_display_c(find_nbr(*parse, parse->neg.width, 1),\
		32);
}

int			ft_parse_format_pourcent(const char *restrict format, t_f *parse)
{
	int i;
	int bol;

	bol = 0;
	i = parse->i;
	parse->val_ret = 0;
	while (!(ft_cchr("%\0", format[i])))
	{
		if ((ft_strchr("hljzsSpdDioOuUxXcC.+0123456789*-# ", format[i])))
			return (1);
		if (!(ft_strchr(".+0123456789*-# ", format[i])))
		{
			bol = 1;
			break ;
		}
		i++;
	}
	ft_parse_format_pourcent1(format, parse, i, bol);
	return (0);
}
