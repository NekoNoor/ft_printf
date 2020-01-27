/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   printf_mediocre.h                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: nschat <nschat@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/21 19:17:31 by nschat        #+#    #+#                 */
/*   Updated: 2020/01/27 18:27:21 by nschat        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_MEDIOCRE_H
# define PRINTF_MEDIOCRE_H
# include <stdarg.h>
# include <stdlib.h>

typedef struct	s_flags
{
	int minus;
	int zero;
}				t_flags;

typedef union	u_arg
{
	char			c;
	char			*s;
	int				i;
	unsigned int	ui;
	void			*p;
}				t_arg;

typedef struct	s_data
{
	t_flags	flags;
	int		width;
	int		precision;
	char	type;
	t_arg	arg;
}				t_data;

typedef struct	s_list
{
	t_data			*data;
	struct s_list	*next;
}				t_list;

typedef struct	s_dispatch
{
	char	type;
	int		(*print)(t_data *);
}				t_dispatch;

int				ft_printf(const char *format, ...);

t_flags			get_flags(const char **format);
int				get_width(const char **format, va_list ap, t_data *data);
int				get_precision(const char **format, va_list ap);
void			get_arg(const char **format, va_list ap, t_data *data);
t_list			*analyze_format(const char *format, va_list ap);

t_list			*ft_lstnew(t_data *data);
t_list			*ft_lstlast(t_list *lst);
void			ft_lstadd_back(t_list **alst, t_list *new);
void			free_list(t_list **alst);

int				print_list(t_list *list);

int				ft_atoi(char *str);
int				ft_isspace(int c);
int				ft_isdigit(int c);

#endif
