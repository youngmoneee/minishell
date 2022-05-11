/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngpar <youngseo321@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 17:23:52 by youngpar          #+#    #+#             */
/*   Updated: 2022/05/11 18:50:00 by youngpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/echo.h"

t_bool	parse_option(const char *str)
{
	int	idx;
	int	ret;

	ret = 0;
	idx = 0;
	if (str[idx++] != '-')
		return (0);
	while (str[idx]) {
		if (str[idx] == 'n')
			idx += 1;
	}
	return (ret);
}

int	echo(int argc, char *argv[])
{
	int	idx;

	idx = -1;
	if (argv[0][0] == '-' && argv[0][1] == 'n' && !argv[0][2])
	{
		idx = 0;
		while (++idx < argc)
			if (idx == argc - 1)
				printf("%s", argv[idx]);
			else
				printf("%s ", argv[idx]);
	}
	else
	{
		while (++idx < argc)
			if (idx == argc - 1)
				printf("%s", argv[idx]);
			else
				printf("%s ", argv[idx]);
		printf("\n");
	}
	return (0);
}
