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
	if (format[*i] >= '.' && format[*i + 1] >= '0' && format[*i + 1] <= '9')
	{
		(*i)++;
		form_struct->precision = ft_atoi(&format[*i]);
		while (format[*i] >= '0' && format[*i] <= '9')
			(*i)++;
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

// void 	ft_conversion(t_form *form_struct, char *frmt, )
