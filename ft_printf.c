/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguerand <vguerand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/09 19:39:39 by vguerand          #+#    #+#             */
/*   Updated: 2018/01/19 01:16:18 by vguerand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_parse_format_all(const char *restrict format, t_f *parse, \
	va_list *ap)
{
	ft_parse_format0(format, parse, ap);
	ft_parse_format1(format, parse, ap);
	ft_parse_format2(format, parse, ap);
	ft_parse_format3(format, parse, ap);
	ft_parse_format4(format, parse, ap);
}

t_f			ft_parse_format(const char *restrict format, int i, \
	va_list *ap)
{
	t_f		parse;
	char	*tmp;

	tmp = NULL;
	parse = ft_init_struct();
	parse.i = i;
	while (!(ft_strchr("hljzsSpdDioOuUxXcC", format[parse.i])))
	{
		ft_parse_format_all(format, &parse, ap);
		if (ft_isdigit(format[parse.i]) && format[parse.i] != '0')
		{
			parse.width.val = 1;
			parse.width.width = ft_atoi(format + parse.i);
			tmp = ft_itoa(parse.width.width);
			parse.i += ft_strlen(tmp);
			ft_strdel(&tmp);
		}
		if (!(ft_parse_format_pourcent(format, &parse)))
			return (parse);
	}
	ft_parse_format_ltr(format, &parse);
	ft_parse_regle(&parse);
	ft_parse_regle_2(&parse);
	return (parse);
}

static int	ft_printf1(const char *restrict format, int *i, int val_ret, \
	va_list *ap)
{
	int		a;
	t_f		parse;

	if (format[*i] == '%')
	{
		parse = ft_parse_format(format, *i + 1, ap);
		val_ret += parse.val_ret;
		*i = parse.i;
		if (parse.pourcent == 0)
		{
			if ((a = ft_display(ap, parse)) == -1)
				return (-1);
			else
				val_ret += a;
		}
	}
	return (val_ret);
}

int			ft_printf(const char *restrict format, ...)
{
	int		i;
	int		val_ret;
	va_list ap;

	val_ret = 0;
	va_start(ap, format);
	i = 0;
	while (format[i] != '\0')
	{
		while (format[i] != '\0' && format[i] != '%' && format[i])
		{
			val_ret += ft_putnchar(format[i], 1);
			i++;
		}
		if ((val_ret = ft_printf1(format, &i, val_ret, &ap)) == -1)
			return (-1);
		if (i >= (int)ft_strlen((char *)format))
			break ;
	}
	return (val_ret);
}
