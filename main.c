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
#define  T "hello ca%----4c %1c va %10c%-c ??", '\0', '\n', 2, 0
#define TEXT1 "%4c" // essaye avec un l

int main()
{
	printf("\t%d\n", ft_printf(T));
	printf("\t%d\n", printf(T));


	//printf("%d", a);
	//printf("%p", "2");
	return (0);
}
