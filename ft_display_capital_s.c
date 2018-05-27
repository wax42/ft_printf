/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_capital_s.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguerand <vguerand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 16:36:11 by vguerand          #+#    #+#             */
/*   Updated: 2018/01/18 23:12:24 by vguerand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_strwdel(wchar_t **as)
{
	if (as != NULL)
	{
		free(*as);
		*as = NULL;
	}
}

static int	ft_display_capital_s1(t_f parse)
{
	parse.val_ret = aff_struct((int)ft_strlen("(null)"), &parse);
	parse.val_ret = ft_display_char("(null)", parse);
	if (parse.neg.val && parse.precision.width <= parse.neg.width)
		parse.val_ret += ft_display_c(find_nbr(parse, parse.neg.width, \
			(int)ft_strlen("(null)")), 32);
	return (parse.val_ret);
}

int			ft_display_capital_s(va_list *ap, t_f parse)
{
	wchar_t *str1;

	str1 = NULL;
	if (parse.flag.val == 'l' && parse.type == 's')
		parse.type = 'S';
	if (parse.type != 'S')
		return (0);
	str1 = va_arg(*ap, wchar_t *);
	if (str1 != NULL)
	{
		aff_struct((int)ft_wstrlen_byte(str1, parse.precision.width), &parse);
		parse.val_ret = ft_display_wchar(str1, parse);
		if (parse.val_ret == -1)
			return (-1);
		if (parse.neg.val && parse.precision.width <= parse.neg.width)
			parse.val_ret += ft_display_c(find_nbr(parse, parse.neg.width, \
				(int)ft_wstrlen_byte(str1, parse.precision.width)), 32);
	}
	else
		parse.val_ret = ft_display_capital_s1(parse);
	return (parse.val_ret);
}
