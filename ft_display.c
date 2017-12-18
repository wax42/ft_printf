/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguerand <vguerand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 16:36:11 by vguerand          #+#    #+#             */
/*   Updated: 2017/12/18 13:46:19 by vguerand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_display(const char *restrict format, va_list *ap, p_f parse)
{
    long long         var_int;
    unsigned char     *var_char;
    int        val_ret;
    int base;
    char *type;

    val_ret = 0;
    var_char = NULL;
    base = 10;
    if ((val_ret = ft_display_cs_l())) // gere le l et le ll
        return (val_ret);
    if ((val_ret = ft_display_cs_none()))
        return (val_ret);

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

    if ((type = ft_strchr("DdioOxX", format[parse.i])))
    {
        var_int = va_arg(*ap, signed long);
        if (var_int < 0)
            parse.neg_int = 1;

        ft_putnbr(base);
        var_char = (unsigned char *)ft_itoa_base(var_int, base) + parse.neg_int;
    }
    else if (ft_strchr("sScC", format[parse.i]))
        var_char = va_arg(*ap, unsigned char *);
    ft_putendl("On passe a l'affichage");
    ft_display_neg(parse, var_char);
    return (0);
}
