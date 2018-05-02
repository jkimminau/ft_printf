/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_flags.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkimmina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 14:48:27 by jkimmina          #+#    #+#             */
/*   Updated: 2018/05/01 16:57:02 by jkimmina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf_flags.h>
#include <stdio.h>

char	*alt_flag(char *conv, t_flags *flags)
{
	char	*res;

	if (flags->alt == 0 && *flags->key != 'p')
		return (conv);
	else if (ft_strcmp(conv, "") == 0 || (ft_strcmp(conv, "0") == 0 && *flags->key != 'p'))
		return (conv);
	else if (ft_strchr("oO",*(flags->key)))
		res = ft_strjoin("0", conv);
	else if (ft_strchr("xp", *flags->key))
		res = ft_strjoin("0x", conv);
	else if (*(flags->key) == 'X')
		res = ft_strjoin("0X", conv);
	else
		return (conv);
	free(conv);
	return (res);
}

char	*plus_flag(char *conv, t_flags *flags)
{
	char	*res;

	if ((*(flags->key) != 'd' && *(flags->key) != 'i') || ft_strstr(conv, "-"))
		return (conv);
	res = ft_strjoin("+", conv);
	free(conv);
	return (res);
}

char	*space_flag(char *conv, t_flags *flags)
{
	char	*res;

	if ((*(flags->key) != 'd' && *(flags->key) != 'i')
			|| flags->plus || ft_strstr(conv, "-"))
		return (conv);
	res = ft_strjoin(" ", conv);
	free(conv);
	return (res);
}

char	*prec_flag(char *conv, t_flags *flags)
{
	char	*res;
	char	*list;
	int		i;
	int		digits;

	list = ft_strdup("diouxX");
	if (ft_strchr(list, *flags->key))
	{
		digits = ft_strlen(conv) - (ft_strstr(conv, "-") != 0);
		if (flags->prec == 0 && ft_strcmp("0", conv) == 0 && !(*(flags->key) == 'o' && flags->alt))
			res = ft_strdup("");
		else if (digits < flags->prec)
		{
			i = -1;
			res = ft_strnew(flags->prec + 1 + (ft_strstr(conv, "-") != 0));
			ft_memset(res, '0', flags->prec + (ft_strstr(conv, "-") != 0));
			while (!ft_isdigit(conv[++i]))
				res[i] = conv[i];
			ft_strcpy(res + flags->prec + (ft_strstr(conv, "-") != 0) - ft_strlen(conv + i), conv + i);
		}
		else
			res = ft_strdup(conv);
	}
	else if (*(flags->key) == 's')
		res = ft_strsub(conv, 0, flags->prec);
	else
		res = ft_strdup(conv);
	free(list);
	free(conv);
	return (res);
}

char	*num_flag(char *conv, t_flags *flags)
{
	char	*res;
	int		strlen;
	char	*lst;
	int		i;

	strlen = flags->strlen + ft_strlen(conv);
	if (strlen >= flags->width)
		return (conv);
	res = ft_strnew(flags->width + 1);
	if (flags->zero && flags->minus == 0 && flags->prec == -1)
		ft_memset(res, '0', flags->width);
	else
		ft_memset(res, ' ', flags->width);
	if (flags->minus)
		ft_strncpy(res, conv, strlen);
	else
	{
		lst = ft_strdup("dioxX");
		i = 0;
		if (ft_strchr(lst, *flags->key))
			while ((conv[i] < '1' || conv[i] > '9')
					&& conv[i] && (flags->zero && flags->prec == -1))
			{
				res[i] = conv[i];
				i++;
			}
		free(lst);
		ft_strcpy(res + flags->width - strlen + i, conv + i);
	}
	free(conv);
	return (res);
}
