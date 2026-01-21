/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpeixoto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 13:01:18 by gpeixoto          #+#    #+#             */
/*   Updated: 2026/01/16 17:45:55 by gpeixoto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	count_words(char *str, char c)
{
	int	count;
	int	check;
	int	i;

	count = 0;
	check = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			check = 0;
		else if (!check)
		{
			count++;
			check = 1;
		}
		i++;
	}
	return (count);
}

static char	*get_next_word(char *str, char c)
{
	static int	place = 0;
	char		*next_word;
	int			len;
	int			i;

	len = 0;
	i = 0;
	while (str[place] == c)
		place++;
	while ((str[place + len] != c) && str[place + len])
		len++;
	next_word = malloc((size_t)len * sizeof(char) + 1);
	if (!next_word)
		return (NULL);
	while ((str[place] != c) && str[place])
		next_word[i++] = str[place++];
	next_word[i] = '\0';
	return (next_word);
}

/*static void	*free_all(char **args)
{
	int	i;

	i = 0;
	while (args[i])
	{
		free(args[i]);
		i++;
	}
	free(args);
	return (NULL);
}

static char	**fill_arr(char *str, char c, char **args, int words)
{
	int	i;

	i = 0;
	if (!args)
		return (NULL);
	while (words-- >= 0)
	{
		if (i == 0)
		{
			args[i] = malloc(sizeof(char));
			if (!args[i])
				return (NULL);
			args[i][0] = '\0';
		}
		else
			args[i] = get_next_word(str, c);
		if (!args[i])
			return (free_all(args));
		i++;
	}
	args[i] = NULL;
	return (args);
}

char	**ft_split(char *str, char c)
{
	int	words;
	char	**args;

	words = count_words(str, c);
	if (!words)
		return (NULL);
	args = malloc(sizeof(char *) * (words + 2));
	if (!args)
		return (NULL);
	return (fill_arr(str, c, args, words));
}*/

char	**ft_split(char *str, char c)
{
	int		words;
	char	**args;
	int		i;

	words = count_words(str, c);
	if (!words)
		return (NULL);
	args = malloc(sizeof(char *) * (words + 2));
	if (!args)
		return (NULL);
	i = 0;
	while (words-- >= 0)
	{
		if (i == 0)
		{
			args[i] = malloc(sizeof(char));
			if (!args[i])
				return (NULL);
			args[i++][0] = '\0';
			continue ;
		}
		args[i++] = get_next_word(str, c);
	}
	args[i] = NULL;
	return (args);
}
