/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maudiffr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 12:14:29 by maudiffr          #+#    #+#             */
/*   Updated: 2023/05/26 12:29:31 by maudiffr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static	int	words(const char *str, char c)
{
	int	i;
	int	j;
	int	nb;

	i = 0;
	j = 0;
	nb = 0;
	while (str[i])
	{
		if ((str[i] == c && str[i + 1] != c && str[i + 1])
			|| (i == 0 && str[i] != c && str[0] != '\0'))
		{
			i++;
			j = 0;
			while (str[j + i] != c && str[j + i] != '\0')
				j++;
			nb++;
		}
		else
			i++;
	}
	return (nb);
}

static	char	*chain(const char *str, int start, int finish, char c)
{
	int		i;
	char	*tab;

	i = 0;
	tab = malloc(sizeof(char) * (finish - start + 1));
	if (tab == NULL)
		return (NULL);
	while (start < finish && str[start] != c)
	{
		tab[i] = str[start];
		i++;
		start++;
	}
	tab[i] = '\0';
	return (tab);
}

static	int	finish(const char *str, unsigned int start, char c)
{
	size_t	j;

	j = 0;
	while (str[j + start + 1] != c && str[j + start + 1] != '\0')
		j++;
	return (j);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	k;
	char	**tab;

	tab = malloc(sizeof(char *) * (words(s, c) + 1));
	if (tab == NULL)
		return (NULL);
	i = 0;
	j = 0;
	k = 0;
	while (s[i])
	{
		if (i == 0 && s[0] != c)
			tab[k++] = chain(s, i, finish(s, i, c) + 1, c);
		if (s[i] == c && s[i + 1] != c && s[i + 1] != '\0')
			tab[k++] = chain(s, i + 1, finish(s, i, c) + i + 1, c);
		i++;
	}
	if (k == 0 && s[0] != c && s[0] != '\0')
		tab[k++] = chain(s, j, ft_strlen(s), c);
	tab[k] = NULL;
	return (tab);
}
