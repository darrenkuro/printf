/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlu <dlu@student.42berlin.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 15:59:59 by dlu               #+#    #+#             */
/*   Updated: 2023/05/05 02:15:17 by dlu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>
#include <stdio.h>

int	main(void)
{
	int	ret;

	ret = ft_printf(" %#X\n", 255);
	printf("%d\n", ret);
	printf("------std------\n");
	printf("%.6s\n", (char *) NULL);
	return (0);
}
