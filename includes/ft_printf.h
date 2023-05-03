/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlu <dlu@student.42berlin.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 10:31:59 by dlu               #+#    #+#             */
/*   Updated: 2023/05/03 19:28:55 by dlu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

typedef struct s_format
{
	char	type;
	int		minus;
	int		plus;
	int		zero;
	int		hash;
	int		space;
	int		dot;
}	t_format;

# define DEC		"0123456789"
# define HEXU		"0123456789ABCDEF"
# define HEXL		"0123456789abcdef"
# define NULL_STR	"(null)"
# define NULL_LEN	6

int		ft_printf(const char *s, ...);

void	print_char(char **s, int *count);
void	print_arg(char **s, va_list *args, int *count);
void	parse_flag(char **s, va_list *args, t_format *format);

void	format_char(int c, int *count);
void	format_str(char *s, int *count);
void	format_ptr(void *p, int *count);
void	format_nbr(int n, const char *base, int *count);
void	format_nbr_u(unsigned int n, const char *base, int *count);

int		write_null(int *count);
int		write_ull(unsigned long long n, int *count);

#endif
