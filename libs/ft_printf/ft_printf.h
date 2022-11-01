/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnacarel <fnacarel@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 16:36:36 by fnacarel          #+#    #+#             */
/*   Updated: 2022/11/01 16:42:47 by fnacarel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# define HEX_LOWCASE "0123456789abcdef"
# define HEX_UPCASE "0123456789ABCDEF"
# define DEC_DIGITS "0123456789"

# ifdef __linux__
#  define NULLABLE "(nil)"
# else
#  define NULLABLE "0x0"
# endif

int				putchar_printf(char c);
int				ft_putstr_printf(char *str);
size_t			ft_strlen(char *str);
int				ft_printf(const char *str, ...);
int				ft_put_address(unsigned long long nbr);
int				put_base_printf(long long nbr, char *base);
int				puthex_printf(unsigned long long nbr, int use_uppercase);


#endif
