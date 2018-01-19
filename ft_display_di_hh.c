/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_di_hh.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguerand <vguerand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 16:36:11 by vguerand          #+#    #+#             */
/*   Updated: 2018/01/18 23:25:07 by vguerand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_display_di_hh2(char *str, t_f *parse)
{
	parse->val_ret = aff_struct((int)ft_strlen(str), parse);
	parse->val_ret = ft_display_char(str, *parse);
	if (parse->neg.val && parse->precision.width <= parse->neg.width)
		parse->val_ret += ft_display_c(find_nbr(*parse, parse->neg.width - \
			parse->htag.width + parse->plus, (int)ft_strlen(str)), 32);
	ft_strdel(&str);
}

int			ft_display_di_hh(va_list *ap, t_f parse)
{
	int		sa;
	char	*str;

	sa = 0;
	str = NULL;
	if (!(ft_cchr("DdiuoOxX", parse.type)) || !(ft_cchr("h", parse.flag.val)))
		return (0);
	if (parse.flag.width != 2)
		return (0);
	(parse.type == 'u') ? sa = (unsigned char)va_arg(*ap, int) : sa;
	(parse.type == 'd' || parse.type == 'i') ? sa = (char)va_arg(*ap, int) : sa;
	(parse.type == 'O') ? sa = (uintmax_t)va_arg(*ap, int) : sa;
	(parse.type == 'o') ? sa = (unsigned char)va_arg(*ap, int) : sa;
	(parse.type == 'x' || parse.type == 'X') ? sa = \
	(unsigned char)va_arg(*ap, int) : sa;
	(sa < 0) ? parse.space.width = 1 : parse.space.width;
	(parse.space.width) ? sa = -sa : sa;
	(parse.type == 'd' || parse.type == 'i' || parse.type == 'u') ? \
	str = ft_itoa_base(sa, 10, 0) : str;
	(parse.type == 'o' || parse.type == 'O') ? str = ft_itoa_base(sa, 8, 0) \
	: str;
	(parse.type == 'x') ? str = ft_itoa_base_max(sa, 16, 0) : str;
	(parse.type == 'X') ? str = ft_itoa_base_max(sa, 16, 1) : str;
	ft_display_di_hh2(str, &parse);
	return (parse.val_ret);
}
