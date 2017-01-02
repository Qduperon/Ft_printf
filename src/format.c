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
		else if ((format[*i] == '#'))
			form_struct->pflag = '#';
		(*i)++;
	}
}

void	ft_prec_pad(t_form *form_struct, char *format, int *i)
{
	if (format[*i] >= '0' && format[*i] <= '9'))
		form_struct->padding = ft_atoi(format);
	if (format[*i] >= '.')
	{
		i++;
		form_struct->precision = ft_atoi(&format[i]);
	}
}

void	ft_length_mod(t_form *form_struct, va_list *args, char *format, int *i)
{

}
