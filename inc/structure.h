/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structure.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngpar <youngseo321@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 18:18:51 by youngpar          #+#    #+#             */
/*   Updated: 2022/05/04 04:11:25 by dongkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURE_H
# define STRUCTURE_H

/*
 * Interface
 */

typedef int					t_bool;
typedef struct s_argument 	t_argument;
typedef struct s_option		t_option;
typedef struct s_elem		t_elem;

struct	s_elem {
	char	*data;
	int		type;
};

# endif
