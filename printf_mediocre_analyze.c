/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   printf_mediocre_analyze.c                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: nschat <nschat@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/22 13:46:00 by nschat        #+#    #+#                 */
/*   Updated: 2020/01/22 13:47:27 by nschat        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "printf_mediocre.h"

t_flags	get_flags(const char **format)
{
	const char	*stop = "cspdiuxX%123456789";
	t_flags		flags;

	flags.minus = 0;
	flags.zero = 0;
	while (**format)
	{
		if (**format == '-')
			flags.minus = 1;
		if (**format == '0')
			flags.zero = 1;
		if (ft_strchr(stop, **format) != NULL)
			break ;
		(*format)++;
	}
	if (flags.minus && flags.zero)
		flags.zero = 0;
	return (flags);
}

int		get_width(const char **format, va_list ap, t_data *data)
{

}

int		get_precision(const char **format, va_list ap)
{

}

char	get_type(const char **format)
{

}

t_list	*analyze_format(const char *format, va_list ap)
{
	t_list	*list;
	t_data	*data;

	list = NULL;
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			data = (t_data *)malloc(sizeof(t_data));
			if (data == NULL)
			
				free_list(&list);
				return (NULL);
			}
			data->flags = get_flags(&format);
			data->width = get_width(&format, ap, data);
			data->precision = get_precision(&format, ap);
			data->type = get_type(&format);
			ft_lstadd_back(&list, ft_lstnew(data));
		}
		format++;
	}
	return (list);
}
