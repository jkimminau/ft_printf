/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_special.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkimmina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/01 16:00:35 by jkimmina          #+#    #+#             */
/*   Updated: 2018/05/01 18:19:04 by jkimmina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>
#include <ft_printf_flags.h>

int		conv_perc(t_flags *flags)
{
	char	*res;
	int		len;

	res = ft_strdup("%");
	if (res)
		res = num_flag(res, flags);
	len = ft_strlen(res);
	write(1, res, len);
	free(res);
	return (len);
}

int		conv_ptr(va_list *ap, t_flags *flags)
{
	char		*res;
	int			len;
	uintmax_t	num;

	num = conv_unsigned(ap, flags);
	res = ft_uitoa_base(num, 16);
	res = ft_strjoin("0x", res);
	if (flags->width > 0)
		res = num_flag(res, flags);
	len = ft_strlen(res);
	write(1, res, len);
	free(res);
	return (len);
}
