/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   printf_mediocre.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: nschat <nschat@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/19 15:30:31 by nschat        #+#    #+#                 */
/*   Updated: 2020/01/22 13:47:28 by nschat        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "printf_mediocre.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			break ;
		s++;
	}
	if (*s == (char)c)
		return ((char *)s);
	return (NULL);
}

int		print_list(t_list *list)
{
	int	len;


}

int		ft_printf(const char *format, ...)
{
	t_list	*list;
	va_list	ap;
	int		len;

	va_start(ap, format);
	list = analyze_format(format, ap);
	len = print_list(list);
	va_end(ap);
	return (len);
}
