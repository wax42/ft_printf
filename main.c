/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguerand <vguerand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 12:28:05 by vguerand          #+#    #+#             */
/*   Updated: 2017/12/22 15:42:27 by vguerand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#define TEXT 425
#define  T "salut"
#define TEXT1 "%.%" // essaye avec un l
#define ARG ,TEXT)

int main()
{
	printf("\t%d\n", ft_printf(TEXT1));

	printf("\t%d\n", printf(TEXT1));

	//printf("%d", a);
	//printf("%p", "2");
	return (0);
}
