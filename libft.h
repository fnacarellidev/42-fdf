/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnacarel <fnacarel@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 12:10:00 by fnacarel          #+#    #+#             */
/*   Updated: 2022/11/01 12:41:46 by fnacarel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef LIBFT_H
# define LIBFT_H
# include <unistd.h>
# include <stdarg.h>

# ifdef __linux__
#  define NULLABLE "(nil)"
# else
#  define NULLABLE "0x0"
# endif

# define DEC_DIGITS "0123456789"
# define HEX_UPCASE "0123456789ABCDEF"
# define HEX_LOWCASE "0123456789abcdef"

size_t	ft_strlen(const char *s);

// ft_printf stuff
int		putchar_printf(char c);
int		ft_putstr_printf(char *str);
size_t	ft_strlen_printf(char *str);
int		ft_put_address(unsigned long long nbr);
int		put_base_printf(long long nbr, char *base);
int		puthex_printf(unsigned long long nbr, int use_uppercase);
int		ft_putchar_printf(char c);


#endif
