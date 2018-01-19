/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_char.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguerand <vguerand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 16:26:06 by vguerand          #+#    #+#             */
/*   Updated: 2018/01/18 23:14:20 by vguerand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_display_char(char *str, t_f parse)
{
	if (parse.precision.val == 1)
	{
		if (ft_strchr("DdioOuUxXp", parse.type))
		{
			if ((int)ft_strlen(str) < parse.precision.width && \
			parse.precision.width)
			{
				parse.val_ret += ft_display_c(parse.precision.width - \
					(int)ft_strlen(str) - ((parse.type == 'o' || parse.type  \
					== 'O') ? (parse.htag.width) : 0), 48);
				parse.val_ret += ft_putstr_len(str, parse.precision.width);
			}
			else if (parse.precision.width <= (int)ft_strlen(str) && \
			!parse.neutral)
				parse.val_ret += ft_putstr_len(str, (int)ft_strlen(str));
		}
		else if (ft_strchr("sS", parse.type))
			parse.val_ret += ft_putstr_len(str, parse.precision.width);
		else
			parse.val_ret += ft_putstr_len(str, (int)ft_strlen(str));
	}
	else
		parse.val_ret += ft_putstr_len(str, (int)ft_strlen(str));
	return (parse.val_ret);
}
