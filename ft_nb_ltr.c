/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nb_ltr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguerand <vguerand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 08:34:09 by vguerand          #+#    #+#             */
/*   Updated: 2017/12/22 12:11:10 by vguerand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_nb_ltr(char *str, int mot, char separateur)
{
	int		index;
	int		nb_lettres;

	index = ft_index_mot(str, mot, separateur);
	nb_lettres = 0;
	while (str[index] != separateur && str[index])
	{
		nb_lettres++;
		index++;
	}
	return (nb_lettres);
}
