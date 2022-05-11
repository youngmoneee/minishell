/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elems_to_lst.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongkim <dongkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 22:19:34 by dongkim           #+#    #+#             */
/*   Updated: 2022/05/11 18:28:16 by dongkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	sub_new_node(t_fd **to, t_elem *from)
{
	to[0]->type = from->type;
	to[0]->subtype = from->subtype;
	to[0]->file_name = from->data;
}

static t_lst	*new_node(int pipe_idx, t_elem *elems)
{
	t_lst	*ret;

	ret = ft_realloc(0, 0, sizeof(t_lst), 0);
	if (ret == 0)
		return (0);
	while (ret->fdc + ret->argc < pipe_idx)
	{
		if (elems[ret->fdc + ret->argc].type != ET_STR)
		{
			ret->fdv = ft_realloc(ret->fdv, ret->fdc, ret->fdc + 1, 1);
			if (ret->fdv == 0)
				return (0);
			free(elems[ret->fdc + ret->argc].data);
			ret->fdv[ret->fdc].type = elems[ret->fdc + ret->argc].type;
			ret->fdv[ret->fdc].subtype = elems[ret->fdc + ret->argc].subtype;
			ret->fdv[ret->fdc].file_name = elems[ret->fdc + ret->argc + 1].data;
			ret->fdc += 2;
		}
		else
		{
			ret->argv = ft_realloc(ret->argv, ret->argc, ret->argc + 1, 1);
			if (ret->argv == 0)
				return (0);
			ret->argv[ret->argc] = elems[ret->fdc + ret->argc].data;
			ret->argc++;
		}
	}
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
	int		i;
	int		pipe_idx;
	t_lst	*head;

	i = 0;
	head = 0;
	while (elems[i].data)
	{
		pipe_idx = 0;
		while (elems[i + pipe_idx].data && elems[i + pipe_idx].type == ET_PIP)
			pipe_idx++;

		if (add_node_back(&head, new_node(argc, &elems[i], type)) == 0)
		{
			while (del_node_front(&head, 1))
				;
			return (1);
		}

		i += pipe_idx;	
	}
	free(elems);
	*lst = head;
	return (0);
}
