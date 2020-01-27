/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   printf_mediocre_utils.c                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: nschat <nschat@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/24 17:10:08 by nschat        #+#    #+#                 */
/*   Updated: 2020/01/27 15:08:05 by nschat        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "printf_mediocre.h"

int	ft_atoi(char *str)
{
	unsigned	out;
	int			sign;

	while (ft_isspace(*str))
		str++;
	sign = (*str == '-') ? -1 : 1;
	str += (*str == '-' || *str == '+');
	out = 0;
	while (ft_isdigit(*str))
	{
		out = out * 10 + (*str - '0');
		str++;
	}
	return (out * sign);
}

int ft_isspace(int c)
{
	return ((c >= 9 && c <= 13) || c == 32);
}

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}
