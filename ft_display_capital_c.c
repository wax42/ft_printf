/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_capital_c.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguerand <vguerand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 17:12:33 by vguerand          #+#    #+#             */
/*   Updated: 2018/01/12 17:06:35 by vguerand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_capital_n(t_f *parse, int n, wchar_t str)
{
	parse->val_ret = aff_struct(n, parse);
	parse->val_ret += n;
	if (n == 0 || n == 1)
		ft_putnchar(str, 1);
	else
		ft_putwchar(str);
	if (parse->neg.val)
	{
		parse->precision.val = 1;
		parse->val_ret += ft_display_c(find_nbr(*parse, parse->neg.width - n,\
		n), 32);
	}
	return (parse->val_ret);
}

int	ft_display_capital_c(va_list *ap, t_f parse)
{
	wchar_t str;

	if (parse.flag.val == 'l' && parse.type == 'c')
		parse.type = 'C';
	if (parse.type != 'C')
		return (0);
	str = va_arg(*ap, long int);
	if ((str >= 0 && str < 128 && MB_CUR_MAX >= 1))
		return (ft_capital_n(&parse, 1, str));
	else if (str >= 128 && str < 2048 && MB_CUR_MAX >= 2)
		return (ft_capital_n(&parse, 2, str));
	else if (str >= 2048 && str < 65536 && MB_CUR_MAX >= 3)
		return (ft_capital_n(&parse, 3, str));
	else if (str >= 65536 && str < 263425 && MB_CUR_MAX == 4)
		return (ft_capital_n(&parse, 4, str));
	else
		return (-1);
	return (parse.val_ret);
}
