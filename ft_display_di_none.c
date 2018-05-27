/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_di_none.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguerand <vguerand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 16:36:11 by vguerand          #+#    #+#             */
/*   Updated: 2018/01/19 00:25:55 by vguerand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_display_di_none2(char *str, t_f *parse, int sa)
{
	if ((parse->type == 'x') && parse->space.width)
	{
		str = ft_itoa_base_max(4294967296 - sa, 16, 0);
		parse->space.width = 0;
	}
	if (parse->type == 'X' && parse->space.width)
	{
		str = ft_itoa_base_max(4294967295 - sa + 1, 16, 1);
		parse->space.width = 0;
	}
	parse->val_ret = aff_struct((int)ft_strlen(str), parse);
	parse->val_ret = ft_display_char(str, *parse);
	if (parse->neg.val && parse->precision.width <= parse->neg.width)
		parse->val_ret += ft_display_c(find_nbr(*parse, parse->neg.width - \
			parse->htag.width + parse->plus, (int)ft_strlen(str)), 32);
	if (str[0] != '\0')
		ft_strdel(&str);
}

static char	*ft_display_di_none1(char *str, t_f *parse, int sa, unsigned la)
{
	(parse->type == 'u') ? str = ft_itoa_unsigned(la) : str;
	(parse->type == 'd') ? str = ft_itoa(sa) : str;
	(parse->type == 'i') ? str = ft_itoa_base(sa, 10, 0) : str;
	(parse->type == 'x') ? str = ft_itoa_base(sa, 16, 0) : str;
	(parse->type == 'X') ? str = ft_itoa_base(sa, 16, 1) : str;
	(parse->type == 'o' && !(parse->space.width)) ? str = \
	ft_itoa_base(sa, 8, 0) : str;
	if (sa == 0 && la == 0)
	{
		(parse->precision.val == 1 && parse->precision.width == 0) ? (str = "")\
		: str;
		parse->neutral = 1;
		if (parse->type == 'o' && parse->htag.val)
		{
			str = "";
			parse->neutral = 0;
		}
	}
	if ((parse->type == 'o') && parse->space.width)
	{
		str = ft_itoa_base_max(4294967296 - sa, 8, 0);
		parse->space.width = 0;
	}
	return (str);
}

int			ft_display_di_none(va_list *ap, t_f parse)
{
	int				sa;
	unsigned int	la;
	char			*str;

	sa = 0;
	la = 0;
	str = NULL;
	if (!(ft_cchr("diuoxXO", parse.type)))
		return (0);
	(parse.type == 'u') ? (la = (unsigned int)va_arg(*ap, unsigned int)) : \
	(sa = (int)va_arg(*ap, int));
	(sa < 0) ? (parse.space.width = 1) : (parse.space.width);
	(parse.space.width) ? sa = -sa : sa;
	str = ft_display_di_none1(str, &parse, sa, la);
	ft_display_di_none2(str, &parse, sa);
	return (parse.val_ret);
}
