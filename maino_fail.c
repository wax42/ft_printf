/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguerand <vguerand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 12:28:05 by vguerand          #+#    #+#             */
/*   Updated: 2017/12/20 11:13:43 by vguerand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#define TEXT 42556412454
#define TEXT1 "bonjour %%%-8ld %o" // essaye avec un l

int main()
{
	ft_printf(TEXT1, TEXT, (unsigned)TEXT);

	ft_putchar('\n');

	printf(TEXT1, TEXT, (unsigned)TEXT);

	//printf("%d", a);
	//printf("%p", "2");
	return (0);
}
