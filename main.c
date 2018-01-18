/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguerand <vguerand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 12:28:05 by vguerand          #+#    #+#             */
/*   Updated: 2018/01/12 18:15:20 by vguerand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <locale.h>
#include <limits.h>
#define TE "%#1.2o %0012.O", (unsigned char)12, 0, 123654789
#define TA "%.4u", 424242
#define  T "{%S}", L"ÊM-M-^QÊM-^XØ‰∏M-ÂM-^O™ÁM-^L´„M-M-^B"
#define TEXT1 "%ld", 0xff11ff11ff88

int main()
{
	setlocale(LC_ALL, ""); // #malinlelyn
	int *ptr;
	int a = 8;
	ptr = &a;
	wchar_t	s[4];
	s[0] = 0x53;
	s[1] = 0xd800;
	s[2] = 0x81000;
	s[3] = '\0';
	printf("\t%d\n\n", ft_printf(TA));
	printf("\t%d\n", printf(TA));
	return (0);
}

/*
ok

precision.width 2
width.width 1



precision.width 0
width.width 2
*/
