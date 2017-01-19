/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convertdioux.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spalmaro <spalmaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 19:38:54 by spalmaro          #+#    #+#             */
/*   Updated: 2017/01/18 14:26:19 by spalmaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_lmodifer()
{
	char *str;

	str = NULL;
	if (c == 'd' || c == 'D' || c == 'i')
		str = ft_lltoa_base(nbr, 10);
	else if (c == 'u' || c == 'U')
		str = ft_lltoa_base((unsigned long long)nbr, 10);
	else if (c == 'x')
		str = ft_lltoa_base(nbr, 16);
	else if (c == 'X')
	{
		str = ft_lltoa_base(nbr, 16);
		ft_strtoupper(str);
	}
	else if (c == 'o' || c == 'O')
		str = ft_lltoao(nbr);
	return (str;)
}

int		ft_convertint(long long nb, t_form *form_struct, char c)
{

	return (0);
}

int		writeperct(char *c)
{
	// int	len;
	//
	// len = 0;
	// if (*c == '%')
	// 	ft_putchar('%');
	// while (*c != '')
	return (0);
}
