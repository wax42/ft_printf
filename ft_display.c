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

    if ((parse.val_ret = ft_display_di_hh(format, ap, parse)))
        return (parse.val_ret);
        // dDioOuxX gérés tous ensemble
    if ((parse.val_ret = ft_display_di_ll(format, ap, parse)))
        return (parse.val_ret);
        // dDioOxX pas geres ensemble a cause du long (besoin d'un itoa base long)
    if ((parse.val_ret = ft_display_di_j(format, ap, parse)))
        return (parse.val_ret);
        //pareil (intmax_t)

    if ((parse.val_ret = ft_display_di_z(format, ap, parse)))
        return (parse.val_ret);
        //pareil (size_t)

    if ((parse.val_ret = ft_display_di_none(format, ap, parse)))
        return (parse.val_ret);
        // dDioOuxX ensemble
  /*
    if ((val_ret = ft_display_u_ll())) // gere le l et le ll
        return (val_ret);
    if ((val_ret = ft_display_u_j()))
        return (val_ret);
    if ((val_ret = ft_display_u_z()))
        return (val_ret);
    if ((val_ret = ft_display_p_none()))
        return (val_ret);
  */
    return (0);
}
