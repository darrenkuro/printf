/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlu <dlu@student.42berlin.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 04:53:15 by dlu               #+#    #+#             */
/*   Updated: 2023/05/03 09:18:44 by dlu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	main(void)
{
	printf("%c\n", 'a' + (256 * 10));
	// - pads on the right, with spaces
	printf("%-10s\n", "test-");
	printf("%c\n", 'Z'); // warning about types? undefined; whatever
	printf("%-1d\n", 666); // doesn't truncate
	//printf("%0-10i\n", 17123);
	printf("%.5s\n", "this is a test");
	return (0);
}
