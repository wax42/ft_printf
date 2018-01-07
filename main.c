/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguerand <vguerand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 12:28:05 by vguerand          #+#    #+#             */
/*   Updated: 2018/01/04 18:18:15 by vguerand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#define TEXT 'U'
#define  T "%20.ld et %.4hhi !", 0x11ffaa147, (signed char)-8
#define TEXT1 "%ld", 0xff11ff11ff88

int main()
{
	void *ptr;
	ptr = "eed";
	printf("\t%d\n", ft_printf(T));
	printf("\t%d\n", printf(T));
	return (0);
}
