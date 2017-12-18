/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_c.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguerand <vguerand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 12:18:53 by vguerand          #+#    #+#             */
/*   Updated: 2017/12/18 16:26:01 by vguerand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int     ft_display_c(p_f parse, int size, int c)
{
    int i;

    i = size - parse.neg.width;
    while (i < parse.neg.width)
    {
            ft_putchar(c);
            i++;
    }
    return (i > 0) ? i : 0;
}
