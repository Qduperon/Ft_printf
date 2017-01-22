/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convertcs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spalmaro <spalmaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 19:39:21 by spalmaro          #+#    #+#             */
/*   Updated: 2017/01/21 21:24:38 by spalmaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
		if (!(tmp = malloc(sizeof(char *) * (form_struct->padding))))
			return (NULL);
		while (space-- > 0)
			tmp[i++] = ' ';
		tmp[i] = '\0';
		if (form_struct->mzflag != '-')
			tmp = ft_strncat(tmp, str, form_struct->precision);
		else if (form_struct->mzflag == '-')
		{
			str = ft_strndup(str, form_struct->precision);
			tmp = ft_strcat(str, tmp);
		}
		return (tmp);
	}
	else
		return (ft_strndup(str, form_struct->precision));
}

char	*ft_strpadding(char *str, t_form *form_struct)
{
	int		i;
	int		space;
	char	*tmp;

	i = 0;
	space = form_struct->padding - (int) ft_strlen(str);
	if (!(tmp = malloc(sizeof(char *) * (form_struct->padding))))
		return (NULL);
	while (space-- > 0)
		tmp[i++] = ' ';
	if (form_struct->mzflag == '-')
	{
		str = ft_strndup(str, form_struct->precision);
		tmp = ft_strcat(str, tmp);
	}
	else
		ft_strcpy(&tmp[i], str);
	return (tmp);
}

int		ft_s(va_list args, t_form *form_struct)
{
	char	*tmp;
	char	*str;
	int		len;

	if (ft_strcmp(form_struct->length_mod, "l") == 0)
		return (ft_S(args, form_struct));
	if(!(str = va_arg(args, char *)))
		str = "(null)";
	if ((form_struct->precision == -1 && form_struct->padding == 0) ||
	form_struct->precision > (int) ft_strlen(str))
	{
		ft_putstr(str);
		return (ft_strlen(str));
	}
	else if (form_struct->precision < (int) ft_strlen(str) && form_struct->precision != -1)
		tmp = ft_strprecision(str, form_struct);
	else if (form_struct->padding > (int) ft_strlen(str))
		tmp = ft_strpadding(str, form_struct);
	ft_putstr(tmp);
	len = (int) ft_strlen(tmp);
	// free(tmp);
	return (len);
}

int		ft_c(va_list args, t_form *form_struct)
{
	int				i;
	char			*tmp;
	unsigned char	str;

	i = 1;
	if (ft_strcmp(form_struct->length_mod, "l") == 0)
		return (ft_C(args, form_struct));
	str = (unsigned char)va_arg(args, wchar_t);
	if (form_struct->padding > 1)
	{
		if (form_struct->precision != 1)
			form_struct->precision = 1;
		tmp = (ft_strpadding((char *)&str, form_struct));
		ft_putstr(tmp);
		i = ft_strlen(tmp);
		free(tmp);
	}
	else
		write(1, &str, 1);
	return (i);
}

int		ft_p(va_list args, t_form *form_struct)
{
	unsigned long	i;
	int				len;
	char			*str;

	i = (unsigned long) va_arg(args, void *);
	len = 0;
	if (form_struct->precision == 0 && form_struct->padding == 0)
		str = ft_strdup("0x");
	else
	{
		str = ft_strjoin("0x", ft_lltoa_base(i, 16));
		form_struct->precision = ft_strlen(str);
	}
	if (form_struct->padding > ft_strlen(str))
		str = ft_strpadding(str, form_struct);
	ft_putstr(str);
	len = ft_strlen(str);
	free(str);
	return(len);
}