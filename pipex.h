/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maudiffr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 11:50:35 by maudiffr          #+#    #+#             */
/*   Updated: 2023/06/26 10:14:11 by maudiffr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <fcntl.h>

void	ft_putstr(char *str);
size_t	ft_strlen(const char *s);
char	*get_path(char **envp);
char	*ft_strjoin(char const *s1, char const *s2);
void	ft_exit2(int error);
void	ft_free(char **tab);
char	**ft_split(char const *s, char c);

#endif
