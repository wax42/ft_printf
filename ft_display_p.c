/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_p.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguerand <vguerand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 16:36:11 by vguerand          #+#    #+#             */
/*   Updated: 2018/01/19 01:44:44 by vguerand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_display_p(va_list *ap, t_f parse)
{
	unsigned long	sa;
	char			*str;

	sa = 0;
	str = NULL;
	if (parse.type != 'p')
		return (0);
	sa = (unsigned long)va_arg(*ap, void *);
	if (sa == 0 && parse.precision.val && !parse.precision.width)
	{
		parse.val_ret = aff_struct((int)ft_strlen(str), &parse);
		if (parse.neg.val && parse.precision.width <= parse.neg.width)
			parse.val_ret += ft_display_c(find_nbr(parse, parse.neg.width, \
				(int)ft_strlen(str)) - 2, 32);
		return (parse.val_ret);
	}
	str = ft_itoa_base_max(sa, 16, 0);
	parse.val_ret = aff_struct((int)ft_strlen(str), &parse);
	parse.val_ret = ft_display_char(str, parse);
	if (parse.neg.val && parse.precision.width <= parse.neg.width)
		parse.val_ret += ft_display_c(find_nbr(parse, parse.neg.width, \
			(int)ft_strlen(str)) - 2, 32);
	if (str[0] != '\0')
		ft_strdel(&str);
	return (parse.val_ret);
}
