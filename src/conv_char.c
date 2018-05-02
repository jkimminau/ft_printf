/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_char.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkimmina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/30 19:28:22 by jkimmina          #+#    #+#             */
/*   Updated: 2018/05/01 17:12:40 by jkimmina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf_conv.h>

int		conv_char(va_list *ap, t_flags *flags)
{
	char	*ret;
	int		len;

	len = 0;
	ret = ft_strnew(2);
	ret[0] = va_arg(*ap, int);
	if (ret[0] < 32 || ret[0] > 126)
		flags->strlen++;
	if (flags->width > 0)
		ret = num_flag(ret, flags);
	len = flags->strlen + ft_strlen(ret);
	write(1, ret, len);
	free(ret);
	return (len);
}

int		conv_str(va_list *ap, t_flags *flags)
{
	char	*ret;
	char	*tmp;
	int		len;

	tmp = va_arg(*ap, char*);
	if (tmp == 0)
		ret = ft_strdup("(null)");
	else
	{
		ret = ft_strdup(tmp);
		if (flags->prec > -1)
			ret = prec_flag(ret, flags);
		if (flags->width)
			ret = num_flag(ret, flags);
	}
	len = ft_strlen(ret);
	write(1, ret, len);
	free(ret);
	return (len);
}
