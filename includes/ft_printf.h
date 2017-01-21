/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qduperon <qduperon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 11:26:14 by qduperon          #+#    #+#             */
/*   Updated: 2017/01/21 18:05:06 by spalmaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define CONVERSION sSpcCdDioOuUxX
# include "../libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

typedef struct		s_form
{
	char			mzflag;
	char			spflag;
	char			pflag;
	char			*length_mod;
	int				precision;
	int				padding;
}					t_form;

t_form	*struct_init(void);
int		ft_printf(const char *format, ...);
int		ft_parse(const char *format, va_list args);
int		arg_parse (va_list args, char *format, int *i);
void	ft_length_mod(t_form *form_struct, char *frmt, int *i);
void	ft_prec_pad(t_form *form_struct, char *format, int *i);
void	ft_flags(t_form *form_struct, char *format, int *i);
char	*ft_strpadding(char *str, t_form *form_struct);
int 	ft_conversion(t_form *form_struct, va_list args, char *c, int i);
int		ft_S(va_list args, t_form *form_struct);
int		ft_s(va_list args, t_form *form_struct);
int		ft_C(va_list args, t_form *form_struct);
int		ft_c(va_list args, t_form *form_struct);
int		ft_p(va_list args, t_form *form_struct);
int		ft_convertint(va_list args, t_form *form_struct, char c);
int		isflag(char c);
int		islmodifier(char *c);
int		writeperct(char *c, t_form *form_struct);
int		ft_add_lmod(t_form *form_struct, va_list args);

#endif
