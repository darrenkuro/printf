/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlu <dlu@student.42berlin.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 10:58:18 by dlu               #+#    #+#             */
/*   Updated: 2023/05/03 18:25:42 by dlu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_char(char **s, int *count)
{
	write(1, (*s)++, 1);
	(*count)++;
}

void	print_arg(char **s, va_list *args, int *count)
{
	//t_format	format;

	(*s)++;
	//parse_flag(s, args, &format);
	//if (format.flag == 's')
	if (**s == 'c')
		format_char(va_arg(*args, int), count);
	else if (**s == 's')
		format_str(va_arg(*args, char *), count);
	/*
	else if (**s == 'p')
		format_ptr(va_arg(*args, void *), count);
	else if (**s == 'd' || **s == 'i')
		format_nbr(va_arg(*args, int), DEC, count);
	else if (**s == 'u')
		format_nbr_u(va_arg(*args, unsigned int), DEC, count);
	else if (**s == 'x')
		format_nbr(va_arg(*args, int), HEXL, count);
	else if (**s == 'X')
		format_nbr(va_arg(*args, int), HEXU, count);
		*/
	else if (**s == '%')
		format_char('%', count);
	(*s)++;
}
