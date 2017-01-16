#include "../includes/ft_printf.h"

char	*ft_strprecision(char *str, t_form *form_struct)
{
	int		space;
	int		i;
	char	*tmp;

	i = 0;
	if (form_struct->padding > form_struct->precision)
	{
		space = form_struct->padding - form_struct->precision;
		if (!(tmp = malloc(sizeof(char *) * (form_struct->padding + 1))))
			return (NULL);
		while (space-- > 0)
			tmp[i++] = ' ';
		tmp = ft_strncpy(&tmp[i], src, form_struct->precision);
		return (tmp);
	}
	else
		return (ft_strndup(str, form_struct->padding));
}

char	*ft_strpadding(char *str, t_form *form_struct)
{
	int		i;
	int		space;

	i = 0;
	space = form_struct->padding - (int) ft_strlen(str);
	if (!(tmp = malloc(sizeof(char *) * (form_struct->padding + 1))))
		return (NULL);
	while (space-- > 0)
		tmp[i++] = ' ';
	ft_strcpy(&tmp[i], str);
	return (tmp));
}

int		ft_s(va_list args, t_form *form_struct)
{
	char	*tmp;
	char	*str;
	int		len;

	if (ft_strcmp(form_struct->length_mod, "l") == 0)
		return (ft_S(args, form_struct, final));
	if (!(str = va_arg(args, char *)))
		tmp = "(null)"; //check if this works
	else
		tmp = str;
	if (form_struct->precision < (int) ft_strlen(str))
		tmp = ft_strprecision(str, form_struct);
	else if (form_struct->padding > (int) ft_strlen(str))
		tmp = ft_strpadding(str, form_struct);
	ft_putstr(tmp);
	len = (int) ft_strlen(tmp);
	free (tmp);
	return (len);
}

int		ft_c(va_list args, t_form form_struct)
{
	int		i;
	char	*tmp
	char	str;

	i = 1;
	if (ft_strcmp(form_struct->length_mod, "l") == 0)
		return (ft_C(args, form_struct);
	str = (char) va_arg(args, unsigned char);
	if (form_struct->padding > 1)
	{
		if (form_struct->precision != NULL)
			form_struct->precision = 0;
		tmp = (ft_strpadding(&str, form_struct)) //check if gives two chars instead of one
		ft_putstr(tmp);
		i = ft_strlen(tmp);
		free(tmp);
	}
	else
		ft_putchar((char) str);
	return (i);
}
