/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_char.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkimmina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/30 19:28:22 by jkimmina          #+#    #+#             */
/*   Updated: 2018/04/30 20:41:23 by jkimmina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf_conv.h>

char	*conv_char(va_list *ap, t_flags *flags)
{
	char	*ret;

	ret = ft_strnew(2);
	ret[0] = va_arg(*ap, int);
	ret[1] = '\0';
	if (ret[0] < 32 || ret[0] > 126)
		flags->strlen++;
	return (ret);
}
