/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwstr_len.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguerand <vguerand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 21:15:33 by vguerand          #+#    #+#             */
/*   Updated: 2017/12/18 21:24:24 by vguerand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_putwstr_len(wchar_t *s, size_t len)
{
	size_t i;

	i = 0;
	if (s != NULL)
	{
		while (i < len && s[i])
		{
			ft_putwchar(s[i]);
			i++;
		}
	}
	return (i);
}
