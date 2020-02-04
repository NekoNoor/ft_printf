/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   printf_mediocre_nbr.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: nschat <nschat@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/29 18:21:07 by nschat        #+#    #+#                 */
/*   Updated: 2020/02/04 15:34:17 by nschat        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "printf_mediocre.h"
#include <unistd.h>

static int	nbrlen(t_data *data)
{
	unsigned long	nbr;
	int				base;
	int				len;

	if (data->type == 'p' || data->type == 'x' || data->type == 'X')
		base = 16;
	else
		base = 10;
	if (data->type == 'd' || data->type == 'i')
		nbr = data->arg.i < 0 ? -(long)data->arg.i : data->arg.i;
	else
		nbr = data->arg.ul;
	len = 1;
	while (nbr / base)
	{
		len++;
		nbr /= base;
	}
	return (len);
}

static int	extralen(t_data *data, int nbr_len)
{
	int	len;

	len = 0;
	if ((data->type == 'd' || data->type == 'i') && data->arg.i < 0)
		len += 1;
	if (data->type == 'p')
		len += 2;
	if (nbr_len < data->precision)
		len += data->precision - nbr_len;
	return (len);
}

static void	number_prefix(t_data *data)
{
	if ((data->type == 'd' || data->type == 'i') && data->arg.i < 0)
		write(1, "-", 1);
	if (data->type == 'p')
		write(1, "0x", 2);
}

static void	number_value(t_data *data)
{
	if (data->type == 'p')
		ft_putnbr(data->arg.ul, 16, 16);
	if (data->type == 'd' || data->type == 'i')
		ft_putnbr(data->arg.i < 0 ? -(long)data->arg.i : data->arg.i, 10, 0);
	if (data->type == 'u')
		ft_putnbr(data->arg.ui, 10, 0);
	if (data->type == 'x')
		ft_putnbr(data->arg.ui, 16, 16);
	if (data->type == 'X')
		ft_putnbr(data->arg.ui, 16, 0);
}

int			print_number(t_data *data)
{
	int padding;
	int	nbr_len;
	int extra_len;

	padding = 0;
	nbr_len = nbrlen(data);
	extra_len = extralen(data, nbr_len);
	if (data->flags.minus == 0 && nbr_len + extra_len < data->width)
		padding += pad(' ', data->width - (nbr_len + extra_len));
	number_prefix(data);
	if (nbr_len < data->precision)
		pad('0', data->precision - nbr_len);
	number_value(data);
	if (data->flags.minus == 1 && nbr_len + extra_len < data->width)
		padding += pad(' ', data->width - (nbr_len + extra_len));
	return (extra_len + nbr_len + padding);
}