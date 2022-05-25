/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongkim <dongkim@student.42seoul.f>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 12:40:08 by dongkim           #+#    #+#             */
/*   Updated: 2022/05/25 12:40:09 by dongkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_H
# define ENV_H

# include "../../inc/structure.h"

char	**deep_copy(char **arr);
char	**shallow_copy(char **arr);
char	*pointer_of(const char *key, char **env);
int		index_of(const char *key, char **env);

char	*ft_getenv(const char *key, char **env);
t_bool	ft_setenv(const char *key_value, char ***env);
t_bool	ft_putenv(const char *key_value, char ***env);
t_bool	ft_rmenv(const char *key, char ***env);

t_bool	ft_env(char **env);
t_bool	ft_export(int argc, char **argv, char ***env);
t_bool	ft_unset(int argc, char **argv, char ***env);

#endif
