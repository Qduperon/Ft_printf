/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convertdioux.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spalmaro <spalmaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 19:38:54 by spalmaro          #+#    #+#             */
/*   Updated: 2017/01/21 21:47:10 by spalmaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*ft_nbrpadding(char *str, t_form *form_struct)
{
	char	*tmp;
	int		extra;
	int		i;

	i = 0;
	extra = form_struct->padding - (ft_strlen(str));
	if (!(tmp = malloc(sizeof(char *) * (form_struct->padding))))
		return (NULL);
	if (form_struct->mzflag == '0' && form_struct->precision == -1)
	{
		while (i < extra)
			tmp[i++] = '0';
		tmp[i] = '\0';
		tmp = ft_strcpy(&tmp[i], str);
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

	if (form_struct->precision > ft_strlen(str))
	{
		i = 0;
		zeros = form_struct->precision - (ft_strlen(str));
		if (!(tmp = malloc(sizeof(char *) * (ft_strlen(str) + zeros))))
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

char	*filltmp(long long nbr, char c)
{
	char *str;

	str = NULL;
	if (c == 'd' || c == 'D' || c == 'i')
		str = ft_lltoa_base(nbr, 10);
	else if (c == 'u' || c == 'U')
		str = ft_lltoa_base((unsigned long long)nbr, 10);
	else if (c == 'x')
		str = ft_lltoa_base(nbr, 16);
	else if (c == 'X')
	{
		str = ft_lltoa_base(nbr, 16);
		ft_strtoupper(str);
	}
	else if (c == 'o' || c == 'O')
		str = ft_lltoa_base(nbr, 8);
	return (str);
}

int		ft_convertint(va_list args, t_form *form_struct, char c)
{
	char		*tmp;
	int			len;
	long long	nbr;

	nbr = va_arg(args, long long);
	len = 0;
	tmp = filltmp(nbr, c);
	tmp = ft_nbrprecision(tmp, form_struct);
	tmp = ft_addprefix(tmp, form_struct, c);
	if (form_struct->padding > ft_strlen(tmp))
		tmp = ft_nbrpadding(tmp, form_struct);
	ft_putstr(tmp);
	len = ft_strlen(tmp);
	free(tmp);
	return (len);
}
