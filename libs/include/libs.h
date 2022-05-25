/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libs.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngpar <youngseo321@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 18:07:20 by youngpar          #+#    #+#             */
/*   Updated: 2022/05/25 14:30:20 by dongkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBS_H
# define LIBS_H

# include "pwd.h"
# include "util.h"
# include "env.h"

int	ft_cd(int argc, char **argv, char ***env);
int	ft_echo(int argc, char *argv[]);
int	ft_exit(const int argc, char **argv, t_stat *stat);

#endif
