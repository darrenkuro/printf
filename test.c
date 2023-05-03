/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlu <dlu@student.42berlin.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 15:43:37 by dlu               #+#    #+#             */
/*   Updated: 2023/05/03 19:13:22 by dlu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stddef.h>

// doesn't work!
// %.5-10s

int	main(void)
{
	printf("%-10s%%-10s\n", "abcdefg");
	printf("%-10.5s%%-10.5s\n", "abcdefg");
	printf("%.5s%%.5s\n", "abcdefg");
	printf("%+10d%%+10d\n", 42);
	printf("%10d%%10d\n", 42);
	printf("%#x%%#x\n", 42);
	printf("%x%%x\n", 42);
	printf("%s%%s NULL\n", (char *) NULL);
	printf("%10d%%10d\n", 42);
	printf("%10d%%10d\n", 42);
	return (0);
}
