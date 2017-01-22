/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convertdioux.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spalmaro <spalmaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 19:38:54 by spalmaro          #+#    #+#             */
/*   Updated: 2017/01/22 18:28:30 by spalmaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*ft_nbrpadding(char *str, t_form *form_struct)
{
	char	*tmp;
	int		extra;
	int		i;

	i = 0;
	extra = form_struct->padding - ((int)ft_strlen(str));
	if (!(tmp = malloc(sizeof(char *) * (form_struct->padding))))
		return (NULL);
	if (form_struct->mzflag == '0' && form_struct->precision == -1)
	{
		while (i < extra)
			tmp[i++] = '0';
		tmp[i] = '\0';
		tmp = ft_strcat(tmp, str);
	}
	else
	{
		while (i < extra)
			tmp[i++] = ' ';
		tmp[i] = '\0';
		form_struct->mzflag == '-' ? (tmp = ft_strcat(str, tmp)) : (tmp = ft_strcat(tmp, str));
	}
	return (tmp);
}

char	*ft_addprefix(char *str, t_form *form_struct, char c)
{
	char *tmp;
	char *nbr;

	tmp = NULL;
	if (form_struct->spflag == ' ' && (c == 'd' || c == 'D' || c == 'i')
	&& str[0] != '-')
		tmp = " ";
	else if (form_struct->spflag == '+' && (c == 'd' || c == 'D' || c == 'i')
	&& str[0] != '-')
		tmp = "+";
	if (form_struct->pflag == '#' && (ft_strcmp(str, "0") != 0))
	{
		c == 'x' ? (tmp = "0x") : 0;
		c == 'X' ? (tmp = "0X") : 0;
	}
	if (form_struct->pflag == '#' && (c == 'o' || c == 'O'))
		str[0] != '0' ? (tmp = "0") : 0;
	if (tmp != NULL)
	{
		nbr = str;
		str = ft_strjoin(tmp, str);
		free(nbr);
	}
	return (str);
}

char	*ft_nbrprecision(char *str, t_form *form_struct)
{
	char	*tmp;
	int		i;
	int		zeros;

	if (form_struct->precision > (int)ft_strlen(str))
	{
		i = 0;
		zeros = form_struct->precision - ((int)ft_strlen(str));
		if (!(tmp = malloc(sizeof(char *) * ((int)ft_strlen(str) + zeros))))
			return (NULL);
		if (str[0] == '-')
			tmp[i++] = '-';
		while (zeros-- > 0)
			tmp[i++] = '0';
		tmp[i] = '\0';
		tmp = ft_strcat(tmp, str);
		return (tmp);
	}
	return (str);
}

int		ft_convertint(long long nbr, t_form *form_struct, char c)
{
	char		*tmp;
	int			len;

	len = 0;
	c == 'D' ? (form_struct->length_mod = "l") : 0;
	c == 'O' ? (form_struct->length_mod = "l") : 0;
	c == 'U' ? (form_struct->length_mod = "l") : 0;
	tmp = ft_add_lmod(form_struct, nbr, c);
	tmp = ft_nbrprecision(tmp, form_struct);
	tmp = ft_addprefix(tmp, form_struct, c);
	if (form_struct->padding > ft_strlen(tmp))
		tmp = ft_nbrpadding(tmp, form_struct);
	ft_putstr(tmp);
	len = ft_strlen(tmp);
	// free(tmp);
	return (len);
}
