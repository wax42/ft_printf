/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_cs_l.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguerand <vguerand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 14:19:18 by vguerand          #+#    #+#             */
/*   Updated: 2017/12/18 15:56:28 by vguerand         ###   ########.fr       */
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
		parse.val_ret = aff_struct(str, parse);
	}
	if (nbr >= 1)
	{
		str1 = va_arg(*ap, wchar_t *);
		parse.val_ret = aff_struct(str, parse);
	}
	return (parse.val_ret);
}
