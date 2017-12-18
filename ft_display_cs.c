/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_cs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguerand <vguerand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 14:19:18 by vguerand          #+#    #+#             */
/*   Updated: 2017/12/18 19:29:10 by vguerand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_display_cs(const char *restrict format, va_list *ap, p_f parse)
{
	int nbr;
	char *str;
	wchar_t *str1;


	nbr = 0;
	str1 = NULL;
	str = NULL;
	while((parse.flag = ft_cchr("l", format[parse.i])))
	{
		nbr++;
		parse.i++;
	}
	if (!(parse.type = ft_cchr("sScC", format[parse.i])))
		return (0);
	if (nbr == 0)
	{
		str = va_arg(*ap, char *);
		parse.val_ret = aff_struct((int)ft_strlen(str), parse);
		parse.val_ret += ft_display_char(str, parse);
		if (parse.neg.val)
			parse.val_ret += ft_display_c(find_nbr(parse, parse.neg.width, (int)ft_strlen(str)), 32);
	}
	if (nbr >= 1)
	{
		str1 = va_arg(*ap, wchar_t *);
		parse.val_ret = aff_struct((int)ft_strlen(str), parse);
	}
	return (parse.val_ret);
}
