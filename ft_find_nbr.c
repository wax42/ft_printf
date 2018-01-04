/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_nbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguerand <vguerand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 19:26:48 by vguerand          #+#    #+#             */
/*   Updated: 2018/01/04 17:03:52 by vguerand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int find_nbr(p_f parse, int size, int str)
{
	if (ft_strchr("s,S", parse.type) && parse.precision.val == 1)
		return (parse.precision.width > str ? ((parse.neg.val) ? (parse.neg.width - str) : str): size - parse.precision.width);
	else
		return (size - str - parse.space.width);
}
