/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlu <dlu@student.42berlin.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 06:14:33 by dlu               #+#    #+#             */
/*   Updated: 2023/05/05 01:47:47 by dlu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/* Returns the length to be printed for string. */
int	ft_strlen(char *s, t_format format)
{
	int	i;

	if (!s || (format.type == 's' && format.dot && format.precision == 0))
		return (0);
	i = -1;
	while (s[++i])
		if (format.type == 's' && format.dot && i >= format.precision)
			return (i);
	return (i);
}

/* Return the length of the padding. */
int	print_padding(char c, int len)
{
	int	i;

	if (len <= 0)
		return (0);
	i = -1;
	while (++i < len)
		write(1, &c, 1);
	return (len);
}

void	print_prefix(int *count, t_format *format)
{
	if (format->neg || format->plus || format->space)
	{
		if (format->neg)
			write(1, "-", 1);
		else if (format->plus)
			write(1, "+", 1);
		else if (format->space)
			write(1, " ", 1);
		--(format->width);
		++(*count);
	}
	else if (format->hash)
	{
		if (format->type == 'x')
			write(1, "0x", 2);
		if (format->type == 'X')
			write(1, "0X", 2);
		format->width -= 2;
		*count += 2;
	}
}
