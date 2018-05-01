/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkimmina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 17:12:39 by jkimmina          #+#    #+#             */
/*   Updated: 2018/04/30 19:52:53 by jkimmina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <ft_printf.h>
#include <limits.h>

int		main(void)
{
	wchar_t	i;
	char	j;

	i = 0;
	j = 0;
	//while (i < 1000)
		//printf("%C\t i = %d\t%c\tj = %d\n", i++, i, j++, j);
	printf("%C\t%d,%C\t%d\n", L'暖', L'暖', L'ح', L'ح');
	return (0);
}
