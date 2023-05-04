/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_nbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlu <dlu@student.42berlin.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 06:14:33 by dlu               #+#    #+#             */
/*   Updated: 2023/05/04 17:22:17 by dlu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

/* Return the length of the nbr string, excluding '\0'. */
int	len_nbr_u(unsigned long long n, t_format *format)
{
	int	len;

	len = 0;
	if (n == 0)
		return (++len);
	while (n > 0 && ++len)
		n /= format->base;
	return (len);
}

/* Load the number string into format. */
void	load_nbr_u(unsigned int n, const char *base, t_format *format)
{
	char	*num;
	int		len;

	num = format->num;
	len = len_nbr_u(n, format) + 1;
	num[--len] = '\0';
	while (--len >= 0)
	{
		if (n > 0)
			num[len] = base[n % format->base];
		else
			num[len] = base[-(n % format->base)];
		n /= format->base;
	}
}

void	load_nbr_ptr(void *p, const char *base, t_format *format)
{
	char				*num;
	int					len;
	unsigned long long	n;

	n = (unsigned long long) p;
	num = format->num;
	len = len_nbr_u(n, format) + 3;
	num[0] = '0';
	num[1] = 'x';
	num[--len] = '\0';
	while (--len >= 2)
	{
		num[len] = base[n % format->base];
		n /= format->base;
	}
}
