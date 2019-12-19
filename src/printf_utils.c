/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   printf_utils.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: nschat <nschat@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/11 19:25:24 by nschat        #+#    #+#                 */
/*   Updated: 2019/12/12 10:57:03 by nschat        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "printf_utils.h"

size_t	calc_size(const char *format, va_list ap)
{
	size_t	size;


}

t_list	*parse_format(const char *format)
{
	t_list	*head;
	t_list	*node;

	head = NULL;
	while (format)
	{
		format = ft_strchr(format, '%');
		data = (t_data *)malloc(sizeof(t_data));
		// TODO: free previous linked list if malloc fails
		if (data == NULL)
			return (NULL)
		node = ft_lstnew(data);
		if (format != NULL)
		{
			format++;
			data->parameter = get_parameter(&format);
			data->flags = get_flags(&format);
			data->width = get_width(&format);
			data->precision = get_precision(&format);
			data->length = get_length(&format);
			data->type = get_type(&format);
		}
		ft_lstadd_back(&head, node);
	}
	return (NULL);
}

int		get_parameter(char **format)
{
	char	*orig;

	orig = *format;
	while (ft_isdigit(**format))
		(*format)++;
	if (**format == '$')
		return (ft_atoi(orig));
	*format = orig;
	return (0);
}

char	get_flags(char **format)
{
	static const char	*flags = "-+ 0#";
	char				out;

	out = 0;
	while (ft_strchr(flags, **format))
	{
		if (**format == '-')
			out |= 0b00001
		if (**format == '+')
			out |= 0b00010
		if (**format == ' ')
			out |= 0b00100
		if (**format == '0')
			out |= 0b01000
		if (**format == '#')
			out |= 0b10000
		(*format)++;
	}
	return (out);
}

int		get_width(char **format)
{
}

int		get_precision(char **format)
{
}

char	*get_length(char **format)
{
}

char	get_type(char **format)
{
	static const char	*types = "cspdiuxX%nfge";

	while (ft_strchr(types, **format) == NULL)
		(*format)++;
	return (**format);
}
