/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qduperon <qduperon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 11:26:14 by qduperon          #+#    #+#             */
/*   Updated: 2016/12/08 16:49:55 by spalmaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define CONVERSION sSpdDioOuUxXcC
# define FLAGS #0-+
# define LENGTHMOD hljz

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

#endif
