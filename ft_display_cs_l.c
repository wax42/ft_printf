/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_cs_l.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguerand <vguerand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 14:19:18 by vguerand          #+#    #+#             */
/*   Updated: 2017/12/18 15:56:28 by vguerand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



int ft_display_cs(const char *restrict format, va_list *ap, p_f parse)
{
	int nbr;
	char *str;

	nbr = 0;
	while((parse.type = ft_cchr("l", format[parse.i++])))
		nbr++;
	if (nbr == 0)
		str = va_arg(*ap, char *);
	if (nbr >= 1)
		str = va_arg(*ap, wchar_t *);
	parse.val_ret = aff_struct(str, ap, parse);
	return (parse.val_ret);
}
