/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkimmina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 17:12:39 by jkimmina          #+#    #+#             */
/*   Updated: 2018/05/01 16:14:23 by jkimmina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <wchar.h>
#include <stdlib.h>
#include <ft_printf.h>
#include <limits.h>

int		main(void)
{
	//printf("%d\n", printf("%10R\n"));
	printf("%d\n", ft_printf("%10R\n"));
	return (0);
}
