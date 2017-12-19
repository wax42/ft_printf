/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.base_max.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguerand <vguerand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 16:44:22 by vguerand          #+#    #+#             */
/*   Updated: 2017/12/18 13:44:41 by vguerand         ###   ########.fr       */
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



char         *ft_strrev(char *str)
{
    char *tmp;
    int i;
    int k;

    i = ft_strlen(str);
    k = 0;
    tmp = (char *)malloc(sizeof(char) * i + 1);
    while(i--)
    {
        tmp[k] = str[i];
        k++;
    }
    tmp[k] = '\0';
    ft_strdel(&str);
    return (tmp);
}

int   ft_nbrlen_max(unsigned long long n, unsigned long long base)
{
    int i;

    i = 1;
    while (n > base - 1)
     {
       n = n / base;
       i++;
    }
    return (i);
}

char    *ft_itoa_base_max(unsigned long long  n, int ba, int uppercase)
{
    char    *str;
    int        i;
    int        length;
    unsigned long long base;

    base = (unsigned long long)ba;
    if (base < 2 || base > 16)
        return (NULL);
    if (base == 10)
        return ((char *)ft_itoa_long(n));
    length = 0;
    length = ft_nbrlen_max(n, base);
    str = (char*)malloc(sizeof(*str) * (length + 1));
    i = 0;
    while (i < length)
    {
        if (base > 10 && (n % base >= 10) && uppercase)
            str[i++] = (n % base) - 10 + 'A';
        else if (base > 10 && (n % base >= 10))
            str[i++] = (n % base) - 10 + 'a';
        else
            str[i++] = (n % base) + '0';
        n /= base;
    }
    str[i] = '\0';
    return (ft_strrev(str));
}
