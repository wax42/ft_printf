/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguerand <vguerand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 12:28:05 by vguerand          #+#    #+#             */
/*   Updated: 2018/01/04 16:18:28 by vguerand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#define TEXT NULL
#define  T ""
#define TEXT1 "%10s" // essaye avec un l
#define ARG ,TEXT)

int main()
{
	//printf("\t%d\n", ft_printf(TEXT1, TEXT));

	printf("\t%d\n" , ft_printf("COUCOU%.0s%s%-12s", "hi", "coco", NULL));


	printf("\t%d\n" , printf("COUCOU%.0s%s%-12s", "hi", "coco", NULL));
//	printf("\t%d\n", printf(TEXT1, TEXT));

	//printf("%d", a);
	//printf("%p", "2");
	return (0);
}
