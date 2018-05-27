/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstr_len.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguerand <vguerand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 21:10:50 by vguerand          #+#    #+#             */
/*   Updated: 2018/01/18 21:19:21 by mbarthe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_wstrlen(wchar_t *str)
{
	size_t i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

size_t	ft_wstrlen_byte(wchar_t *str, int precision)
{
	size_t	i;
	int		size;
	int		a;

	i = 0;
	size = 0;
	if (precision == 0)
		precision = 1000000;
	while (str[i])
	{
		if ((a = ft_len_unicode(str[i], precision - size)) == -1)
			break ;
		else
			size += a;
		if (size >= precision)
			break ;
		i++;
	}
	return (size);
}
