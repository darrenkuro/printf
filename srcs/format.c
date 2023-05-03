/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlu <dlu@student.42berlin.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 10:58:18 by dlu               #+#    #+#             */
/*   Updated: 2023/05/03 18:42:57 by dlu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	format_char(int c, int *count)
{
	write(1, &c, 1);
	(*count)++;
}

void	format_str(char *s, int *count)
{
	if (!s)
	{
		format_null(count);
		return ;
	}
	while (*s)
	{
		write(1, s++, 1);
		(*count)++;
	}
}

/*
void	format_ptr(void *p, int *count)
{
	
}
*/
