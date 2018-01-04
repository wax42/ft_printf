/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguerand <vguerand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 16:36:11 by vguerand          #+#    #+#             */
/*   Updated: 2018/01/04 17:19:19 by vguerand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_display(const char *restrict format, va_list *ap, p_f parse)
{
    if ((parse.val_ret = ft_display_s(format, ap, parse)))
        return (parse.val_ret);
	if ((parse.val_ret = ft_display_little_c(format, ap, parse)))
		return (parse.val_ret);
    if ((parse.val_ret = ft_display_di_hh(format, ap, parse)))
        return (parse.val_ret);

    if ((parse.val_ret = ft_display_di_ll(format, ap, parse)))
        return (parse.val_ret);

    if ((parse.val_ret = ft_display_di_j(format, ap, parse)))
        return (parse.val_ret);

    if ((parse.val_ret = ft_display_di_z(format, ap, parse)))
        return (parse.val_ret);

    if ((parse.val_ret = ft_display_di_none(format, ap, parse)))
        return (parse.val_ret);

  /*
    if ((val_ret = ft_display_p_none()))
        return (val_ret);
  */
    return (0);
}
