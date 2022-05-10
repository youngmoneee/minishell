/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elems_to_lst.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongkim <dongkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 22:19:34 by dongkim           #+#    #+#             */
/*   Updated: 2022/05/11 06:50:50 by dongkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_lst	*new_node(int argc, t_elem *elems, int type)
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
	ret->argc = argc;
	ret->type = type;
	ret->next = 0;
	i = 0;
	while (i < argc)
	{
		ret->argv[i] = elems[i].data;
		i++;
	}
	ret->argv[i] = 0;
	return (ret);
}

static int	add_node_back(t_lst **head, t_lst *node)
{
	t_lst	*tmp;

	if (node == 0)
		return (0);
	if (*head)
	{
		tmp = *head;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = node;
	}
	else
		*head = node;
	return (1);
}

int	del_node_front(t_lst **head, int is_deep_clean)
{
	t_lst	*tmp;

	if (*head)
	{
		tmp = *head;
		*head = (*head)->next;
		if (is_deep_clean == 2)
			clean_dchar(tmp->argv, tmp->argc);
		else if (is_deep_clean == 1)
			free(tmp->argv);
		free(tmp);
		return (1);
	}
	return (0);
}

int	elems_to_lst(t_elem *elems, t_lst **lst)
{
	int		argc;
	int		i;
	int		type;
	t_lst	*head;

	printf("-> elems_to_lst\n");
	i = 0;
	head = 0;
	while (elems[i].data)
	{
		type = elems[i].type;
		argc = 0;
		while (elems[i + argc].data && type == elems[i + argc].type)
			argc++;
		if (add_node_back(&head, new_node(argc, &elems[i], type)) == 0)
		{
			while (del_node_front(&head, 1))
				;
			return (1);
		}
		i += argc;	
	}
	free(elems);
	*lst = head;
	return (0);
}
