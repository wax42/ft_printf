/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_wchar.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguerand <vguerand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 21:09:36 by vguerand          #+#    #+#             */
/*   Updated: 2018/01/19 00:54:34 by vguerand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_verif_unicode(wchar_t str, int precision)
{
	if (-1 == ft_len_unicode(str, precision))
		return (0);
	if (str > 0 && str < 128 && MB_CUR_MAX >= 1)
		return (ft_putnchar(str, 1));
	else if (str >= 128 && str < 2048 && MB_CUR_MAX >= 2)
	{
		ft_putwchar(str);
		return (2);
	}
	else if (str >= 2048 && str < 65536 && MB_CUR_MAX >= 3)
	{
		ft_putwchar(str);
		return (3);
	}
	else if (str >= 65536 && str < 263425 && MB_CUR_MAX >= 4)
	{
		ft_putwchar(str);
		return (4);
	}
	else if (str == 0)
		return (ft_putnchar('\0', 1));
	else
		return (-1);
}

int	ft_len_unicode(wchar_t str, int precision)
{
	if (str > 0 && str < 128 && MB_CUR_MAX >= 1 && precision >= 1)
		return (1);
	else if (str >= 128 && str < 2048 && MB_CUR_MAX >= 2 && precision >= 2)
		return (2);
	else if (str >= 2048 && str < 65536 && MB_CUR_MAX >= 3 && precision >= 3)
		return (3);
	else if (str >= 65536 && str < 263425 && MB_CUR_MAX >= 4 && precision >= 4)
		return (4);
	else if (str == 0)
		return (1);
	else
		return (-1);
}

int	ft_putwstr(wchar_t *str, int size, int precision)
{
	int i;
	int val_ret;
	int a;

	val_ret = 0;
	i = 0;
	while (i < size)
	{
		if ((a = ft_verif_unicode(str[i], precision - val_ret)) == -1)
			return (-1);
		else
			val_ret += a;
		if (val_ret >= precision)
			break ;
		i++;
	}
	return (val_ret);
}

int	ft_display_wchar(wchar_t *str, t_f parse)
{
	size_t size;

	size = ft_wstrlen(str);
	if (parse.precision.val == 1)
		parse.val_ret += ft_putwstr(str, (int)size, parse.precision.width);
	else
		parse.val_ret += ft_putwstr(str, (int)size, \
		ft_wstrlen_byte(str, 100000));
	return (parse.val_ret);
}
