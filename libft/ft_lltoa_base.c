/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lltoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spalmaro <spalmaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 18:47:14 by spalmaro          #+#    #+#             */
/*   Updated: 2017/01/17 18:50:13 by spalmaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_intlen(long long nbr, int base)
{
	int		len;
	int		sign;

	sign = 0;
	len = 1;
	if (nbr < 0)
	{
		nbr = nbr * -1;
		if (base == 10)
			sign = 1;
	}
	while (nbr >= base)
	{
		len++;
		nbr = nbr / base;
	}
	return (len + sign);
}


static char	*ft_convert_base(int len, int sign, long long value, int base, char *str)
{
	char	*alphabet;

	alphabet = "0123456789abcdef";
	while (len + sign >= 0)
	{
		if (sign == 1)
		{
			str[0] = '-';
		}
		str[--len] = alphabet[(value % base)];
		value /= base;
	}
	return (str);
}

char		*ft_lltoa_base(long long value, int base)
{
	int		len;
	int		sign;
	char	*str;

	sign = 0;
	if (base < 2 || base > 16)
		return (NULL);
	len = ft_intlen(value, base);
	if (value == -2147483648)
		return  ("-2147483648");
	if (value < 0)
	{
		value *= -1;
		if (base == 10)
			sign = 1;
	}
	if (!(str = (char *)malloc(sizeof(char) * (len + sign +  1))))
		return (NULL);
	str[len] = '\0';
	return (ft_convert_base(len, sign, value, base, str));
}
