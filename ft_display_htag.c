/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_htag.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguerand <vguerand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 15:55:25 by vguerand          #+#    #+#             */
/*   Updated: 2017/12/18 15:55:53 by vguerand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int     ft_display_htag(p_f parse)
{
   if (parse.type == 'o' || parse.type == 'O')
   {
	 ft_putchar('0');
	 return (1);
   }
   if (parse.type == 'x')
   {
	 ft_putstr("0x");
	 return (2);
   }
   if (parse.type == 'X')
   {
	 ft_putstr("0X");
	 return (2);
   }
   return (0);
}
