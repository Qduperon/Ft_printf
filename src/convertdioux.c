/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convertdioux.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spalmaro <spalmaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 19:38:54 by spalmaro          #+#    #+#             */
/*   Updated: 2017/01/19 16:17:57 by spalmaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*filltmp(long long nbr, char c)
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
		str = ft_lltoa_base(nbr, 8);
	return (str);
}

int		ft_convertint(long long nbr, t_form *form_struct, char c)
{
	char	*tmp;

	tmp = filltmp(nbr, c);
	ft_putchar(c);
	ft_putstr(tmp);

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
