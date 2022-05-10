/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elems_to_lst.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongkim <dongkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 22:19:34 by dongkim           #+#    #+#             */
/*   Updated: 2022/05/10 22:43:24 by dongkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_lst	*new_node(int argc, t_elem *elems, int type)
{
	t_lst	*ret;
	int		i;

	ret = malloc(sizeof(t_lst));
	if (ret == 0)
		return (0);
	ret->argv = malloc(sizeof(char *) * (argc + 1));
	if (ret->argv == 0)
	{
		free(ret);
		return (0);
	}
	t_lst->argc = argc;
	t_lst->type = type;
	t_lst->next = 0;
	i = 0;
	while (i < argc)
	{
		ret->argv[i] = elems[i].data;
		i++;
	}
	ret->argv[i] = 0;
	return (ret);
}

void	add_node_back(t_lst **head, t_lst *node)
{
	t_lst	*tmp;

	if (*head)
	{
		tmp = *head;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = node;
	}
	else
		*head = node;
}

void	del_node_front(t_lst **head)
{
	t_lst	*tmp;

	if (*head)
	{
		tmp = *head;
		*head = (*head)->next;
		clean_dchar(tmp->argv, tmp->argc);
		free(tmp);
	}
}

t_lst	*elems_to_lst(t_elem *elems)
{
	
}
