/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cchr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguerand <vguerand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 15:05:03 by vguerand          #+#    #+#             */
/*   Updated: 2017/12/18 15:05:11 by vguerand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char    ft_cchr(const char *s, int c)
{
   int i;

   i = 0;
   while (s[i] != c && s[i])
	   i++;
   if (s[i] == c)
	   return (s[i]);
   return (0);
}
