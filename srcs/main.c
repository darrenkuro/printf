/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlu <dlu@student.42berlin.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 15:59:59 by dlu               #+#    #+#             */
/*   Updated: 2023/05/04 17:21:36 by dlu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#include <stdlib.h>

int	main(void)
{
	char	*test;
	int	ret = ft_printf(" %x \n", -1);

	test = malloc(1);
	printf("%d\n", ret);
	printf(" %p \n", 0);
	ft_printf(" %p \n", test);
	return (0);
}
