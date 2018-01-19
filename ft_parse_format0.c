/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_format0.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguerand <vguerand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 01:22:53 by vguerand          #+#    #+#             */
/*   Updated: 2018/01/19 01:22:54 by vguerand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_parse_format0(const char *restrict format, t_f *parse,\
	va_list *ap)
{
	if (format[parse->i] == '*')
	{
		parse->width.width = va_arg(*ap, int);
		if (parse->width.width < 0)
		{
			parse->neg.width = -parse->width.width;
			parse->neg.val = 1;
		}
		else
			parse->width.val = 1;
		parse->i++;
	}
}
