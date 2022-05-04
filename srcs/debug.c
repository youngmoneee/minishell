/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongkim <dongkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 02:26:47 by dongkim           #+#    #+#             */
/*   Updated: 2022/05/05 02:36:07 by dongkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	debug_print_elems(t_elem *elems, int idx)
{
	int	i;

	if (idx < 0)
	{
		i = 0;
		while (elems[i].data != 0)
		{
			printf("%d)\tstr:%s\n\ttype:%d\n", i + 1,
				elems[i].data, elems[i].type);
			i++;
		}
	}
	else
	{
		i = idx;
		printf("%d)\tstr:%s\n\ttype:%d\n", i + 1, elems[i].data, elems[i].type);
	}
}
