/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlu <dlu@student.42berlin.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 15:43:37 by dlu               #+#    #+#             */
/*   Updated: 2023/05/04 06:48:29 by dlu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stddef.h>

// doesn't work!
// %.5-10s
// (null) follows the format still

int	main(void)
{
	printf("%-10s%%-10s\n", "abcdefg");
	printf("%-10.5s%%-10.5s\n", "abcdefg");
	printf("%.5s%%.5s\n", "abcdefg");
	printf("%+10d%%+10d\n", 42);
	printf("%10d%%10d\n", 42);
	printf("%#x%%#x\n", 42);
	printf("%x%%x\n", 42);
	printf("%10s%%s NULL\n", (char *) NULL);
	printf("%10%%%10c\n");
	printf("%-10s\n", "abc");
	return (0);
}
