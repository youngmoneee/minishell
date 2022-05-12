/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elems_to_lst.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongkim <dongkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 22:19:34 by dongkim           #+#    #+#             */
/*   Updated: 2022/05/12 16:46:54 by dongkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_lst	*free_and_retz(t_lst *ret)
{
	free(ret);
	return (0);
}

static t_lst	*new_node(t_lst *ret, int pipe_idx, t_elem *e)
{
	ret = ft_realloc(ret, 0, sizeof(t_lst), 0);
	while (ret && ret->fdc * 2 + ret->argc < pipe_idx)
	{
		if (e[ret->fdc * 2 + ret->argc].type != ET_STR)
		{
			ret->fdv = ft_realloc(ret->fdv, sizeof(t_fd) * (ret->fdc + 1),
					sizeof(t_fd) * (ret->fdc + 2), 1);
			if (ret->fdv == 0)
				return (free_and_retz(ret));
			free(e[ret->fdc * 2 + ret->argc].data);
			e[ret->fdc * 2 + ret->argc].data = 0;
			ret->fdv[ret->fdc].type = e[ret->fdc * 2 + ret->argc].type;
			ret->fdv[ret->fdc].subtype = e[ret->fdc * 2 + ret->argc].subtype;
			ret->fdv[ret->fdc++].file = e[ret->fdc * 2 + ret->argc + 1].data;
		}
		else
		{
			ret->argv = ft_realloc(ret->argv, sizeof(char *) * (ret->argc + 1),
					sizeof(char *) * (ret->argc + 2), 1);
			if (ret->argv == 0)
				return (free_and_retz(ret));
			ret->argv[ret->argc++] = e[(ret->fdc * 2) + ret->argc].data;
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
		{
			clean_dchar(tmp->argv, tmp->argc);
			free(tmp->fdv);
		}
		else if (is_deep_clean == 1)
		{
			free(tmp->argv);
			free(tmp->fdv);
		}
		free(tmp);
		return (1);
	}
	return (0);
}

int	elems_to_lst(t_elem *elems, int elem_cnt, t_lst **lst)
{
	int		i;
	int		pipe_idx;

	i = 0;
	printf("-> elems_to_lst\n");
	while (i < elem_cnt)
	{
		pipe_idx = 0;
		while (i + pipe_idx < elem_cnt && elems[i + pipe_idx].type != ET_PIP)
			pipe_idx++;
		if (add_node_back(lst, new_node(0, pipe_idx, &elems[i])) == 0)
		{
			while (del_node_front(lst, 1))
				;
			return (1);
		}
		i += pipe_idx;
		if (elems[i].type == ET_PIP)
		{
			free(elems[i].data);
			elems[i++].data = 0;
		}
	}
	free(elems);
	return (0);
}
