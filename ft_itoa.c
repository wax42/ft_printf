/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguerand <vguerand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 12:22:24 by vguerand          #+#    #+#             */
/*   Updated: 2017/12/12 12:22:53 by vguerand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned char        *ft_str_itoa(long long int len, long long int n, int neg)
{
    unsigned char *str;

    str = (unsigned char *)malloc(sizeof(char) * len);
    if (str == NULL)
        return (NULL);
    str[--len] = '\0';
    while (len--)
    {
        str[len] = n % 10 + '0';
        n = n / 10;
    }
    if (neg)
        str[0] = '-';
    return (str);
}


unsigned char            *ft_itoa_long(long long int n)
{
    long long int    i;
    long long int    l;
    int        neg;

    i = n;
    l = 2;
    neg = 0;
    if (n < 0)
    {
        n = -n;
        neg = 1;
    }
    while (i /= 10)
        l++;
    l = l + neg;
    return (ft_str_itoa(l, n, neg));
}
