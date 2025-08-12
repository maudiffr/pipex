/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maudiffr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 10:27:27 by maudiffr          #+#    #+#             */
/*   Updated: 2023/06/26 10:43:29 by maudiffr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_exit2(int error)
{
	if (error == 1)
	{
		ft_putstr("Error: Invalid numbers of arguments.\n");
		ft_putstr("Example: ./pipex file1 cmd1 cmd2 file2\n");
		exit (1);
	}
	if (error == 7)
	{
		ft_putstr("Error with input commands (Empty).\n");
		exit (7);
	}
}

void	ft_free(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}
