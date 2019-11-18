/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_split.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: nschat <nschat@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/28 18:16:28 by nschat        #+#    #+#                 */
/*   Updated: 2019/11/17 15:45:42 by nschat        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static size_t	ft_arr_size(char const *s, char c)
{
	size_t size;

	size = 0;
	while (*s)
	{
		if (*s != c && (s[1] == c || s[1] == '\0'))
			size++;
		s++;
	}
	return (size);
}

static size_t	ft_split_size(char const *s, char c)
{
	char	*delim;

	delim = ft_strchr(s, c);
	if (delim == NULL)
		delim = (char *)s + ft_strlen(s);
	return (delim - s);
}

static void		ft_free_arr(char **arr, size_t i)
{
	while (i)
	{
		i--;
		free(arr[i]);
	}
	free(arr);
}

static void		ft_split_str(char **arr, const char *s, char c, size_t i)
{
	size_t	split_size;

	if (*s == '\0')
	{
		arr[i] = NULL;
		return ;
	}
	if (*s == c)
		return (ft_split_str(arr, s + 1, c, i));
	split_size = ft_split_size(s, c);
	arr[i] = ft_substr(s, 0, split_size);
	if (arr[i] == NULL)
		return (ft_free_arr(arr, i));
	ft_split_str(arr, s + split_size, c, i + 1);
}

char			**ft_split(char const *s, char c)
{
	char		**arr;
	size_t		size;

	if (s == NULL)
		return (NULL);
	size = ft_arr_size(s, c);
	arr = (char **)malloc(sizeof(char *) * (size + 1));
	if (arr == NULL)
		return (NULL);
	ft_split_str(arr, s, c, 0);
	return (arr);
}
