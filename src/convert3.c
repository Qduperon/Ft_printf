#include "../includes/ft_printf.h"

int		ft_S(va_list args, t_form *form_struct)
{
	int			i;
	wchar_t		*str;

	i = 0;
	str = va_arg(args, wchar_t *);
	return (0);
}

int		ft_p(va_list args, t_form *form_struct)
{
	unsigned long	i;
	int				len;
	// char		*tmp;
	char			*str;

	i = (unsigned long) va_arg(args, void *);
	len = 0;
	str = ft_strjoin("0x", ft_lltoa_base(i, 16));
	if (form_struct->padding > ft_strlen(str))
		str = ft_strpadding(str, form_struct);
	ft_putstr(str);
	len = ft_strlen(str);
	return(len);
}

int		ft_C(va_list args, t_form *form_struct)
{
	int			i;
	wchar_t		str;

	i = 0;
	str = va_arg(args, wchar_t);
	return (0);
}
