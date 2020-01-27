/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   printf_mediocre_print.c                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: nschat <nschat@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/22 13:58:16 by nschat        #+#    #+#                 */
/*   Updated: 2020/01/27 18:27:10 by nschat        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "printf_mediocre.h"
#include <stdio.h> //

int	print_list(t_list *list)
{
	/*
	 *int					len;
	 *const t_dispatch	dispatch_table[10] = {
	 *    {'c', &print_char},
	 *    {'s', &print_string},
	 *    {'p', &print_number},
	 *    {'d', &print_number},
	 *    {'i', &print_number},
	 *    {'u', &print_number},
	 *    {'x', &print_number},
	 *    {'X', &print_number},
	 *    {'%', &print_char}
	 *};
	 */
	printf("list->data->flags.minus: %i\n", list->data->flags.minus);
	printf("list->data->flags.zero: %i\n", list->data->flags.zero);
	printf("list->data->precision: %i\n", list->data->precision);
	printf("list->data->width: %i\n", list->data->width);
	printf("list->data->type: %c\n", list->data->type);
	printf("list->data->arg: %s\n", list->data->arg.s);
	return (0);
}
