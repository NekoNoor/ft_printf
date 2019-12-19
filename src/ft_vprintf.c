/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_vprintf.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: nschat <nschat@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/11 18:40:01 by nschat        #+#    #+#                 */
/*   Updated: 2019/12/11 19:44:08 by nschat        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "printf_utils.h"

int	ft_vprintf(const char *format, va_list ap)
{
	int len;

	len = ft_vdprintf(1, format, ap);
	return (len);
}

int	ft_vsprintf(char *str, const char *format, va_list ap)
{
	int	len;

	len = ft_vsnprintf(str, calc_size(format, ap), format, ap);
	return (len);
}

int	ft_vsnprintf(char *str, size_t size, const char *format, va_list ap)
{
	int	len;

	len = calc_size(format, ap);
	// TODO: build str from format
	return (len);
}

int	ft_vasprintf(char **ret, const char *format, va_list ap)
{
	size_t	size;
	int		len;

	size = calc_size(format, ap);
	*ret = (char *)malloc(sizeof(char) * size);
	if (*ret == NULL)
		return (-1);
	len = ft_vsnprintf(*ret, size, format, ap);
	return (len);
}

int	ft_vdprintf(int fd, const char *format, va_list ap)
{
	int		len;
	char	*ret;

	len = ft_vasprintf(&ret, format, ap);
	write(fd, ret, len);
	free(ret);
	return (len);
}
