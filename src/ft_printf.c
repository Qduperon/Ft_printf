#include "../includes/ft_printf.h"

int		ft_parse(char *next_conv)
{
	int i;

	i = 1;
	if (next_conv[i] == '%')
		ft_putchar('%');
	while (next_conv[i])
	{
		
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
	if (!(ft_parse(next_conv))
		return (-1); //idk what its supposed to send

}
