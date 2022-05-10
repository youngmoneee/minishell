/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongkim <dongkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 02:26:47 by dongkim           #+#    #+#             */
/*   Updated: 2022/05/11 01:11:28 by dongkim          ###   ########.fr       */
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

void	print_node(t_lst *node)
{
	int	i;

	i = 0;
	printf("int argc:\t%d\n", node->argc);
	printf("char** argv:\t%p\n", node->argv);
	while (node->argv[i])
	{
		printf(" -> [%s]\n", node->argv[i]);
		i++;
	}
	printf("type:\t\t%d\n", node->type);
	printf("next:\t\t%p\n", node->next);
	printf("\n");
}

void	debug_print_lst(t_lst *lst, int idx)
{
	int	i;

	i = 0;
	while (lst)
	{
		if (idx < 0 || idx == i)
			print_node(lst);
		i++;
		lst = lst->next;
	}
}
