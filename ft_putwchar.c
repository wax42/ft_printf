/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguerand <vguerand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 16:32:59 by vguerand          #+#    #+#             */
/*   Updated: 2018/01/18 21:27:09 by mbarthe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#define WCHAR_MASK_1 "0xxxxxxx"
#define WCHAR_MASK_2 "110xxxxx 10xxxxxx"
#define WCHAR_MASK_3 "1110xxxx 10xxxxxx 10xxxxxx"
#define WCHAR_MASK_4 "11110xxx 10xxxxxx 10xxxxxx 10xxxxxx"

int		ft_strlentab(char **str)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (str[j][i] != '\0')
	{
		i = 0;
		while (str[j][i] != '\0')
			i++;
		j++;
	}
	return (j);
}

void	ft_strdel_tab(char **tab, size_t tab_len)
{
	size_t i;

	i = 0;
	while (i <= tab_len)
	{
		free(tab[i]);
		i++;
	}
	ft_strdel(&tab[i]);
	free(tab);
	tab = NULL;
}

char	**apply_mask(char *bin, char *m)
{
	int		length_bin;
	int		length_mask;
	char	*mask;
	char	**tmp;
	size_t	i;

	mask = ft_strdup(m);
	length_bin = ft_strlen(bin) - 1;
	length_mask = ft_strlen(mask) - 1;
	while (length_mask >= 0 && length_bin >= 0)
	{
		if (mask[length_mask] == 'x')
		{
			mask[length_mask] = bin[length_bin];
			length_bin--;
		}
		length_mask--;
	}
	i = -1;
	while (++i < ft_strlen(mask))
		(mask[i] == 'x') ? mask[i] = '0' : mask[i];
	tmp = ft_strsplit(mask, ' ');
	ft_strdel(&mask);
	return (tmp);
}

void	ft_putwchar(wchar_t c)
{
	int		character;
	char	*bin;
	char	**mask;
	int		to_print;
	int		i;

	character = (int)c;
	bin = ft_itoa_base(character, 2, 0);
	if (ft_strlen(bin) <= 7)
		mask = apply_mask(bin, WCHAR_MASK_1);
	else if (ft_strlen(bin) <= 11)
		mask = apply_mask(bin, WCHAR_MASK_2);
	else if (ft_strlen(bin) <= 16)
		mask = apply_mask(bin, WCHAR_MASK_3);
	else
		mask = apply_mask(bin, WCHAR_MASK_4);
	ft_memdel((void **)&bin);
	i = 0;
	while (mask[i])
	{
		to_print = ft_atoi_base(mask[i], 2);
		write(1, &to_print, 1);
		i++;
	}
	ft_strdel_tab(mask, ft_strlentab(mask));
}
