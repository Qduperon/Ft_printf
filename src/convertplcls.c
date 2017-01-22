/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convertplcls.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spalmaro <spalmaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 19:39:14 by spalmaro          #+#    #+#             */
/*   Updated: 2017/01/22 18:58:50 by spalmaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		bytelen(wchar_t c)
{
	int		i;

	i = 0;
	while (c >> 1)
		i++;
	return (i);
}

int		ft_ls(va_list args, t_form *form_struct)
{
	int			i;
	wchar_t		*str;

	i = 0;
	str = va_arg(args, wchar_t *);
	return (0);
}

int		ft_lc(va_list args, t_form *form_struct)
{
	int			i;
	wchar_t		str;

	i = 0;
	str = va_arg(args, wchar_t);
	return (0);
}

int		writeperct(char *c, t_form *form_struct)
{
	int		len;
	int		i;
	char	*tmp;

	len = 1;
	i = 0;
	tmp = ft_strdup("%");
	while (c[i] && c[i] != '%')
	{
		tmp = ft_strcat(tmp, &c[i]);
		len++;
	}
	if (form_struct->padding > ft_strlen(tmp))
	{
		form_struct->precision = ft_strlen(tmp);
		tmp = ft_strpadding(tmp, form_struct);
	}
	ft_putstr(tmp);
	len = ft_strlen(tmp);
	free(tmp);
	return (len);
}
