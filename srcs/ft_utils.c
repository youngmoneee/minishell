/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongkim <dongkim@student.42seoul.f>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 03:04:17 by dongkim           #+#    #+#             */
/*   Updated: 2022/05/04 05:44:14 by dongkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_realloc(char *ptr, int befsize, int aftsize)
{
	char	*ret;
	int		i;

	ret = malloc(aftsize);
	if (ret)
	{
		i = 0;
		while (ptr && i < befsize)
		{
			ret[i] = ptr[i];
			i++;
		}
		while (i < aftsize)
			ret[i++] = 0;
		if (ptr)
			free(ptr);
	}
	return (ret);
}

int	ft_strlen(const char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

void	ft_strncpy(char *dst, const char *src, int len)
{
	int	i;

	i = 0;
	while (src[i] && i < len)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = 0;
}

char	*ft_strinsert(char *str, int idx, char *insert, int cutlen)
{
	int		insert_len;
	int		str_len;
	char	*ret;

	insert_len = ft_strlen(insert);
	str_len = ft_strlen(str);
	ret = malloc(sizeof(char) * (str_len + insert_len + 1));
	if (ret == 0)
		return (0);
	ft_strncpy(ret, str, idx);
	ft_strncpy(&ret[idx], insert, insert_len);
	ft_strncpy(&ret[idx + insert_len + cutlen], &str[idx], str_len - idx);
	return (ret);
}

void	*clean_elem(t_elem *elems)
{
	int	i;

	if (elems)
	{
		i = 0;
		while (elems[i].data)
		{
			free(elems[i].data);
			i++;
		}
		free(elems);
	}
	return (0);
}
