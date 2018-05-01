/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_conv.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkimmina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 16:18:20 by jkimmina          #+#    #+#             */
/*   Updated: 2018/04/30 17:42:35 by jkimmina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf_conv.h>
#include <stdio.h>

char	*conv_char(va_list *ap, t_flags *flags)
{
	char	*ret;

	ret = ft_strnew(2);
	if (*flags->key == 'C' || ft_strcmp(flags->flagstr, "l") == 0)
		ret[0] = va_arg(*ap, wchar_t);
	else
		ret[0] = va_arg(*ap, int);
	ret[1] = '\0';
	if (ret[0] < 32 || ret[0] > 126)
		flags->strlen++;
	return (ret);
}

char	*conv_base(uintmax_t num, t_flags *flags, int base)
{
	char	*res;
	int		i;

	i = -1;
	res = ft_uitoa_base(num, base);
	if (*flags->key >= 'A' && *flags->key <= 'Z')
		while (res[++i] != '\0')
			res[i] = ft_toupper(res[i]);
	return (res);
}

char	*conv_signed(va_list *ap, t_flags *flags)
{
	if (ft_strcmp(flags->flagstr, "") == 0 && *flags->key == 'D')
		return (ft_sitoa(va_arg(*ap, long)));
	if (ft_strcmp(flags->flagstr, "hh") == 0)
		return (ft_sitoa((signed char)va_arg(*ap, int)));
	if (ft_strcmp(flags->flagstr, "h") == 0)
		return (ft_sitoa((short)va_arg(*ap, int)));
	if (ft_strcmp(flags->flagstr, "l") == 0)
		return (ft_sitoa(va_arg(*ap, long)));
	if (ft_strcmp(flags->flagstr, "ll") == 0)
		return (ft_sitoa(va_arg(*ap, long long)));
	if (ft_strcmp(flags->flagstr, "j") == 0)
		return (ft_sitoa(va_arg(*ap, intmax_t)));
	if (ft_strcmp(flags->flagstr, "z") == 0)
		return (ft_sitoa(va_arg(*ap, size_t)));
	return (ft_itoa(va_arg(*ap, int)));
}

char	*conv_unsigned(va_list *ap, t_flags *flags)
{
	uintmax_t	num;

	if (ft_strcmp(flags->flagstr, "l") == 0 || ft_strchr("Up", *flags->key))
		num = va_arg(*ap, unsigned long);
	else if (ft_strcmp(flags->flagstr, "hh") == 0)
		num = ((unsigned char)va_arg(*ap, int));
	else if (ft_strcmp(flags->flagstr, "h") == 0)
		num = ((unsigned short)va_arg(*ap, int));
	else if (ft_strcmp(flags->flagstr, "ll") == 0)
		num = va_arg(*ap, unsigned long long);
	else if (ft_strcmp(flags->flagstr, "j") == 0)
		num = va_arg(*ap, uintmax_t);
	else if (ft_strcmp(flags->flagstr, "z") == 0)
		num = va_arg(*ap, size_t);
	else
		num = va_arg(*ap, unsigned int);
	if (ft_strchr("uU", *flags->key))
		return (ft_uitoa(num));
	else if (ft_strchr("xXp", *flags->key))
		return (conv_base(num, flags, 16));
	else if (ft_strchr("oO", *flags->key))
		return (conv_base(num, flags, 8));
	return (0);
}

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
