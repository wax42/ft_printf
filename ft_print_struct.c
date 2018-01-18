/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_struct.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguerand <vguerand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/22 16:09:37 by vguerand          #+#    #+#             */
/*   Updated: 2017/12/22 16:15:26 by vguerand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_print_struct(p_f parse)
{
	printf("\n,\n");
	printf("htag :\t%d\t%d\n", parse.htag.val, parse.htag.width);

	printf("precision :\t%d\t%d\n", parse.precision.val, parse.precision.width);

	printf("space :\t%d\t%d\n", parse.space.val, parse.space.width);

	printf("type : \t%c\n", parse.type);

	printf("flag:\t%c\t%d\n", parse.flag.val, parse.flag.width);

	printf("zero :\t%d\t%d\n", parse.zero.val, parse.zero.width);

	printf("neg :\t%d\t%d\n", parse.neg.val, parse.neg.width);

	printf("parse.plus :\t%d\n", parse.plus);

	printf("width :\t%d\t%d\n", parse.width.val, parse.width.width);
}
