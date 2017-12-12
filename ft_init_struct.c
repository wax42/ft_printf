/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_struct.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguerand <vguerand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 14:16:03 by vguerand          #+#    #+#             */
/*   Updated: 2017/12/12 14:16:17 by vguerand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

p_f		ft_init_struct()
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
