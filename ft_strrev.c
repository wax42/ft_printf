/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguerand <vguerand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 13:44:17 by vguerand          #+#    #+#             */
/*   Updated: 2018/01/18 21:23:00 by mbarthe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strrev(char *str)
{
	char	*tmp;
	int		i;
	int		k;

	i = ft_strlen(str);
	k = 0;
	tmp = (char *)malloc(sizeof(char) * i + 1);
	while (i--)
	{
		tmp[k] = str[i];
		k++;
	}
	tmp[k] = '\0';
	ft_strdel(&str);
	return (tmp);
}
