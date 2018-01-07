/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_cs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguerand <vguerand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 14:19:18 by vguerand          #+#    #+#             */
/*   Updated: 2017/12/25 20:43:37 by vguerand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_wstr_len(wchar_t* str)
{
	size_t i;

	i = 0;
	while(str[i])
		i++;
	return (i);
}


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
		if (str != NULL)
			parse.val_ret = ft_display_char(str, parse);
		if (parse.neg.val)
			parse.val_ret += ft_display_c(find_nbr(parse, parse.neg.width, (int)ft_strlen(str)), 32);
	}
	else if (nbr >= 1)
	{
		str1 = va_arg(*ap, wchar_t *);
		parse.val_ret = aff_struct((int)ft_wstrlen(str1), parse);
		parse.val_ret = ft_display_wchar(str1, parse);
		if (parse.neg.val)
			parse.val_ret += ft_display_c(find_nbr(parse, parse.neg.width, (int)ft_wstrlen(str1)), 32);
	}
	return (parse.val_ret);
}
