/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguerand <vguerand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 16:36:11 by vguerand          #+#    #+#             */
/*   Updated: 2018/01/18 21:33:11 by mbarthe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_display(va_list *ap, t_f parse)
{
	if ((parse.val_ret = ft_display_p(ap, parse)))
		return (parse.val_ret);
	if ((parse.val_ret = ft_display_capital_s(ap, parse)))
		return (parse.val_ret);
	if ((parse.val_ret = ft_display_s(ap, parse)))
		return (parse.val_ret);
	if ((parse.val_ret = ft_display_capital_c(ap, parse)))
		return (parse.val_ret);
	if ((parse.val_ret = ft_display_little_c(ap, parse)))
		return (parse.val_ret);
	if ((parse.val_ret = ft_display_di_hh(ap, parse)))
		return (parse.val_ret);
	if ((parse.val_ret = ft_display_di_h(ap, parse)))
		return (parse.val_ret);
	if ((parse.val_ret = ft_display_di_l(ap, parse)))
		return (parse.val_ret);
	if ((parse.val_ret = ft_display_di_j(ap, parse)))
		return (parse.val_ret);
	if ((parse.val_ret = ft_display_di_z(ap, parse)))
		return (parse.val_ret);
	if ((parse.val_ret = ft_display_di_none(ap, parse)))
		return (parse.val_ret);
	return (0);
}
