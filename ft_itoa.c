/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchalaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 10:08:47 by tchalaou          #+#    #+#             */
/*   Updated: 2023/11/14 14:38:25 by tchalaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_nbrlen(long n)
{
	int	len;

	len = 0;
	if (!n)
		len++;
	if (n < 0)
	{
		n = -n;
		len++;
	}
	while (n > 0)
	{
		len++;
		n /= 10;
	}
	return (len);
}

static void	ft_convert_int(char *p, long n)
{
	*p = 0;
	while (n > 0)
	{
		*--p = n % 10 + '0';
		n /= 10;
	}
}

char	*ft_itoa(int n)
{
	long	nb;
	int		len;
	char	*res;
	char	*p;

	nb = n;
	len = ft_nbrlen(nb);
	res = malloc(len + 1);
	if (!res)
		return (NULL);
	p = res;
	if (!nb)
	{
		*p++ = '0';
		*p = 0;
		return (res);
	}
	if (nb < 0)
	{
		*p = '-';
		nb = -nb;
	}
	p += len;
	ft_convert_int(p, nb);
	return (res);
}
