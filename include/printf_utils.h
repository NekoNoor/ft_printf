/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   printf_utils.h                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: nschat <nschat@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/11 19:24:41 by nschat        #+#    #+#                 */
/*   Updated: 2019/12/12 10:46:49 by nschat        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_UTILS_H
# define PRINTF_UTILS_H
# include "libft.h"
# include <stdarg.h>

size_t	calc_size(const char *format, va_list ap)
t_list	*parse_format(const char *format, va_list ap);

int		get_parameter(char **format)
char	get_flags(char **format)
int		get_width(char **format)
int		get_precision(char **format)
char	*get_length(char **format)
char	get_type(char **format, va_list ap)

#endif
