/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngpar <youngseo321@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 17:23:52 by youngpar          #+#    #+#             */
/*   Updated: 2022/04/26 18:36:47 by youngpar         ###   ########.fr       */
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

//	echo가 str 리턴하고 쉘에서 리다이렉션 없으면 출력? 문자열을 인자로 다음 오퍼레이션한테?
t_bool	echo(t_argument *arg)
{
	if (arg || !arg)
		printf("Echo test\n");
	return (0);
}
