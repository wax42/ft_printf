/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguerand <vguerand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/09 19:39:39 by vguerand          #+#    #+#             */
/*   Updated: 2018/01/04 16:26:53 by vguerand         ###   ########.fr       */
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
		if (format[parse->i] == 'd')
			parse->i--;
		if (format[parse->i + 1] == '*')
			parse->neg.width = va_arg(*ap, int);
		else
		{
			parse->neg.width = ft_atoi(format + parse->i);
			parse->i += ft_strlen(ft_itoa(parse->neg.width));
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
		if (format[parse->i] == 'd')
			parse->i--;
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
		parse->space.val = 1;
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
		else if (ft_isdigit(format[parse->i]))
		{
			parse->precision.width = ft_atoi(format + parse->i);
			parse->i += ft_strlen(ft_itoa(parse->precision.width));
		}
	}
}

static int	ft_parse_format_pourcent(const char *restrict format, p_f *parse)
{
	int i;

	i = parse->i;
	parse->val_ret = 0;
	while (!(ft_cchr("%\0", format[i])))
	{
		if ((ft_strchr("hljzsSpdDioOuUxXcC", format[i])))
			return (1);
		i++;
	}
	parse->precision.val = 0;
	parse->space.val = 0;
	parse->plus = 0;
	parse->val_ret += aff_struct(1, *parse);
	ft_putchar('%');
	if (parse->neg.val)
		parse->val_ret += ft_display_c(find_nbr(*parse, parse->neg.width, 1), 32);
	parse->i = i;
	parse->val_ret += 1;
	return (0);
}

p_f	ft_parse_format(const char *restrict format, int i, va_list *ap)
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
		if (!(ft_parse_format_pourcent(format, &parse)))
			return (parse);
	}
	return (parse);
}

int				ft_printf(const char *restrict format, ...)
{
	int		i;
	va_list ap;
	int val_ret;
	p_f parse;

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
		if (format[i] == '%')
		{
			parse = ft_parse_format(format, i + 1, &ap);
			val_ret += parse.val_ret;
			i = parse.i + 1;
			val_ret += ft_display(format, &ap, parse);

		}
		if (i >= (int)ft_strlen((char *)format))
			break ;

		while((ft_strchr("hljzsSpdDioOuUxXcC", format[i])) && i < (int)ft_strlen((char *)format))
				i++;
	}
	return (val_ret);
}
