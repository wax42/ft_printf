/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguerand <vguerand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/09 19:39:39 by vguerand          #+#    #+#             */
/*   Updated: 2017/12/11 18:14:52 by vguerand         ###   ########.fr       */
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
	parse.neg_int = 0;

	parse.width.val = 0;
	parse.width.width = 0;
	return (parse);
}


p_f 	ft_parse_format(const char *restrict format, int i, va_list *ap)
{
	p_f parse;

	parse = ft_init_struct();
	parse.i = i;
	while (!(ft_strchr("hljzsSpdDioOuUxXcC", format[parse.i])))
	{
		if (format[parse.i] == '#')
		{
			parse.htag = 1;
			while (format[parse.i] == '#')
				parse.i++;
		}
		if (format[parse.i] == 32)
		{
			parse.space = 1;
			while (format[parse.i] == 32)
				parse.i++;
		}
		if (format[parse.i] == '.')
		{
			parse.precision.val = 1;
			while (format[parse.i] == '.')
				parse.i++;
			if (format[parse.i] == '*')
				parse.precision.width =  va_arg(*ap, int);
			else
			{
				parse.precision.width = ft_atoi(format + parse.i);
				parse.i += ft_strlen(ft_itoa(parse.zero.width));
			}
		}
		if (format[parse.i] == '-')
		{
			parse.neg.val = 1;
			while (format[parse.i] == '-')
				i++;
			if (format[parse.i++] == '*')
				parse.neg.width =  va_arg(*ap, int);
			else
			{
				parse.neg.width = ft_atoi(format + parse.i);
				parse.i += ft_strlen(ft_itoa(parse.zero.width));
			}
		}
		if (format[parse.i] == '+')
		{
			parse.plus = 1;
			while (format[parse.i] == '+')
				parse.i++;
		}
		if (format[parse.i] == '0')
		{
			parse.zero.val = 1;
			while (format[parse.i] == '0')
				parse.i++;
			if (format[parse.i++] == '*')
				parse.zero.width =  va_arg(*ap, int);
			else
			{
				parse.zero.width = ft_atoi(format + parse.i);
				parse.i += ft_strlen(ft_itoa(parse.zero.width));
			}
		}
		if (format[parse.i] == '*')
		{
			parse.width.val = 1;
			while (format[parse.i] == '*')
				parse.i++;
			parse.zero.width = va_arg(*ap, int);
		}
		if (ft_isdigit(format[parse.i]))
		{
			parse.width.val = 1;
			parse.width.width = ft_atoi(format + parse.i);
			parse.i += ft_strlen(ft_itoa(parse.width.width));
		}
		else
			parse.i++; // maybe faut l enlever
	}
	return (parse);
}



int ft_printf(const char * restrict format, ...)
{
	int 	i;
	va_list ap;


	va_start(ap, format);
	i = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			if (format[i + 1] != '%')
				ft_display(format, &ap, ft_parse_format(format, i, &ap));
		}
		i++;
	}
	return (0);
}


int main()
{
	int a;
	int *ptr;

	a = 2;
	ptr = &a;
	ft_printf("%... d", 2);
	//printf("%d", a);
	//printf("%p", "2");
	return (0);
}
