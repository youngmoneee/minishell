/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngpar <youngseo321@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 18:06:53 by youngpar          #+#    #+#             */
/*   Updated: 2022/04/26 18:37:31 by youngpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ECHO_H
# define ECHO_H

# include <stdio.h>
# include "../../inc/structure.h"

struct s_option
{
	t_bool	n;
};

struct s_argument
{
	t_option	option;
	t_elem		elem;
};


/*
 *	Interface
 */

t_bool	echo(t_argument *arg);
t_bool	parse_option(const char *str);
#endif
