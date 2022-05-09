/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongkim <dongkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 10:16:15 by dongkim           #+#    #+#             */
/*   Updated: 2022/05/09 10:16:18 by dongkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	*clean_dchar(char **dchar, int cnt)
{
	int	i;

	if (dchar)
	{
		i = 0;
		while (i < cnt)
		{
			free(dchar[i]);
			i++;
		}
		free(dchar);
	}
	return (0);
}

void	*clean_elem(t_elem *elems, int cnt)
{
	int	i;

	if (elems)
	{
		i = 0;
		while (i < cnt)
		{
			free(elems[i].data);
			i++;
		}
		free(elems);
	}
	return (0);
}
