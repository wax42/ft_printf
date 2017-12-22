/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguerand <vguerand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 12:28:05 by vguerand          #+#    #+#             */
/*   Updated: 2017/12/20 11:25:30 by vguerand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#define TEXT 42556412454
#define  T "salut"
#define TEXT1 "bonjour %%%-8ld %s" // essaye avec un l

int main()
{
	printf("\t%d\n", ft_printf(TEXT1, TEXT, T));


	printf("\t%d\n", printf(TEXT1, TEXT, T));

	//printf("%d", a);
	//printf("%p", "2");
	return (0);
}
