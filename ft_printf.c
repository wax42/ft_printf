/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguerand <vguerand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/09 19:39:39 by vguerand          #+#    #+#             */
/*   Updated: 2017/12/18 13:41:05 by vguerand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ft_parse_format3(const char *restrict format, p_f *parse,\
	va_list *ap)
{
	if (format[parse->i] == '-')
	{
		parse->neg.val = 1;
		while (format[parse->i] == '-')
			parse->i++;
		if (format[parse->i + 1] == '*')
			parse->neg.width = va_arg(*ap, int);
		else
		{
			parse->neg.width = ft_atoi(format + parse->i);
			parse->i += ft_strlen(ft_itoa(parse->zero.width));
		}
	}
	if (format[parse->i] == '*')
	{
		parse->width.val = 1;
		while (format[parse->i] == '*')
			parse->i++;
		parse->zero.width = va_arg(*ap, int);
	}
}

static void		ft_parse_format2(const char *restrict format, p_f *parse,\
	va_list *ap)
{
	if (format[parse->i] == '+')
	{
		parse->plus = 1;
		while (format[parse->i] == '+')
			parse->i++;
	}
	if (format[parse->i] == '0')
	{
		parse->zero.val = 1;
		while (format[parse->i] == '0')
			parse->i++;
		if (format[parse->i + 1] == '*')
			parse->zero.width = va_arg(*ap, int);
		else
		{
			parse->zero.width = ft_atoi(format + parse->i);
			parse->i += ft_strlen(ft_itoa(parse->zero.width));
		}
	}
}

static void		ft_parse_format1(const char *restrict format, p_f *parse,\
	va_list *ap)
{
	if (format[parse->i] == '#')
	{
		parse->htag = 1;
		while (format[parse->i] == '#')
			parse->i++;
	}
	if (format[parse->i] == 32)
	{
		parse->space = 1;
		while (format[parse->i] == 32)
			parse->i++;
	}
	if (format[parse->i] == '.')
	{
		parse->precision.val = 1;
		while (format[parse->i] == '.')
			parse->i++;
		if (format[parse->i + 1] == '*')
			parse->precision.width = va_arg(*ap, int);
		else
		{
			parse->precision.width = ft_atoi(format + parse->i);
			parse->i += ft_strlen(ft_itoa(parse->zero.width));
		}
	}
}

p_f				ft_parse_format(const char *restrict format, int i, va_list *ap)
{
	p_f parse;

	parse = ft_init_struct();
	parse.i = i;
	while (!(ft_strchr("hljzsSpdDioOuUxXcC", format[parse.i])))
	{
		ft_parse_format1(format, &parse, ap);
		ft_parse_format2(format, &parse, ap);
		ft_parse_format3(format, &parse, ap);
		if (ft_isdigit(format[parse.i]))
		{
			parse.width.val = 1;
			parse.width.width = ft_atoi(format + parse.i);
			parse.i += ft_strlen(ft_itoa(parse.width.width));
		}
	}
	return (parse);
}

int				ft_printf(const char *restrict format, ...)
{
	int		i;
	va_list ap;

	va_start(ap, format);
	i = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			if (format[i + 1] != '%')
				ft_display(format, &ap, ft_parse_format(format, i + 1, &ap));
			else
			{
				ft_putchar('%');
			}
		}
		i++;
	}
	return (0);
}
