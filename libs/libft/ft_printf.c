/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnacarel <fnacarel@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 11:22:50 by fnacarel          #+#    #+#             */
/*   Updated: 2022/10/05 19:12:00 by fnacarel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	putchar_printf(char c)
{
	return (write(1, &c, 1));
}

static int	ft_percent_handler(char c, va_list ptr)
{
	int	charsprinted;

	charsprinted = 0;
	if (c == 'c')
		charsprinted += putchar_printf(va_arg(ptr, int));
	else if (c == 's')
		charsprinted += ft_putstr_printf(va_arg(ptr, char *));
	else if (c == 'p')
		charsprinted += ft_put_address(va_arg(ptr, unsigned long long));
	else if (c == 'd' || c == 'i')
		charsprinted += put_base_printf(va_arg(ptr, int), DEC_DIGITS);
	else if (c == 'u')
		charsprinted += put_base_printf(va_arg(ptr, unsigned int), DEC_DIGITS);
	else if (c == 'x')
		charsprinted += put_base_printf(va_arg(ptr, unsigned int), HEX_LOWCASE);
	else if (c == 'X')
		charsprinted += put_base_printf(va_arg(ptr, unsigned int), HEX_UPCASE);
	else if (c == '%')
		return (write(1, "%", 1));
	return (charsprinted);
}

int	ft_printf(const char *str, ...)
{
	va_list	ptr;
	int		count;
	int		i;

	i = 0;
	count = 0;
	va_start(ptr, str);
	if (!str)
		return (-1);
	while (str[i])
	{
		if (str[i] == '%')
			count += ft_percent_handler(str[++i], ptr);
		else
			count += putchar_printf(str[i]);
		i++;
	}
	va_end(ptr);
	return (count);
}
