/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structure.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngpar <youngseo321@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 18:18:51 by youngpar          #+#    #+#             */
/*   Updated: 2022/05/10 00:49:20 by dongkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURE_H
# define STRUCTURE_H

/*
 * Interface
 */

typedef int					t_bool;
typedef struct s_option		t_option;
typedef struct s_arg 		t_arg;
typedef struct s_elem		t_elem;

typedef struct s_glob		t_glob;

struct s_elem
{
	char	*data;
	int		type;
};

struct s_arg
{
	int				argc;
	char			**argv;
	int				type;
	struct s_arg	*next;
};

// 다 때려박 ㄱ
struct s_glob
{
	char	**env;
};

extern t_glob	g_val;

# endif
