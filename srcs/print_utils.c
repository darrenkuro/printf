/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlu <dlu@student.42berlin.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 06:14:33 by dlu               #+#    #+#             */
/*   Updated: 2023/05/04 15:53:35 by dlu              ###   ########.fr       */
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
		if (format.type == 's' && i >= format.precision)
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

/* Return the length of the nbr string, excluding '\0'. */
int	len_nbr(int n, t_format *format)
{
	int	len;

	len = 0;
	if (n == 0)
		return (++len);
	if (n == INT_MIN)
		return (INT_MINLEN);
	if (n < 0 && ++len)
		n = -n;
	while (n > 0 && ++len)
		n /= format->base;
	return (len);
}

/* Load the number string into format. */
void	load_nbr(int n, const char *base, t_format *format)
{
	char	*num;
	int		len;

	num = format->num;
	len = len_nbr(n, format) + 1;
	if (n < 0)
		num[0] = '-';
	num[--len] = '\0';
	while (--len >= 0 && num[len] != '-')
	{
		if (n > 0)
			num[len] = base[n % format->base];
		else
			num[len] = base[-(n % format->base)];
		n /= format->base;
	}
}
