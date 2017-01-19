/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spalmaro <spalmaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 19:39:09 by spalmaro          #+#    #+#             */
/*   Updated: 2017/01/19 17:14:11 by spalmaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_convert_base(int len, int sign, int value, int base, char *str)
{
	char *alphabet;

	alphabet = "0123456789ABCDEF";
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

char		*ft_itoa_base(int value, int base)
{
	int len;
	int sign;
	char *str;

	sign = 0;
	if (base < 2 || base > 16)
		return (NULL);
	len = ft_base_size(value, base);
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
