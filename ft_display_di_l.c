/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_di_l.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguerand <vguerand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 16:36:11 by vguerand          #+#    #+#             */
/*   Updated: 2018/01/19 01:44:44 by vguerand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_display_di_l3(t_f *parse, long int sa, unsigned long long *la, \
	char *str)
{
	(sa < 0) ? (parse->space.width = 1) : parse->space.width;
	if (sa == 0)
	{
		if (parse->type != 'x')
		{
			(parse->precision.val == 1 && parse->precision.width == 0) ? (str =\
				"") : str;
			parse->neutral = 1;
			if ((parse->type == 'o' || parse->type == 'O') && parse->htag.val)
				parse->neutral = 0;
		}
	}
	else
	{
		if (parse->space.width)
			*la = -sa;
		else
			(*la = sa);
	}
	return (str);
}

static void	ft_display_di_l2(char *str, t_f *parse)
{
	parse->val_ret = aff_struct((int)ft_strlen(str), parse);
	parse->val_ret = ft_display_char(str, *parse);
	if (parse->neg.val && parse->precision.width <= parse->neg.width)
		parse->val_ret += ft_display_c(find_nbr(*parse, parse->neg.width - \
			parse->htag.width + parse->plus, (int)ft_strlen(str)), 32);
	if (str[0] != '\0')
		ft_strdel(&str);
}

static int	ft_condition(t_f *parse)
{
	if (ft_cchr("DUO", parse->type))
	{
		parse->flag.val = 'l';
		parse->flag.width = 1;
	}
	if (!(ft_cchr("DUdiuoOxX", parse->type)) || (!(ft_cchr("l", \
	parse->flag.val)) || parse->flag.width < 1))
		return (0);
	return (1);
}

int			ft_display_di_l(va_list *ap, t_f parse)
{
	long int				sa;
	unsigned long long int	la;
	char					*str;

	la = 0;
	sa = 0;
	str = NULL;
	if (ft_condition(&parse) == 0)
		return (0);
	(parse.type == 'u' || parse.type == 'U' || parse.type == 'x' || \
	parse.type == 'X') ? la = va_arg(*ap, unsigned long int) : sa;
	(parse.type == 'o' || parse.type == 'O') ? la = va_arg(*ap, \
		unsigned long int) : sa;
	(parse.type == 'd' || parse.type == 'i' || parse.type == 'D') ?\
	sa = va_arg(*ap, long int) : sa;
	str = ft_display_di_l3(&parse, sa, &la, str);
	(parse.type == 'x' ? str = ft_itoa_base_max(la, 16, 0) : str);
	(parse.type == 'X' ? str = ft_itoa_base_max(la, 16, 1) : str);
	(parse.type == 'd' || parse.type == 'i' || parse.type == 'u' || parse.type \
	== 'D' || parse.type == 'U') ? str = ft_itoa_base_max(la, 10, 0) : str;
	((parse.type == 'o' || parse.type == 'O') && str == NULL) ? str = \
	ft_itoa_base_max(la, 8, 0) : str;
	ft_display_di_l2(str, &parse);
	return (parse.val_ret);
}
