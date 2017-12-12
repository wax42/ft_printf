/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguerand <vguerand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 16:36:11 by vguerand          #+#    #+#             */
/*   Updated: 2017/12/12 15:06:08 by vguerand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_display(const char *restrict format, va_list *ap, p_f parse)
{
	long long 		var_int;
	unsigned char 	*var_char;
	long			val_ret;

	val_ret = 0;
	var_char = NULL;
	while (!ft_strchr("hljz", format[parse.i]))
 		parse.i++; // on zappe les flags de merde

	if (ft_strchr("DioOuUxXp", format[parse.i]))
	{

		var_int = va_arg(*ap, long long);
		if (var_int < 0)
			parse.neg_int = 1;
		var_char = ft_itoa_long(var_int) + parse.neg_int;// refaire le itoa en long long
		//et qui retourne un long long char
	}
	else if (ft_strchr("sScC", format[parse.i]))
		var_char = va_arg(*ap, unsigned char *);
	ft_putendl("On passe a l'affichage");
	ft_display_neg(parse, var_char);
	return (0);
}
