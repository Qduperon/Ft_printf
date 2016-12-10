#include "../includes/ft_printf.h"

char	*ft_parse(char *next_conv)
{
	int i;

	i = 1;
	if (next_conv[1] == '%')
	{
		//ft_putchar('%');
		return (next_conv + i);
	}
	while (next_conv[i] && (ft_digit(next_conv[i]) == 1))
	{
		if (next_conv[1] == )
	}
}

int		ft_printf(const char *format, ...)
{
	va_list		lst;
	char		*nxt_conv;

	va_start(lst, format);
	nxt_conv = ft_strchr(lst, '%');
	if (*format == '\0')
		return (0);
	if (!nxt_conv)
	{
		ft_putstr(format);
		return (ft_strlen(format));
	}
	while (nxt_conv)
	{
		if (!(next_conv = ft_parse(next_conv))
			return (-1); //idk what its supposed to send
	}
}
