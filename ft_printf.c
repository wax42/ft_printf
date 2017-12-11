/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguerand <vguerand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/09 19:39:39 by vguerand          #+#    #+#             */
/*   Updated: 2017/12/11 15:23:59 by vguerand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include  <stdio.h>

p_f 	ft_init_struct()
{
	p_f parse;

	parse.htag = 0;

	parse.precision.val = 0;
	parse.precision.width= 0;

	parse.space = 0;

	parse.zero.val = 0;
	parse.zero.width = 0;

	parse.neg.val = 0;
	parse.neg.width = 0;

	parse.plus = 0;

	parse.width.val = 0;
	parse.width.width = 0;
	return (parse);
}


int 	ft_parse_format(const char *restrict format, int i, va_list ap)
{
	p_f parse;

	while (ft_strcmp(&format[i], "hljzsSpdDioOuUxXcC"))
	{
		if (format[i] == '#')
		{
			parse.htag = 1;
			while (format[i] == '#')
				i++;
		}
		if (format[i] == 32)
		{
			parse.space = 1;
			while (format[i] == 32)
				i++;
		}
		if (format[i] == '.')
		{
			parse.precision.val = 1;
			while (format[i] == '.')
				i++;
			if (format[i] == '*')
				parse.precision.width =  va_arg(ap, int);
			else
			{
				parse.precision.width = ft_atoi(format + i);
				i += ft_strlen(ft_itoa(parse.zero.width));
			}
		}
		if (format[i] == '-')
		{
			parse.neg.val = 1;
			while (format[i] == '-')
				i++;
			if (format[i++] == '*')
				parse.neg.width =  va_arg(ap, int);
			else
			{
				parse.neg.width = ft_atoi(format + i);
				i += ft_strlen(ft_itoa(parse.zero.width));
			}
		}
		if (format[i] == '+')
		{
			parse.plus = 1;
			while (format[i] == '+')
				i++;
		}
		if (format[i] == '0')
		{
			parse.zero.val = 1;
			while (format[i] == '0')
				i++;
			if (format[i++] == '*')
				parse.zero.width =  va_arg(ap, int);
			else
			{
				parse.zero.width = ft_atoi(format + i);
				i += ft_strlen(ft_itoa(parse.zero.width));
			}
		}
		if (format[i] == '*')
		{
			parse.width.val = 1;
			while (format[i] == '*')
				i++;
			parse.zero.width = va_arg(ap, int);
		}
		if (ft_isdigit(format[i]))
		{
			parse.width.val = 1;
			parse.width.width = ft_atoi(format + i);
			i += ft_strlen(ft_itoa(parse.width.width));
		}
		else
			i++;
	}
	return (i);
}



int ft_printf(const char * restrict format, ...)
{
	int 	i;
	va_list ap;

	va_start(ap, format);
	while (format[i])
	{
		if (format[i] == '%')
			i = ft_parse_format(format, i, ap);
		i++;
	}
	return (0);
}


int main()
{
	printf("%10s", "salut");
	return (0);
}
