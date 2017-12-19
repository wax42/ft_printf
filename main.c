/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguerand <vguerand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 12:28:05 by vguerand          #+#    #+#             */
/*   Updated: 2017/12/18 22:00:01 by vguerand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#define TEXT 425
#define TEXT1 "%#X bonjour %-8d"

int main()
{
	ft_printf(TEXT1, TEXT , TEXT);

	ft_putchar('\n');

	printf(TEXT1, TEXT, TEXT);

	//printf("%d", a);
	//printf("%p", "2");
	return (0);
}
