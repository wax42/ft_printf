/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguerand <vguerand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 16:36:11 by vguerand          #+#    #+#             */
/*   Updated: 2017/12/18 15:59:58 by vguerand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_display(const char *restrict format, va_list *ap, p_f parse)
{
    if ((parse.val_ret = ft_display_cs(format, ap, parse)))
        return (parse.val_ret);

/*
    if ((val_ret = ft_display_diox_hh())) //gere le h et le hh
        return (val_ret);
    if ((val_ret = ft_display_diox_ll())) // gere le l et le ll
        return (val_ret);
    if ((val_ret = ft_display_diox_j()))
        return (val_ret);
    if ((val_ret = ft_display_diox_z()))
        return (val_ret);
    if ((val_ret = ft_display_diox_none()))
        return (val_ret);
	if ((val_ret = ft_display_u_hh())) //gere le h et le hh
        return (val_ret);
    if ((val_ret = ft_display_u_ll())) // gere le l et le ll
        return (val_ret);
    if ((val_ret = ft_display_u_j()))
        return (val_ret);
    if ((val_ret = ft_display_u_z()))
        return (val_ret);
    if ((val_ret = ft_display_u_none()))
        return (val_ret);
    if ((val_ret = ft_display_p_none()))
        return (val_ret);

*/
    return (0);
}
