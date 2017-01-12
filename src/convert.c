#include "../includes/ft_printf.h"

int		ft_s(va_list args, t_form *form_struct, char **final)
{
	int			i;
	char		*tmp;
	char		*str;

	if (ft_strcmp(form_struct->length_mod, "l") == 0)
		return (ft_S(args, form_struct, final));
	if (!(str = va_arg(args, char *)))
		return (NULL);
	if (form_struct->precision < ft_strlen(str))
	{
		if (form_struct->padding > form_struct->precision)
		{
			i = form_struct->padding - form_struct->precision;
			if (!(tmp = malloc(sizeof(char *) * (form_struct->padding + 1))))
				return (NULL);
			while (tmp[i++])
				tmp[i] = ' ';
			tmp = ft_strncpy(&tmp[i], src, form_struct->precision);
		}
		else
		
	}
	// if (form_struct->precision != NULL && (form_struct->precision < ft_strlen(str))
	// {
	// 	tmp = ft_strncpy(tmp, str, form_struct->precision);
	// }
	// if (form_struct->padding != NULL && form_struct->padding > ft_strlen(tmp))
	// {
	// 	i = form_struct->padding - ((int)ft_strlen(tmp));
	//
	// }

}

int		ft_S(va_list args, t_form form_struct, char **final)
{
	int			i;
	wchar_t		*str;

	i = 0;
	str = va_arg(args, wchar_t *);
}

int		ft_p(va_list args, t_form form_struct, char **final)
{
	int					i;
	unsigned long		str;

	i = 0;
	str = va_arg(args, void *);
}

int		ft_c(va_list args, t_form form_struct, char **final)
{
	int			i;
	wchar_t		str;

	i = 0;
	str = va_arg(args, wchar_t);
}

int		ft_C(va_list args, t_form form_struct, char **final)
{
	int			i;
	wchar_t		str;

	i = 0;
	str = va_arg(args, wchar_t);
}
