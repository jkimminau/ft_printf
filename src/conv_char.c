/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_char.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkimmina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/30 19:28:22 by jkimmina          #+#    #+#             */
/*   Updated: 2018/05/01 18:27:36 by jkimmina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf_conv.h>
#include <stdio.h>

int		conv_wchar(va_list *ap, t_flags *flags)
{
	wchar_t	ret;
	char	*tmp;
	int	len;

	len = 1;
	ret = va_arg(*ap, wchar_t);
	if (flags->width > 1)
	{
		len = flags->width;
		tmp = (char*)malloc(flags->width);
		ft_memset(tmp, ' ', flags->width - 1);
		tmp[flags->width - 1] = '\0';
		if (flags->minus)
		{
			write(1, &ret, 1);
			ft_putstr(tmp);
		}
		else
		{
			ft_putstr(tmp);
			write(1, &ret, 1);
		}
		free(tmp);
	}
	else
	write(1, &ret, 1);
	return (len);
}

int		conv_char(va_list *ap, t_flags *flags)
{
	char	*ret;
	int	len;

	if (*flags->key == 'C')
		return (conv_wchar(ap, flags));
	len = 1;
	ret = ft_strnew(2);
	ret[0] = va_arg(*ap, int);
	if (*ret > 127)
		return (-1);
	if (ret[0] < 32 || ret[0] > 126)
		flags->strlen++;
	if (flags->width > 1)
	{
		ret = num_flag(ret, flags);
		len = flags->width;
	}
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
