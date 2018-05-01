/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_conv.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkimmina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 16:32:35 by jkimmina          #+#    #+#             */
/*   Updated: 2018/04/30 20:13:32 by jkimmina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_CONV_H
# define FT_PRINTF_CONV_H

# include <stdarg.h>
# include <libft.h>
# include "ft_printf_struct.h"

char	*conv_char(va_list *ap, t_flags *flags);
char	*conv_signed(va_list *ap, t_flags *flags);
char	*conv_unsigned(va_list *ap, t_flags *flags);
char	*convert(va_list *ap, t_flags *flags);

#endif
