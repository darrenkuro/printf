/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlu <dlu@student.42berlin.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 10:58:18 by dlu               #+#    #+#             */
/*   Updated: 2023/05/04 06:37:23 by dlu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/* Resets the format to the initial state. */
static void	reset_format(t_format *format)
{
	format->type = 0;
	format->padding = ' ';
	format->minus = 0;
	format->plus = 0;
	format->hash = 0;
	format->space = 0;
	format->dot = 0;
	format->width = 0;
	format->precision = 0;
}

static int	parse(char *s, va_list *args)
{
	int			count;
	t_format	format;

	count = 0;
	reset_format(&format);
	while (*s)
	{
		if (*s == '%')
		{
			++s;
			parse_format(&s, args, &format);
			print_arg(args, format, &count);
			reset_format(&format);
		}
		else
		{
			write(1, s++, 1);
			++count;
		}
	}
	return (count);
}

int	ft_printf(const char *s, ...)
{
	int		count;
	va_list	args;

	va_start(args, s);
	count = parse((char *) s, &args);
	va_end(args);
	return (count);
}
