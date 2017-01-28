/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spalmaro <spalmaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 19:39:09 by spalmaro          #+#    #+#             */
/*   Updated: 2017/01/28 20:29:18 by spalmaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_convert_base(int sign, int len, int value, int base)
{
	char	*alphabet;
	char	*str;

	alphabet = "0123456789ABCDEF";
	if (!(str = (char *)malloc(sizeof(char) * (len + sign + 1))))
		return (NULL);
	str[len] = '\0';
	while (len + sign > 0)
	{
		if (sign == 1)
			str[0] = '-';
		if (--len < 0)
			break ;
		str[len] = alphabet[(value % base)];
		value /= base;
	}
			ft_putnbr(len + sign);
	return (str);
}

char			*ft_itoa_base(int value, int base)
{
	int		sign;
	int		len;

	sign = 0;
	if (base < 2 || base > 16)
		return (NULL);
	if (value == -2147483648)
		return ("-2147483648");
	len = ft_base_size(value, base);
	if (value < 0)
	{
		value *= -1;
		if (base == 10)
			sign = 1;
	}
	return (ft_convert_base(sign, len, value, base));
}
