/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguerand <vguerand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/09 19:39:39 by vguerand          #+#    #+#             */
/*   Updated: 2018/01/12 16:48:04 by vguerand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ft_parse_format3(const char *restrict format, p_f *parse,\
	va_list *ap)
{
	char *tmp;

	tmp = NULL;
	if (format[parse->i] == '-')
	{
		parse->neg.val = 1;
		while (format[parse->i] == '-')
			parse->i++;
		if (format[parse->i] == '+')
		{
			parse->plus = 1;
			while (format[parse->i] == '+')
				parse->i++;
		}
		if (format[parse->i] == '*')
			parse->neg.width = va_arg(*ap, int);
		else
		{
			while (format[parse->i] == '0')
				parse->i++;
			parse->neg.width = ft_atoi(format + parse->i);
			tmp = ft_itoa(parse->neg.width);
			parse->i += ft_strlen(tmp);
			if (!parse->neg.width)
				parse->i--;
			ft_strdel(&tmp);
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
	char *tmp;

	tmp = NULL;
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
		if (format[parse->i] == '*')
			parse->zero.width = va_arg(*ap, int);
		else if (format[parse->i] == '+')
		{
			parse->plus = 1;
			while (format[parse->i] == '+')
				parse->i++;
			if ((ft_isdigit(format[parse->i])))
			{
				parse->zero.width = ft_atoi(format + parse->i);
				tmp = ft_itoa(parse->zero.width);
				parse->i += ft_strlen(tmp);
				if (!parse->zero.width)
					parse->i--;
				ft_strdel(&tmp);
			}
		}
		else
		{
			parse->zero.width = ft_atoi(format + parse->i);
			tmp = ft_itoa(parse->zero.width);
			parse->i += ft_strlen(tmp);
			if (!parse->zero.width)
				parse->i--;
			ft_strdel(&tmp);
		}
	}
}

static void		ft_parse_format1(const char *restrict format, p_f *parse,\
	va_list *ap)
{
	char *tmp;

	tmp = NULL;
	if (format[parse->i] == '#')
	{
		parse->htag.val = 1;
		parse->htag.width = 2;
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
		if (format[parse->i] == '*')
		{
			parse->precision.width = va_arg(*ap, int);
			parse->i++;
		}
		else if (ft_isdigit(format[parse->i]))
		{
			parse->precision.width = ft_atoi(format + parse->i);
			tmp = ft_itoa(parse->precision.width);
			parse->i += ft_strlen(tmp);
			ft_strdel(&tmp);
		}
	}
}

static int	ft_parse_format_pourcent(const char *restrict format, p_f *parse)
{
	int i;
	int bol;

	bol = 0;
	i = parse->i;
	parse->val_ret = 0;
	while (!(ft_cchr("%\0", format[i])))
	{
		if ((ft_strchr("hljzsSpdDioOuUxXcC.+0123456789*-# ", format[i])))
			return (1);
		if (!(ft_strchr(".+0123456789*-# ", format[i])))
		{
			bol = 1;
			break ;
		}
		i++;
	}
	parse->pourcent = 1;
	parse->precision.val = 0;
	parse->space.val = 0;
	parse->plus = 0;
	parse->val_ret = aff_struct(1, parse);
	if (!bol)
	{
		ft_putchar('%');
		parse->i = i + 1;
		parse->val_ret += 1;
	}
	else if (bol)
	{
		parse->val_ret += ft_putnchar(format[parse->i], 1);
		parse->i++;
	}
	if (parse->neg.val)
		parse->val_ret += ft_display_c(find_nbr(*parse, parse->neg.width, 1), 32);
	return (0);
}

static void	ft_parse_format_ltr(const char *restrict format, p_f *parse)
{
	while((ft_cchr("l", format[parse->i])))
	{
		parse->flag.val = 'l';
		parse->flag.width++;
		parse->i++;
	}
	while((ft_cchr("h", format[parse->i])))
	{
		parse->flag.val = 'h';
		parse->flag.width++;
		parse->i++;
	}
	while((ft_cchr("j", format[parse->i])))
	{
		parse->flag.val = 'j';
		parse->flag.width++;
		parse->i++;
	}
	while((ft_cchr("z", format[parse->i])))
	{
		parse->flag.val = 'z';
		parse->flag.width++;
		parse->i++;
	}
	parse->type = format[parse->i];
	parse->i++;
}

void 	ft_parse_regle(p_f *parse)
{
	if (parse->plus && (parse->type == 'o' || parse->type == 's' || parse->type == 'S' || parse->type == 'c' || parse->type == 'C' || parse->type == 'u' || parse->type == 'O' || parse->type == 'U' || parse->type == 'x' || parse->type == 'X' || parse->type == 'p'))
		parse->plus = 0;
	if (parse->space.val && (parse->type == 'o' || parse->type == 'u' || parse->type == 's' || parse->type == 'S' || parse->type == 'O' || parse->type == 'U' || parse->type == 'x' || parse->type == 'X' || parse->type == 'p' || parse->type == 'c' || parse->type == 'C'))
		parse->space.val = 0;
	if (parse->neg.val && parse->zero.val)
	{
		parse->zero.val = 0;
		parse->zero.width = 0;
	}
	if (parse->precision.val && parse->zero.val && parse->plus)
	{
		parse->width.val = 1;
		parse->width.width = parse->zero.width;
		parse->zero.val = 0;
	}
	if (parse->precision.width > parse->width.width && (parse->type != 's'))
	{
		parse->width.val = 0;
		parse->width.width = 0;
	}

	if (parse->neg.val && parse->htag.val && parse->width.val)
	{
		parse->width.val = 0;
		parse->neg.width = parse->width.width;
	}
	if (parse->space.val && (parse->plus || parse->type == 'u' || parse->type == 'c'))
		parse->space.val = 0;
	if (parse->plus && (parse->type == 'u' || parse->type == 'c'))
	{
		parse->space.val = 0;
		parse->plus = 0;
	}
	if (parse->precision.width < 0 && (parse->type == 'c' || parse->type == 'C' || parse->type == 's' || parse->type == 'S'))
		parse->precision.width = - parse->precision.width;
	else if (parse->precision.width < 0 && (parse->type != 'c' || parse->type != 'C' || parse->type != 's' || parse->type != 'S'))
		parse->precision.val = 0;
	if ((parse->type == 'c' || parse->type == 'C') && parse->zero.val && parse->precision.val)
		parse->precision.val = 0;
	if ((parse->type == 'c' || parse->type == 'C') && parse->plus)
		parse->plus = 0;
}

p_f	ft_parse_format(const char *restrict format, int i, va_list *ap)
{
	p_f parse;
	char *tmp;
	tmp = NULL;

	parse = ft_init_struct();
	parse.i = i;
	while (!(ft_strchr("hljzsSpdDioOuUxXcC", format[parse.i])))
	{
		if (format[parse.i] == '*')
		{
			parse.width.width = va_arg(*ap, int);
			if (parse.width.width < 0)
			{
				parse.neg.width = -parse.width.width;
				parse.neg.val = 1;
			}
			else
				parse.width.val = 1;
			parse.i++;
		}
		ft_parse_format1(format, &parse, ap);
		ft_parse_format2(format, &parse, ap);
		ft_parse_format3(format, &parse, ap);
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
	return (parse);
}

int				ft_printf(const char *restrict format, ...)
{
	int			i;
	int 		a;
	int 		val_ret;
	va_list ap;

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
			i = parse.i;
			if (parse.pourcent == 0)
			{
				if ((a = ft_display(&ap, parse)) == -1)
					return (-1);
				else
					val_ret += a;
			}
		}
		if (i >= (int)ft_strlen((char *)format))
			break ;

	}
	return (val_ret);
}
