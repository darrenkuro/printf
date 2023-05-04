/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlu <dlu@student.42berlin.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 10:58:18 by dlu               #+#    #+#             */
/*   Updated: 2023/05/04 16:24:53 by dlu              ###   ########.fr       */
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
	load_nbr(n, base, &format);
	print_str(format.num, count, format);
}

/*
void	format_ptr(void *p, int *count)
{
	unsigned long long i;

	if (!p && write_null(count))
		return ;
	//write_ull(*(unsigned long long *) p, count);
	i = 16 * 16 * 16 * 16 * 16 * 16 * 16;
	while (++i < )
}
*/
