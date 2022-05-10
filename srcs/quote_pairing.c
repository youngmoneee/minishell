/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote_pairing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongkim <dongkim@student.42seoul.f>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 03:04:25 by dongkim           #+#    #+#             */
/*   Updated: 2022/05/11 00:53:10 by dongkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	cp_without_quote(char *dst, char *src)
{
	int		i;
	char	quot;

	i = 0;
	while (*src)
	{
		if (*src == '\'' || *src == '\"')
		{
			quot = *(src++);
			while (quot != *src)
				dst[i++] = *(src++);
		}
		else
			dst[i++] = *src;
		src++;
	}
	dst[i] = 0;
}

int	quote_pairing(t_elem *elems)
{
	char	*bef;
	char	*aft;
	int		i;

	printf("-> quote_paring\n");
	i = 0;
	while (elems[i].data)
	{
		bef = elems[i].data;
		aft = malloc(sizeof(char) * (ft_strlen(bef) + 1));
		if (aft == 0)
			return (1);
		cp_without_quote(aft, bef);
		elems[i].data = aft;
		free(bef);
		i++;
	}
	return (0);
}
