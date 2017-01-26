/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convertp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spalmaro <spalmaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 17:13:48 by spalmaro          #+#    #+#             */
/*   Updated: 2017/01/24 17:13:59 by spalmaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

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
	if (form_struct->padding > (int)ft_strlen(tmp))
	{
		form_struct->precision = (int)ft_strlen(tmp);
		tmp = ft_strpadding(tmp, form_struct, 0);
	}
	ft_putstr(tmp);
	len = ft_strlen(tmp);
	//free(tmp);
	return (len);
}
