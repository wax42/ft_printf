/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguerand <vguerand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 15:40:55 by vguerand          #+#    #+#             */
/*   Updated: 2017/12/12 15:41:47 by vguerand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int   ft_len(int n)
{
    int i;

    i = 1;
    while (n > 9)
     {
       n = n / 10;
      i++;

    }
    return (i);
}

char    *ft_to_octal(int n)
{
    int r;
    int tmp;
    int index;
    char *octal;

    tmp = n;
    octal = (char *)malloc(sizeof(char) * ft_len(n) + 1);
    index = ft_len(n);

    if (n == 0)
      return (octal = "0\0");
    while (n)
    {
      r = n % 8;
      index--;
      octal[index] = r + '0';
      n = n / 8;
    }
    octal[ft_len(tmp)] = '\0';
    return (octal);
}

static char    ft_hex_conv(int n)
{
    if (n == 10)
      return ('A');
    if (n == 11)
      return ('B');
    if (n == 12)
      return ('C');
    if (n == 13)
      return ('D');
    if (n == 14)
      return ('E');
    if (n == 15)
      return ('F');
    return (0);
}

char    *ft_to_hexa(int n)
{
    int r;
    int tmp;
    int index;
    char *hexa;

    tmp = n;
    hexa = (char *)malloc(sizeof(char) * ft_len(n) + 1);
    index = ft_len(n);

    if (n == 0)
      return (hexa = "0\0");
    while (n)
    {
      r = n % 16;
      index--;
      if (r >= 10)
        hexa[index] = ft_hex_conv(r);
      else
        hexa[index] = r + '0';
      n = n / 16;
    }
    hexa[ft_len(tmp)] = '\0';
    return (hexa);
}
