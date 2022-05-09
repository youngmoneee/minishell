/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_to_lst.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongkim <dongkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 00:57:44 by dongkim           #+#    #+#             */
/*   Updated: 2022/05/10 00:57:45 by dongkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_arg	*new_arg_node(int argc, t_elem *elems, int type)
{
	t_arg	*ret;
	int		i;

	ret = malloc(sizeof(t_arg));
	if (ret == 0)
		return (0);
	ret->argv = malloc(sizeof(char *) * (argc + 1));
	if (ret->argv == 0)
	{
		free(ret);
		return (0);
	}
	t_arg->argc = argc;
	t_arg->type = type;
	t_arg->next = 0;
	i = 0;
	while (i < argc)
	{
		ret->argv[i] = elems[i].data;
		i++;
	}
	ret->argv[i] = 0;
	return (ret);
}
