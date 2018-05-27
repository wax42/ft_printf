/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_s.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguerand <vguerand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 14:19:18 by vguerand          #+#    #+#             */
/*   Updated: 2018/01/19 00:50:46 by vguerand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_wstr_len(wchar_t *str)
{
	size_t i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int		ft_display_s(va_list *ap, t_f parse)
{
	char *str;

	str = NULL;
	if (parse.type != 's' || parse.flag.width != 0)
		return (0);
	str = va_arg(*ap, char *);
	if (str != NULL)
	{
		parse.val_ret = aff_struct((int)ft_strlen(str), &parse);
		parse.val_ret = ft_display_char(str, parse);
		if (parse.neg.val)
			parse.val_ret += ft_display_c(find_nbr(parse, parse.neg.width -\
				parse.htag.width + parse.plus, (int)ft_strlen(str)), 32);
	}
	else
	{
		parse.val_ret = aff_struct((int)ft_strlen("(null)"), &parse);
		parse.val_ret = ft_display_char("(null)", parse);
		if (parse.neg.val)
			parse.val_ret += ft_display_c(find_nbr(parse, parse.neg.width, \
				(int)ft_strlen("(null)")), 32);
	}
	return (parse.val_ret);
}
