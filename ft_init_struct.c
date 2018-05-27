/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_struct.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguerand <vguerand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 14:16:03 by vguerand          #+#    #+#             */
/*   Updated: 2018/01/19 01:00:02 by vguerand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_f		ft_init_struct(void)
{
	t_f parse;

	parse.neutral = 0;
	parse.precision.val = 0;
	parse.precision.width = 0;
	parse.space.val = 0;
	parse.space.width = 0;
	parse.val_ret = 0;
	parse.flag.val = 0;
	parse.flag.width = 0;
	parse.type = 'A';
	parse.pourcent = 0;
	parse.htag.val = 0;
	parse.htag.width = 0;
	parse.zero.val = 0;
	parse.zero.width = 0;
	parse.neg.val = 0;
	parse.neg.width = 0;
	parse.plus = 0;
	parse.width.val = 0;
	parse.width.width = 0;
	return (parse);
}
