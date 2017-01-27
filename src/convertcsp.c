/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convertcsp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spalmaro <spalmaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 19:39:21 by spalmaro          #+#    #+#             */
/*   Updated: 2017/01/27 16:28:33 by spalmaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*ft_strprecision(char *str, t_form *form)
{
	int		space;
	int		i;
	char	*tmp;

	i = 0;
	if (form->padding > form->precision)
	{
		space = form->padding - form->precision;
		if (!(tmp = malloc(sizeof(char *) * (form->padding))))
			return (NULL);
		while (space-- > 0)
			tmp[i++] = ' ';
		tmp[i] = '\0';
		if (form->mzflag != '-')
			tmp = ft_strncat(tmp, str, form->precision);
		else if (form->mzflag == '-')
		{
			str = ft_strndup(str, form->precision);
			tmp = ft_strcat(str, tmp);
		}
		return (tmp);
	}
	else
		return (ft_strndup(str, form->precision));
}

char	*ft_strpadding(char *str, t_form *form, int f)
{
	int		i;
	int		space;
	char	*tmp;

	i = 0;
	space = form->padding - (int)ft_strlen(str);
	(f == 1) ? (space--) : 0;
	if (!(tmp = malloc(sizeof(char *) * (form->padding))))
		return (NULL);
	while (space-- > 0)
		tmp[i++] = ' ';
	if (form->mzflag == '-')
	{
		str = ft_strndup(str, form->precision);
		tmp = ft_strcat(str, tmp);
	}
	else
		ft_strcpy(&tmp[i], str);
	return (tmp);
}

int		ft_s(va_list args, t_form *form)
{
	char	*tmp;
	char	*str;
	int		len;

	if (ft_strcmp(form->length_mod, "l") == 0)
		return (ft_ls(args, form));
	if (!(str = va_arg(args, char *)))
		str = "(null)";
	if (ft_strcmp(str, "") == 0)
		tmp = ft_strpadding(str, form, 0);
	else if ((form->precision == -1 && form->padding == 0) || (form->precision
		> (int)ft_strlen(str) && form->padding < (int)ft_strlen(str)))
	{
		ft_putstr(str);
		return (ft_strlen(str));
	}
	else if (form->precision < (int)ft_strlen(str) &&
	form->precision != -1)
		tmp = ft_strprecision(str, form);
	else if (form->padding > (int)ft_strlen(str))
		tmp = ft_strpadding(str, form, 0);
	ft_putstr(tmp);
	len = (int)ft_strlen(tmp);
	return (len);
}

int		ft_c(va_list args, t_form *form)
{
	int				i;
	char			*tmp;
	unsigned char	str;

	i = 1;
	if (ft_strcmp(form->length_mod, "l") == 0)
		return (ft_lc(args, form));
	str = (unsigned char)va_arg(args, wchar_t);
	if (form->padding > 1)
	{
		if (form->precision != 1)
			form->precision = 1;
		str == 0 ? tmp = (ft_strpadding((char *)&str, form, 1)) :
		(tmp = (ft_strpadding((char *)&str, form, 0)));
		ft_putstr(tmp);
		i = ft_strlen(tmp);
		(str == 0) ? (i++) : 0;
		//free(tmp);
	}
	else
		write(1, &str, 1);
	str == 0 ? write(1, "\0", 1) : 0;
	return (i);
}

int		ft_p(va_list args, t_form *form)
{
	unsigned long	i;
	int				len;
	char			*str;

	i = (unsigned long)va_arg(args, void *);
	if (form->precision == 0 && form->padding == 0)
		str = ft_strdup("0x");
	else
	{
		str = ft_strjoin("0x", ft_lltoa_base(i, 16));
		form->precision = ft_strlen(str);
	}
	if (form->padding > (int)ft_strlen(str))
		str = ft_strpadding(str, form, 0);
	ft_putstr(str);
	len = (int)ft_strlen(str);
	return (len);
}
