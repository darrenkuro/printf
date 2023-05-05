/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlu <dlu@student.42berlin.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 15:35:33 by dlu               #+#    #+#             */
/*   Updated: 2023/05/05 00:14:47 by dlu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/* Parse '-' and '0', '0' is ignored when '-' is present. */
static void	parse_flags(char **s, t_format *format)
{
	while (**s == '-' && (*s)++)
		format->minus = 1;
	while (**s == '+' && (*s)++)
		format->plus = 1;
	while (**s == '#' && (*s)++)
		format->hash = 1;
	while (**s == ' ' && (*s)++)
		format->space = 1;
	if (format->minus)
		return ;
	while (**s == '0' && (*s)++)
		format->padding = '0';
}

static void	parse_width(char **s, va_list *args, t_format *format)
{
	if (**s == '*')
	{
		format->width = va_arg(*args, int);
		(*s)++;
		return ;
	}
	while (**s >= '0' && **s <= '9')
	{
		format->width = (format->width * 10) + **s - '0';
		(*s)++;
	}
}

static void	parse_precision(char **s, va_list *args, t_format *format)
{
	if (**s == '.')
	{
		format->dot = 1;
		(*s)++;
	}
	if (**s == '*')
	{
		format->precision = va_arg(*args, int);
		if (format->precision < 0)
		{
			format->precision = 0;
			format->dot = 0;
		}
		(*s)++;
	}
	while (**s >= '0' && **s <= '9')
	{
		format->precision = (format->precision * 10) + **s - '0';
		(*s)++;
	}
}

void	parse_format(char **s, va_list *args, t_format *format)
{
	parse_flags(s, format);
	parse_width(s, args, format);
	parse_precision(s, args, format);
	format->type = **s;
	if (**s == 'p' || **s == 'x' || **s == 'X')
		format->base = 16;
	(*s)++;
}
