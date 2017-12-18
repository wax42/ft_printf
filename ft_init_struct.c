/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_struct.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguerand <vguerand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 14:16:03 by vguerand          #+#    #+#             */
/*   Updated: 2017/12/12 14:24:31 by vguerand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

p_f		ft_init_struct(void)
{
	p_f parse;

	parse.htag = 0;
	parse.precision.val = 0;
	parse.precision.width = 0;
	parse.space.val = 0;
	parse.space.width = 0;

	parse.val_ret = 0;

	parse.zero.val = 0;
	parse.zero.width = 0;
	parse.neg.val = 0;
	parse.neg.width = 0;
	parse.plus = 0;
	parse.width.val = 0;
	parse.width.width = 0;
	return (parse);
}
