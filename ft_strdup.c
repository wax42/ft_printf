/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguerand <vguerand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 09:49:39 by vguerand          #+#    #+#             */
/*   Updated: 2017/12/22 12:13:57 by vguerand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strdup(const char *s1)
{
	char *pc;

	pc = (char *)malloc(sizeof(*pc) * (ft_strlen(s1) + 1));
	if (pc != NULL)
	{
		ft_strcpy(pc, s1);
	}
	return (pc);
}
