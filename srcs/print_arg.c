/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlu <dlu@student.42berlin.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 10:58:18 by dlu               #+#    #+#             */
/*   Updated: 2023/05/04 17:17:51 by dlu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_arg(va_list *args, t_format format, int *count)
{
	if (format.type == 'c')
		print_char(va_arg(*args, int), count, format);
	else if (format.type == 's')
		print_str(va_arg(*args, char *), count, format);
	else if (format.type == 'p')
		print_ptr(va_arg(*args, void *), count, format);
	else if (format.type == 'd' || format.type == 'i')
		print_nbr(va_arg(*args, int), DEC, count, format);
	else if (format.type == 'x')
		print_nbr(va_arg(*args, unsigned int), HEXL, count, format);
	else if (format.type == 'X')
		print_nbr(va_arg(*args, unsigned int), HEXU, count, format);
	else if (format.type == 'u')
		print_nbr(va_arg(*args, unsigned int), DEC, count, format);
	else if (format.type == '%')
		print_char('%', count, format);
}
