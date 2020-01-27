/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   printf_mediocre.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: nschat <nschat@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/19 15:30:31 by nschat        #+#    #+#                 */
/*   Updated: 2020/01/27 18:28:21 by nschat        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "printf_mediocre.h"

int	ft_printf(const char *format, ...)
{
	t_list	*list;
	va_list	ap;
	int		len;

	va_start(ap, format);
	list = analyze_format(format, ap);
	va_end(ap);
	len = print_list(list);
	return (len);
}
