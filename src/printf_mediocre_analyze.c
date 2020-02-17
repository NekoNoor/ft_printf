/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   printf_mediocre_analyze.c                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: nschat <nschat@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/22 13:46:00 by nschat        #+#    #+#                 */
/*   Updated: 2020/02/17 17:57:09 by nschat        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "printf_mediocre.h"

static size_t	to_next(const char *format)
{
	size_t	len;

	len = 0;
	while (format[len] && format[len] != '%')
		len++;
	return (len);
}

static void		make_string(const char **format, t_data *data)
{
	size_t	skip_len;

	data->flags = (t_flags){0, 0};
	data->width = -1;
	data->precision = -1;
	data->type = 't';
	skip_len = to_next(*format);
	data->arg.s = ft_substr(*format, 0, skip_len);
	*format += skip_len;
}

static void		fill_data(const char **format, va_list ap, t_data *data)
{
	(*format)++;
	data->flags = get_flags(format);
	data->width = get_width(format, ap, data);
	data->precision = get_precision(format, ap);
	if (data->flags.minus && data->flags.zero)
		data->flags.zero = 0;
	if (data->precision != -1 && data->flags.zero == 1)
		data->flags.zero = 0;
	data->type = **format;
	get_arg(format, ap, data);
}

t_list			*analyze_format(const char *format, va_list ap)
{
	t_list	*list;
	t_data	*data;

	list = NULL;
	while (*format)
	{
		data = (t_data *)malloc(sizeof(t_data));
		if (data == NULL)
		{
			free_list(&list);
			return (NULL);
		}
		if (*format == '%')
			fill_data(&format, ap, data);
		else
			make_string(&format, data);
		ft_lstadd_back(&list, ft_lstnew(data));
	}
	return (list);
}
