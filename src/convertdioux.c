/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convertdioux.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spalmaro <spalmaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 19:38:54 by spalmaro          #+#    #+#             */
/*   Updated: 2017/01/20 19:37:15 by spalmaro         ###   ########.fr       */
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

int		ft_convertint(va_list args, t_form *form_struct, char c)
{
	char		*tmp;
	int			base;
	long long	nbr;

	nbr = va_arg(args, long long);
	tmp = filltmp(nbr, c);
	if (c == 'd' || c == 'D' || c == 'i' || c == 'u' || c == 'U')
		base = 10;
	// else if (c == 'u' || c == 'U')
	// 	str = ft_lltoa_base((unsigned long long)nbr, 10);
	else if (c == 'x')
		str = ft_lltoa_base(nbr, 16);
	else if (c == 'X')
	{
		str = ft_lltoa_base(nbr, 16);
		ft_strtoupper(str);
	}
	else if (c == 'o' || c == 'O')
		str = ft_lltoa_base(nbr, 8);
	ft_putstr(tmp);

	return (1);
}
