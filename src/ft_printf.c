#include "../includes/ft_printf.h"

t_form	*struct_init(void)
{
	t_form	*form_struct;

	if (!(form_struct = malloc(sizeof(t_form)))
		return (NULL);
	format->conversion = '\0';
	format->mzflag = '\0';
	format->spflag = '\0';
	format->pflag = '\0';
	format->length_mod = '\0';
	format->precision = 0;
	format->padding = 0;
	return (form_struct);
}

int		arg_parse (va_list *args, char *format, int *i)
{
	int		len;
	t_form	*form_struct;

	len = 0;
	form_struct = struct_init();
	while (format[*i])
	{
		ft_flags(form_struct, format, i);
		ft_prec_pad(form_struct, args, format, i);
		ft_length_mod(form_struct, format, i);
		if ((len = ft_conversion(form_struct, args, format[*i])) != 0)
		{
			(*i)++;
			break ;
		}
	}
	free (form_struct);
	return (len);
}

int		ft_parse(const char *format, va_lst *args)
{
	int		i;
	int		len;
	char	str;

	i = 0;
	len = 0;
	str = (char *)format;
	while (str[i])
	{
		if (str[i] == '%')
			len += arg_parse(args, str, &i);
		else if (str[i] != '\0')
		{
			ft_putchar(str[i]);
			i++;
			len++;
		}
	}
	return (len);
}

int		ft_printf(const char *format, ...)
{
	va_list		lst;
	int			len;

	len = 0;
	if (format)
	{
		va_start(args, format);
		len = (ft_parse(format, &args));
		va_end(args);
	}
	return (len);
}
