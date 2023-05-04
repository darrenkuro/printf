/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlu <dlu@student.42berlin.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 10:31:59 by dlu               #+#    #+#             */
/*   Updated: 2023/05/04 14:14:42 by dlu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

# define DEC		"0123456789"
# define HEXU		"0123456789ABCDEF"
# define HEXL		"0123456789abcdef"
# define NULL_STR	"(null)"
# define NULL_LEN	6
# define NBR_SIZE	21

typedef struct s_format
{
	char	type;
	char	padding;
	char	num[NBR_SIZE];
	int		minus;
	int		plus;
	int		hash;
	int		space;
	int		dot;
	int		width;
	int		precision;
}	t_format;

int		ft_printf(const char *s, ...);

void	parse_format(char **s, va_list *args, t_format *format);
void	print_arg(va_list *args, t_format format, int *count);

int		print_sc(char *s, int *count, t_format format);
void	print_ptr(void *p, int *count, t_format format);
void	print_nbr(int n, char *base, int *count, t_format format);
void	print_nbr_u(unsigned int n, char *base, int *count, t_format format);

int		ft_strlen(char *s, t_format format);
int		print_padding(char c, int len);

#endif
