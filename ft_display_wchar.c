/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_wchar.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguerand <vguerand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 21:09:36 by vguerand          #+#    #+#             */
/*   Updated: 2017/12/18 21:23:26 by vguerand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_printf.h"

int ft_display_wchar(wchar_t *str, p_f parse)
{
	size_t size;

	size = ft_wstrlen(str);
	if (parse.precision.val == 1)
	{
		if (ft_strchr("dioux", parse.type))
		{
			if (size < (size_t)parse.precision.width)
				parse.val_ret += ft_display_c(parse.precision.width - (int)size , 0);
			parse.val_ret += ft_putwstr_len(str, (size_t)parse.precision.width);
		}
		else if (ft_strchr("sS", parse.type))
			parse.val_ret += ft_putwstr_len(str, (size_t)parse.precision.width);
		else
			parse.val_ret += ft_putwstr_len(str, size);
	}
	else
		parse.val_ret += ft_putwstr_len(str, 1000000);
	return (parse.val_ret);
}
