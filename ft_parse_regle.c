/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_regle.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguerand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 01:19:57 by vguerand          #+#    #+#             */
/*   Updated: 2018/01/19 01:20:02 by vguerand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_parse_regle_2(t_f *parse)
{
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
	if (parse->space.val && (parse->plus || parse->type == 'u' ||\
		parse->type == 'c'))
		parse->space.val = 0;
	if (parse->precision.width < 0 && (parse->type == 'c' || parse->type == 'C'\
		|| parse->type == 's' || parse->type == 'S'))
		parse->precision.width = -parse->precision.width;
	else if (parse->precision.width < 0 && (parse->type != 'c' ||\
		parse->type != 'C' || parse->type != 's' || parse->type != 'S'))
		parse->precision.val = 0;
	if ((parse->type == 'c' || parse->type == 'C') && parse->zero.val &&\
		parse->precision.val)
		parse->precision.val = 0;
	if ((parse->type == 'c' || parse->type == 'C') && parse->plus)
		parse->plus = 0;
}

void	ft_parse_regle(t_f *parse)
{
	if (parse->plus && (ft_strchr("oOsScCuUxXp", parse->type)))
		parse->plus = 0;
	if (parse->space.val && (ft_strchr("oOsScCuUxXp", parse->type)))
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
	if (parse->plus && (parse->type == 'u' || parse->type == 'c'))
	{
		parse->space.val = 0;
		parse->plus = 0;
	}
}
