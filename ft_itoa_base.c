/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguerand <vguerand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 16:44:22 by vguerand          #+#    #+#             */
/*   Updated: 2018/01/19 01:09:15 by mbarthe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_itoa_base(int n, int base, int uppercase)
{
	char	*str;
	int		i;
	int		length;

	if (base < 2 || base > 16 || (base != 10 && n < 0))
		return (NULL);
	if (base == 10)
		return ((char *)ft_itoa_long(n));
	length = ft_nbrlen(n, base);
	str = (char*)malloc(sizeof(*str) * (length + 1));
	i = 0;
	while (i < length)
	{
		if (base > 10 && (n % base >= 10) && uppercase)
			str[i++] = (n % base) - 10 + 'A';
		else if (base > 10 && (n % base >= 10))
			str[i++] = (n % base) - 10 + 'a';
		else
			str[i++] = (n % base) + '0';
		n /= base;
	}
	str[i] = '\0';
	return (ft_strrev(str));
}
