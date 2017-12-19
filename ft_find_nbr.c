/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_nbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguerand <vguerand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 19:26:48 by vguerand          #+#    #+#             */
/*   Updated: 2017/12/18 19:27:13 by vguerand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int find_nbr(p_f parse, int size, int str)
{
	if (ft_strchr("s,S", parse.type) && parse.precision.val != 0)
		return (parse.precision.width > str ? str : size - parse.precision.width);
	else
		return (size - str - parse.space.width);
}
