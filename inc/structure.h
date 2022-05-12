/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structure.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngpar <youngseo321@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 18:18:51 by youngpar          #+#    #+#             */
/*   Updated: 2022/05/12 15:32:22 by dongkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURE_H
# define STRUCTURE_H

/*
 * Interface
 */

typedef int					t_bool;
typedef struct s_option		t_option;
typedef struct s_argument	t_argument;

typedef struct s_elem		t_elem;
typedef struct s_fd			t_fd;
typedef struct s_lst 		t_lst;

typedef struct s_glob		t_glob;

struct s_elem
{
	char	*data;
	int		type;
	int		subtype;
};

struct s_fd
{
	char	*file;
	int		type;
	int		subtype;
};

struct s_lst
{
	int				argc;
	char			**argv;
	int				fdc;
	struct s_fd		*fdv;
	struct s_lst	*next;
};

// 다 때려박 ㄱ
struct s_glob
{
	char	**env;
	int		env_len;
};

extern t_glob	g_val;

# endif
