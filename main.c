/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguerand <vguerand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 12:28:05 by vguerand          #+#    #+#             */
/*   Updated: 2018/01/04 17:01:59 by vguerand         ###   ########.fr       */
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

	printf("%d\n" , ft_printf("%1.4s et %-6.8s et %4.2s", "tuuu", "12345", "hu"));


	printf("%d\n" , printf("%1.4s et %-6.8s et %4.2s", "tuuu", "12345", "hu"));
//	printf("\t%d\n", printf(TEXT1, TEXT));

	//printf("%d", a);
	//printf("%p", "2");
	return (0);
}
