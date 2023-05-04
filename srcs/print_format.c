/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlu <dlu@student.42berlin.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 10:58:18 by dlu               #+#    #+#             */
/*   Updated: 2023/05/04 17:22:31 by dlu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_char(char c, int *count, t_format format)
{
	if (!format.minus)
		count += print_padding(format.padding, format.width - 1);
	write(1, &c, 1);
	(*count)++;
	if (format.minus)
		count += print_padding(format.padding, format.width - 1);
}

/* Handles output for %s, %c, %%. */
int	print_str(char *s, int *count, t_format format)
{
	int	len;
	int	i;

	if (!s && print_str(NULL_STR, count, format))
		return (0);
	len = ft_strlen(s, format);
	if (!format.minus)
		count += print_padding(format.padding, format.width - len);
	i = -1;
	while (++i < len)
		write(1, &s[i], 1);
	*count += len;
	if (format.minus)
		count += print_padding(format.padding, format.width - len);
	return (1);
}

void	print_nbr(int n, char *base, int *count, t_format format)
{
	if (format.type == 'd' || format.type == 'i')
		load_nbr(n, base, &format);
	else if (format.type == 'x' || format.type == 'X' || format.type == 'u')
		load_nbr_u((unsigned int) n, base, &format);
	print_str(format.num, count, format);
}

void	print_ptr(void *p, int *count, t_format format)
{
	if (!p && print_str(NULL_PTR, count, format))
		return ;
	load_nbr_ptr(p, HEXL, &format);
	print_str(format.num, count, format);
}
