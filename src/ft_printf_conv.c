/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_conv.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkimmina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 16:18:20 by jkimmina          #+#    #+#             */
/*   Updated: 2018/04/30 19:30:01 by jkimmina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf_conv.h>

char	*convert(va_list *ap, t_flags *flags)
{
	char	c;
	char	*r;

	c = *flags->key;
	if (c == '%')
		return (ft_strdup("%"));
	else if (ft_strchr("diD", c))
		return (conv_signed(ap, flags));
	else if (ft_strchr("uUxXoOp", c))
		return (conv_unsigned(ap, flags));
	else if (ft_strchr("cC", c))
		return (conv_char(ap, flags));
	else if (ft_strchr("sS", c))
		return ((r = va_arg(*ap, char*)) ? ft_strdup(r) : ft_strdup("(null)"));
	return (0);
}
