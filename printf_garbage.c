/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   printf_garbage.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: nschat <nschat@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/12 12:14:07 by nschat        #+#    #+#                 */
/*   Updated: 2019/12/19 20:17:31 by nschat        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>

#include <stdio.h>

size_t	ft_strlen(char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

int		ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int		ft_putnbr(long nbr, int sign, int upcs, int base)
{
	static const char	*chars = "0123456789ABCDEF0123456789abcdef";

	if (sign && nbr < 0)
		return (ft_putchar('-') + ft_putnbr(-nbr, 0, upcs, base));
	if ((size_t)nbr >= (size_t)base)
		return (ft_putnbr((size_t)nbr / base, 0, upcs, base) +
				ft_putchar(upcs ? chars[(size_t)nbr % base] : chars[(size_t)nbr % base + 16]));
	return (ft_putchar(upcs ? chars[(size_t)nbr % base] : chars[(size_t)nbr % base + 16]));
}

int		ft_putstr(char *str)
{
	int	len;

	len = ft_strlen(str);
	write(1, str, len);
	return (len);
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
			field_width = 0;
			precision = 0;
			while (*format == '-' || *format == '0')
			{
				if (*format == '-')
					flags |= 0b01;
				if (*format == '0')
				{
					flags |= 0b10;
					flags &= ~0b10;
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
				len += ft_putchar(nbr);
				format++;
			}
			if (*format == 's')
			{
				str = va_arg(ap, char *);
				len += ft_putstr(str);
				format++;
			}
			if (*format == 'p')
			{
				nbr = va_arg(ap, unsigned long);
				len += ft_putstr("0x");
				len += ft_putnbr(nbr, 0, 0, 16);
				format++;
			}
			if (*format == 'd' || *format == 'i')
			{
				nbr = va_arg(ap, int);
				len += ft_putnbr(nbr, 1, 0, 10);
				format++;
			}
			if (*format == 'u')
			{
				nbr = va_arg(ap, unsigned long);
				len += ft_putnbr(nbr, 0, 0, 10);
				format++;
			}
			if (*format == 'x' || *format == 'X')
			{
				nbr = va_arg(ap, unsigned int);
				len += ft_putnbr(nbr, 0, 'x' - *format, 16);
				format++;
			}
			if (*format == '%')
			{
				len += ft_putchar('%');
				format++;
			}
		}
		len += ft_putchar(*format);
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
	len = printf_garbage("c %c\ns %*.*s\np %5p\nd %5.*d\ni %*.5i\nu %u\nx %x\nX %X\n%%\n", 0x41, 10, 10, "string", test, 10, 97, 10, -98, 18446744073709551615UL, 0x41ADBEEF, 0x41ADBEEF);
	printf("len = %d\n", len);
	printf("bsd\n");
	len = printf("c %c\ns %*.*s\np %5p\nd %5.*d\ni %*.5i\nu %lu\nx %x\nX %X\n%%\n", 0x41, 10, 10, "string", test, 10, 97, 10, -98, 18446744073709551615UL, 0x41ADBEEF, 0x41ADBEEF);
	printf("len = %d\n", len);
	return (0);
}
