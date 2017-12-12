/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_neg.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguerand <vguerand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 12:18:53 by vguerand          #+#    #+#             */
/*   Updated: 2017/12/12 12:34:01 by vguerand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_display_neg(p_f parse, unsigned char *var_char)
{
    int i;

    i = ft_strlen((const char *)var_char);
    if (parse.neg_int == 1)
            ft_putchar('-');
    ft_putstr((const char *)var_char);
    while (i < parse.neg.width)
    {
            ft_putchar(' ');
            i++;
    }
    return (i > 0) ? 1 : 0;
}
