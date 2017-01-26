/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convertlcls.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spalmaro <spalmaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 19:39:14 by spalmaro          #+#    #+#             */
/*   Updated: 2017/01/26 14:50:37 by spalmaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	ft_wcharpadding(t_form *form_struct, int oct, char *char_oct)
{
	int		space;
	int		tmp;

	space = form_struct->padding - oct;
	tmp = space;
	if (form_struct->mzflag == '-')
	{
		ft_putstr(char_oct);
		while (tmp-- > 0)
			ft_putchar(' ');
	}
	else
	{
		while (tmp-- > 0)
			ft_putchar(' ');
		ft_putstr(char_oct);
	}
	return (space);
}

static void	ft_filloctet(wchar_t c, char *char_oct, int *i, int len)
{
	if (len > 7)
	{
		if (len > 11)
		{
			if (len > 16)
			{
				char_oct[(*i)++] = ((c >> 18) & 0b00000111) | 0b11110000;
				char_oct[(*i)++] = ((c >> 12) & 0b00111111) | 0b10000000;
			}
			else
				char_oct[(*i)++] = ((c >> 12) & 0b00001111) | 0b11100000;
			char_oct[(*i)++] = ((c >> 6) & 0b00111111) | 0b10000000;
		}
		else
			char_oct[(*i)++] = ((c >> 6) & 0b00011111) | 0b11000000;
		char_oct[(*i)++] = (c & 0b00111111) | 0b10000000;
	}
	else
		char_oct[(*i)++] = (char)c;
}

int			ft_ls(va_list args, t_form *form_struct)
{
	int			oct;
	int			len;
	int			total;
	char		char_oct[5];
	wchar_t		*str;

	str = va_arg(args, wchar_t *);
	if (form_struct->precision == -1)
		form_struct->precision = ft_wcslen(str) * 4;
	len = 0;
	total = 0;
	while (*str && len < form_struct->precision)
	{
		ft_filloctet(*str, char_oct, &oct, bitlen(*str));
		if (form_struct->padding > oct)
			total += ft_wcharpadding(form_struct, oct, char_oct);
		else
			ft_putstr(char_oct);
		len += oct;
		total += oct;
		oct = 0;
		str++;
	}
	return (total);
}

int			ft_lc(va_list args, t_form *form_struct)
{
	int			len;
	int			oct;
	wchar_t		str;
	char		char_oct[5];

	oct = 0;
	str = va_arg(args, wchar_t);
	len = bitlen(str);
	ft_filloctet(str, char_oct, &oct, len);
	if (form_struct->padding > oct)
		oct += ft_wcharpadding(form_struct, oct, char_oct);
	else
		ft_putstr(char_oct);
	return (oct);
}
