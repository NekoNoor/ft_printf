/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   printf_mediocre.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: nschat <nschat@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/19 15:30:31 by nschat        #+#    #+#                 */
/*   Updated: 2020/02/17 18:01:23 by nschat        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "printf_mediocre.h"

int	ft_vprintf(const char *format, va_list ap)
{
	t_list	*list;
	int		len;

	list = analyze_format(format, ap);
	len = print_list(list);
	free_list(&list);
	return (len);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		len;

	va_start(ap, format);
	len = ft_vprintf(format, ap);
	va_end(ap);
	return (len);
}
