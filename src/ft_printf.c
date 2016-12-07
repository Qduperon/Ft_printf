#include "../includes/ft_printf.h"

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
}
