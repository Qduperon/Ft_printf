/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qduperon <qduperon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 11:26:14 by qduperon          #+#    #+#             */
/*   Updated: 2017/01/10 17:20:26 by spalmaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define CONVERSION sSpcCdDioOuUxX
# include "../libft/includes/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

typedef struct		s_form
{
	char			conversion;
	char			mzflag;
	char			spflag;
	char			pflag;
	char			*length_mod;
	int				precision;
	int				padding;
}					t_form;

int		ft_printf(const char *format, ...);
int		ft_parse(const char *format, va_list *args);
int		arg_parse (va_list *args, char *format, int *i);
t_form	*struct_init(void);
void	ft_length_mod(t_form *form_struct, char *frmt, int *i);
void	ft_prec_pad(t_form *form_struct, char *format, int *i);
void	ft_flags(t_form *form_struct, char *format, int *i);
int		isflag(char c);
int		islmodifier(char *c);

#endif
