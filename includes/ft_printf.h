/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qduperon <qduperon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 11:26:14 by qduperon          #+#    #+#             */
/*   Updated: 2016/12/18 18:22:22 by spalmaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define CONVERSION sSpdDioOuUxXcC
# define FLAGS #0-+
# define LENGTH_MOD hljz

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

typedef struct		s_form
{
	char			conversion_spec;
	char			flag;
	char			sign;
	char			*length_modif;
	int				min_len;
	int				precision;
	int				padding;
}					t_form;

#endif
