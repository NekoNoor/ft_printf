/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   printf_garbage.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: nschat <nschat@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/12 12:14:07 by nschat        #+#    #+#                 */
/*   Updated: 2020/01/16 18:51:23 by nschat        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>

#include <stdio.h>

int		ft_putchar(char c, char flags, int field_width);

size_t	ft_strlen(char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

size_t	ft_nbrlen(long nbr, int sign, int base)
{
	size_t	len;

	len = 1;
	if (sign == 1 && nbr < 0)
		len++;
	while (nbr / base)
	{
		nbr /= base;
		len++;
	}
	return (len);
}

int		pad(char c, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
		i += ft_putchar(c, 0, -1);
	return (i);
}

int		ft_putchar(char c, char flags, int field_width)
{
	int	padding;

	padding = 0;
	if (field_width != -1 && !(flags & 0b01) && 1 < field_width)
		padding += pad(' ', field_width - 1);
	write(1, &c, 1);
	if (field_width != -1 && (flags & 0b01) && 1 < field_width)
		padding += pad(' ', field_width - 1);
	return (1 + padding);
}

int		ft_putnbr_recursive(long nbr, int sign, int upcs, int base)
{
	static const char	*chars = "0123456789ABCDEF0123456789abcdef";


	if (sign)
}

int		ft_putnbr(long nbr, int sign, int upcs, int base, char flags, int field_width, int precision)
{
	int					padding;
	int					len;

	len = ft_nbrlen(nbr, sign, base);
	padding = 0;
	if (field_width != -1 && !(flags & 0b11) && len < field_width)
		padding += pad(' ', field_width - len);
	if (sign && nbr < 0)
	{
		len += ft_putchar('-', 0, -1);
		nbr = -nbr;
	}
	if (precision != -1 && flags & 0b01 && len < precision)
		padding += pad('0', precision - len - sign);
	
	if (field_width != -1 && flags & 0b10 && len < field_width)
		padding += pad(' ', field_width - len);
	return (len + padding);
}

int		ft_putstr(char *str, char flags, int field_width, int precision)
{
	int	padding;
	int	len;

	padding = 0;
	if (str == NULL)
		str = "(null)";
	len = ft_strlen(str);
	if (precision != -1 && len > precision)
		len = precision;
	if (field_width != -1 && !(flags & 0b01) && len < field_width)
		padding += pad(' ', field_width - len);
	write(1, str, len);
	if (field_width != -1 && (flags & 0b01) && len < field_width)
		padding += pad(' ', field_width - len);
	return (len + padding);
}

int		ft_isspace(int c)
{
	return ((c >= 9 && c <= 13) || c == 32);
}

int		ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

int		ft_atoi(char *str)
{
	unsigned	out;
	int			sign;

	while (ft_isspace(*str))
		str++;
	sign = (*str == '-') ? -1 : 1;
	if (*str == '-' || *str == '+')
		str++;
	out = 0;
	while (ft_isdigit(*str))
	{
		out = out * 10 + (*str - '0');
		str++;
	}
	return (out * sign);
}

int 	print_things(const char *format, va_list ap)
{
	char	*str;
	size_t	nbr;
	int		len;
	char	flags;
	int		field_width;
	int		precision;

	len = 0;
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			flags = 0;
			field_width = -1;
			precision = -1;
			while (*format == '-' || *format == '0')
			{
				if (*format == '-')
					flags |= 0b01;
				if (*format == '0')
				{
					flags |= 0b10;
					flags &= ~0b01;
				}
				format++;
			}
			if (ft_isdigit(*format) || *format == '*' || *format == '.')
			{
				if (ft_isdigit(*format) || *format == '*')
				{
					if (*format == '*')
					{
						field_width = va_arg(ap, int);
						if (field_width < 0)
						{
							if (!(flags & 0b10))
								flags |= 0b01;
							field_width *= -1;
						}
						format++;
					}
					else
					{
						field_width = ft_atoi((char *)format);
						while (ft_isdigit(*format))
							format++;
					}
				}
				if (*format == '.')
				{
					format++;
					if (*format == '*')
					{
						precision = va_arg(ap, int);
						format++;
					}
					else
					{
						precision = ft_atoi((char *)format);
						while (ft_isdigit(*format))
							format++;
					}
				}
			}
			if (*format == 'c')
			{
				nbr = va_arg(ap, int);
				len += ft_putchar(nbr, flags, field_width);
				format++;
			}
			if (*format == 's')
			{
				str = va_arg(ap, char *);
				len += ft_putstr(str, flags, field_width, precision);
				format++;
			}
			if (*format == 'p')
			{
				nbr = va_arg(ap, unsigned long);
				len += ft_putstr("0x", 0, -1, -1);
				len += ft_putnbr(nbr, 0, 0, 16, flags, field_width, precision);
				format++;
			}
			if (*format == 'd' || *format == 'i')
			{
				nbr = va_arg(ap, int);
				len += ft_putnbr(nbr, 1, 0, 10, flags, field_width, precision);
				format++;
			}
			if (*format == 'u')
			{
				nbr = va_arg(ap, unsigned long);
				len += ft_putnbr(nbr, 0, 0, 10, flags, field_width, precision);
				format++;
			}
			if (*format == 'x' || *format == 'X')
			{
				nbr = va_arg(ap, unsigned int);
				len += ft_putnbr(nbr, 0, (*format == 'x') * 16, 16, flags, field_width, precision);
				format++;
			}
			if (*format == '%')
			{
				len += ft_putchar('%', 0, -1);
				format++;
			}
		}
		len += ft_putchar(*format, 0, -1);
		format++;
	}
	return (len);
}

int		printf_garbage(const char *format, ...)
{
	va_list	ap;
	int		len;

	va_start(ap, format);
	len = print_things(format, ap);
	va_end(ap);
	return (len);
}

int		main(void)
{
	int		len;
	void	*test;

	test = malloc(1);
	printf("ft\n");
	len = printf_garbage("c [%5c]\ns [%-*.*s]\np [%5p]\nd [%5.*d]\ni [%*.5i]\nu [%u]\nx [%x]\nX [%X]\n[%%]\n", 0x41, 10, 5, "string", test, 10, 97, 10, -98, 18446744073709551615UL, 0xD3ADB33F, 0xD3ADB33F);
	printf("len = %d\n", len);
	printf("bsd\n");
	len = printf("c [%5c]\ns [%-*.*s]\np [%5p]\nd [%5.*d]\ni [%*.5i]\nu [%lu]\nx [%x]\nX [%X]\n[%%]\n", 0x41, 10, 5, "string", test, 10, 97, 10, -98, 18446744073709551615UL, 0xD3ADB33F, 0xD3ADB33F);
	printf("len = %d\n", len);
	return (0);
}
