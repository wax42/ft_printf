/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_len.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguerand <vguerand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 16:31:54 by vguerand          #+#    #+#             */
/*   Updated: 2017/12/25 20:28:20 by vguerand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr_len(char const *s, int len)
{
	int i;

	i = 0;
	if (s != NULL)
	{
		while (i < len && s[i])
		{
			ft_putchar(s[i]);
			i++;
		}
	}
	return (i);
}
