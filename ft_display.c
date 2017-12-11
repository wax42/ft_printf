/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguerand <vguerand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 16:36:11 by vguerand          #+#    #+#             */
/*   Updated: 2017/12/11 17:04:41 by vguerand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"



void ft_display(const char *restrict format, int i, va_list ap, p_f parse)
{
	long long 		var_int;
	unsigned char 	*var_char;

	while (!ft_strchr("hljz", format[i]))
 		i++; // on zappe les flags de merde

	if (ft_strchr("DdioOuUxX", format[i]))
	{
		var_int = va_arg(ap, long long);
		if (var_int < 0)
			parse.neg_int = 1;
		var_char = ft_itoa(var_int) + parse.neg_int;
	}
	else if (ft_strchr("sScC", format[i]))
		var_char = va_arg(ap, unsigned char *)
	else if (ft_strchr("p"))
		//type de merde

}
