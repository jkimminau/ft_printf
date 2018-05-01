/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_num.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkimmina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/30 19:29:05 by jkimmina          #+#    #+#             */
/*   Updated: 2018/04/30 19:31:59 by jkimmina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf_conv.h>

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

