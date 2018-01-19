/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_format_ltr.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguerand <vguerand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 01:27:16 by vguerand          #+#    #+#             */
/*   Updated: 2018/01/19 01:44:44 by vguerand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_parse_format_ltr(const char *restrict format, t_f *parse)
{
	while ((ft_cchr("l", format[parse->i])))
	{
		parse->flag.val = 'l';
		parse->flag.width++;
		parse->i++;
	}
	while ((ft_cchr("h", format[parse->i])))
	{
		parse->flag.val = 'h';
		parse->flag.width++;
		parse->i++;
	}
	while ((ft_cchr("j", format[parse->i])))
	{
		parse->flag.val = 'j';
		parse->flag.width++;
		parse->i++;
	}
	while ((ft_cchr("z", format[parse->i])))
	{
		parse->flag.val = 'z';
		parse->flag.width++;
		parse->i++;
	}
	parse->type = format[parse->i++];
}
