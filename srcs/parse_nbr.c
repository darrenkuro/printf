/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_nbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlu <dlu@student.42berlin.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 06:14:33 by dlu               #+#    #+#             */
/*   Updated: 2023/05/05 20:28:33 by dlu              ###   ########.fr       */
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
	while (n != 0 && ++len)
		n /= format->base;
	return (len);
}

/* Load the number string into format. */
void	load_nbr(int n, const char *base, t_format *format)
{
	char	*num;
	int		len;

	len = len_nbr(n, format) + 1;
	format->num = malloc(len * sizeof (char));
	num = format->num;
	if (n < 0)
		format->neg = 1;
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

/* Return the length of the nbr string, excluding '\0'. */
int	len_nbr_u(t_ull n, t_format *format)
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
void	load_nbr_u(t_ull n, const char *base, t_format *format)
{
	char	*num;
	int		len;

	len = len_nbr_u(n, format) + 1;
	format->num = malloc(len * sizeof(char));
	num = format->num;
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
