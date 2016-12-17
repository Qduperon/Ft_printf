#include "../includes/ft_printf.h"

int		arg_parse (va_list *args, const char **format)

int		ft_parse(const char *format, va_lst *args)
{
	int i;
	int len;

	i = 0;
	len = 0;
	while (*format)
	{
		if (*format == '%')
			len += arg_parse(args, &format);
		else if (*format != '\0')
		{
			ft_putchar(*format);
			format++;
			len++;
		}
	}
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
