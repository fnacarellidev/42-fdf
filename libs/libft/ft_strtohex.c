/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtohex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnacarel <fnacarel@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 14:38:46 by fnacarel          #+#    #+#             */
/*   Updated: 2022/12/01 15:24:29 by fnacarel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
long int	ft_hex_str_toi(char *str);

long int	ft_hex_str_toi(char *str)
{
	int			i;
	long int	res;

	res = 0;
	i = 0;
	if (str[i])
	{
		while (str[i])
		{
			if (str[i] >= '0' && str[i] <= '9')
				res = (res * 16) + (str[i] - '0');
			else if (str[i] >= 'A' && str[i] <= 'F')
				res = (res * 16) + (str[i] - 'A' + 10);
			else if (str[i] >= 'a' && str[i] <= 'f')
				res = (res * 16) + (str[i] - 'a' + 10);
			i++;
		}
	}
	return (res);
}
