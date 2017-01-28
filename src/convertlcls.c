/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convertlcls.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spalmaro <spalmaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 19:39:14 by spalmaro          #+#    #+#             */
/*   Updated: 2017/01/27 20:15:51 by spalmaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	ft_wcharpadding(t_form *form, int oct, char *char_oct)
{
	int		space;
	int		tmp;

	space = form->padding - oct;
	tmp = space;
	if (form->mzflag == '-')
	{
		ft_putstr(char_oct);
		while (tmp-- > 0)
			ft_putchar(' ');
	}
	else if (form->mzflag == '0')
	{
		while (tmp-- > 0)
			ft_putchar('0');
		ft_putstr(char_oct);
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
	char_oct[(*i)] = '\0';
}

static int	ft_bytebitbyte(wchar_t *s, t_form *form)
{
	int		len;
	int		sp;

	len = 0;
	if (form->precision == -1)
		form->precision = ft_wcslen(s) * 4;
	while (*s)
	{
		sp = bitlen(*s);
		if (sp > 16 && (len + 4 <= form->precision))
			len += 4;
		else if (sp > 11 && (len + 3 <= form->precision))
			len += 3;
		else if (sp > 7 && (len + 2 <= form->precision))
			len += 2;
		else if (sp <= 7 && (len + 1 <= form->precision))
			len++;
		else
			break ;
		s++;
	}
	return (len);
}

static int	ft_wchartpadding(t_form *form, int oct)
{
	int		space;
	int		tmp;

	space = form->padding - oct;
	tmp = space;
	if (form->mzflag == '-')
	{
		while (tmp-- > 0)
			ft_putchar(' ');
	}
	return (space);
}

int			ft_ls(va_list args, t_form *form)
{
	int			oct;
	int			len;
	int			total;
	char		char_oct[5];
	wchar_t		*str;

	if(!(str = va_arg(args, wchar_t *)))
		str = L"(null)";
	len = 0;
	oct = 0;
	total = 0;
	int k = 0;
	if (form->precision == 0)
		total += ft_wcharpadding(form, oct, char_oct);
	else
		total += ft_bytebitbyte(str, form);
	while (*str && len < form->precision)
	{
		ft_filloctet(*str, char_oct, &oct, bitlen(*str));
		if ((len += oct) > form->precision)
			break;
		if (form->padding > oct && k == 0 && form->mzflag != '-' && form->padding > form->precision)
		{
			total += ft_wcharpadding(form, total, char_oct);
			k = 1;
		}
		else
			ft_putstr(char_oct);
		oct = 0;
		str++;
	}
	if (form->padding > oct && form->mzflag == '-')
		total += ft_wchartpadding(form, total);
	return (total);
}

int			ft_lc(va_list args, t_form *form)
{
	int			len;
	int			oct;
	wchar_t		str;
	char		char_oct[5];

	oct = 0;
	str = va_arg(args, wchar_t);
	len = bitlen(str);
	ft_filloctet(str, char_oct, &oct, len);
	if (form->padding > oct)
		oct += ft_wcharpadding(form, oct, char_oct);
	else
		ft_putstr(char_oct);
	str == 0 ? write(1, "\0", 1) : 0;
	return (oct);
}
