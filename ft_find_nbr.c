/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_nbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguerand <vguerand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 19:26:48 by vguerand          #+#    #+#             */
/*   Updated: 2018/01/19 00:56:16 by vguerand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	find_nbr(t_f parse, int size, int str)
{
	if ((!str && parse.neg.width != size))
		return (parse.width.width);
	else if (ft_strchr("s,S,C", parse.type) && parse.precision.val == 1 \
	&& parse.neg.val == 0 && str)
		return (parse.precision.width > str ? (size - str) : size - \
			parse.precision.width);
	else if (ft_strchr("s,S,C", parse.type) && parse.neg.val == 1 && \
	parse.precision.val == 1)
		return (parse.precision.width > str ? (size - str) : size - \
		parse.precision.width);
	else
	{
		if (size < parse.precision.width || (parse.precision.val == 0 || \
			parse.precision.width == 0) || (parse.precision.width < str))
			return (size - str - parse.space.width - parse.plus);
		else
			return (size - parse.space.width - parse.precision.width - \
				parse.plus);
	}
}
