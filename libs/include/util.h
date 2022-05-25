/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongkim <dongkim@student.42seoul.f>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 12:39:47 by dongkim           #+#    #+#             */
/*   Updated: 2022/05/25 13:45:38 by dongkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTIL_H
# define UTIL_H

# include "../../inc/structure.h"
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>

void	*ft_realloc(void *ptr, int befsize, int aftsize, int is_rec);
int		ft_strlen(const char *str);
void	ft_strncpy(char *dst, const char *src, int len);
char	*ft_replace(char *str, int idx, char *insert, int cutlen);
int		ft_strcmp(const char *s1, const char *s2);
char	**ft_split(char const *s, char c);
char	*ft_strdup(const char *s1);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtjoin(char const *s1, char const *s2, char const *s3);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
int		ft_atoi(const char *str);
char	*ft_itoa(int num);

void	ft_lowercase(char *str);

void	*clean_elem(t_elem *elems, int cnt);
void	*clean_dchar(char **dchar, int cnt);
void	*clean_fdv(t_fd *fdv, int fdc);
int		get_quote_len(const char *str);

void	ft_putstr_fd(int fd, const char *str);
int		ft_builtin_error(const char *cmd, const char *arg, const char *msg);
int		ft_builtin_error4(const char *pgname, const char *cmd,
			const char *arg, const char *msg);
int		ft_builtin_error_tok4(const char *pgname, const char *cmd,
			const char *tok, const char *msg);
int		ft_parsing_error(const char *cmd, const char *msg, const char *tok);

#endif
