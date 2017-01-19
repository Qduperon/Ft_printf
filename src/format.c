/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spalmaro <spalmaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 19:39:29 by spalmaro          #+#    #+#             */
/*   Updated: 2017/01/19 17:56:00 by spalmaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <stdio.h>

void	ft_flags(t_form *form_struct, char *format, int *i)
{
	while (format[*i] && (isflag(format[*i]) == 1))
	{
		if (format[*i] == '+')
			form_struct->spflag = '+';
		else if (format[*i] == ' ' && (form_struct->spflag != '+'))
			form_struct->spflag = ' ';
		else if (format[*i] == '-')
			form_struct->mzflag = '-';
		else if (format[*i] == '0' && (form_struct->mzflag != '-'))
			form_struct->mzflag = '0';
		else if (format[*i] == '#')
			form_struct->pflag = '#';
		(*i)++;
	}
	printf("spflag :%c\n", form_struct->spflag);
	printf("mzflag :%c\n", form_struct->mzflag);
	printf("pflag :%c\n", form_struct->pflag);
}

void	ft_prec_pad(t_form *form_struct, char *format, int *i)
{
	if (format[*i] >= '0' && format[*i] <= '9')
		form_struct->padding = ft_atoi(&format[*i]);
	while (format[*i] >= '0' && format[*i] <= '9')
		(*i)++;
	if (format[*i] == '.' && format[*i + 1] >= '0' && format[*i + 1] <= '9')
	{
		(*i)++;
		form_struct->precision = ft_atoi(&format[*i]);
		while (format[*i] >= '0' && format[*i] <= '9')
			(*i)++;
	}
	else if (format[*i] == '.')
	{
		(*i)++;
		form_struct->precision = 0;
	}
	printf("precision: %d\n", form_struct->precision);
	printf("padding: %d\n", form_struct->padding);
}

void	ft_length_mod(t_form *form_struct, char *frmt, int *i)
{
	while (frmt[*i] && (islmodifier(&frmt[*i]) > 0))
	{
		if ((islmodifier(&frmt[*i]) == 1) &&
		(islmodifier(form_struct->length_mod) <= 1))
		{
			form_struct->length_mod = "hh";
			(*i)++;
		}
		else if ((islmodifier(&frmt[*i]) == 2) &&
		(islmodifier(form_struct->length_mod) <= 2))
			form_struct->length_mod = "h";
		else if (frmt[*i] == 'j' && islmodifier(form_struct->length_mod) <= 3)
			form_struct->length_mod = "j";
		else if (frmt[*i] == 'l' && frmt[*i + 1] == 'l')
		{
			form_struct->length_mod = "ll";
			(*i)++;
		}
		else if (frmt[*i] == 'l' && islmodifier(form_struct->length_mod) <= 3)
			form_struct->length_mod = "l";
		else if (frmt[*i] == 'z' && islmodifier(form_struct->length_mod) <= 3)
			form_struct->length_mod = "z";
		(*i)++;
	}
	printf("length mod: %s\n", form_struct->length_mod);
}

int 	ft_conversion(t_form *form_struct, va_list args, char *c, int i)
{
	int		(*convert[5])(va_list, t_form*);
	char	*conversion;

	conversion = "sSpcCdDioOuUxX";
	convert[0] = &ft_s;
	convert[1] = &ft_S;
	convert[2] = &ft_p;
	convert[3] = &ft_c;
	convert[4] = &ft_C;
	while (conversion[i])
	{
		if (conversion[i] == c[0] && (i >= 5))
			return (ft_convertint(args, form_struct, c[0]));
		else if (conversion[i] == c[0])
			return (convert[i])(args, form_struct);
		i++;
	}
	if (c[0] == '%' || ft_isprint(c[0]))
		return (writeperct(c));
	return (0);
}
