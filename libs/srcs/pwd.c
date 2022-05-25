/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngpar <youngseo321@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 18:42:47 by youngpar          #+#    #+#             */
/*   Updated: 2022/05/25 12:43:28 by dongkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

int	ft_pwd(void)
{
	char	*path;

	path = getcwd(0, 0);
	if (path == NULL)
	{
		ft_builtin_error(SHELL_NAME, "pwd", strerror(errno));
		return (1);
	}
	printf("%s\n", path);
	free(path);
	return (0);
}
