/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradwan <aradwan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 09:32:56 by aradwan           #+#    #+#             */
/*   Updated: 2024/12/17 09:32:56 by aradwan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	word_len(const char *s, char c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

char	*copy_string(char *str, const char *s, char c)
{
	int	i;

	i = 0;
	if (!s || !str)
		return (NULL);
	while (s[i] && s[i] != c)
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

void	skip_sep(const char *s, char c, t_split *split)
{
	while (s[split->i] && s[split->i] == c)
		split->i++;
	while (s[split->i])
	{
		while (s[split->i] && s[split->i] == c)
			split->i++;
		if (s[split->i] && s[split->i] != c)
		{
			split->words++;
			while (s[split->i] && s[split->i] != c)
				split->i++;
		}
		if (s[split->i])
			split->i++;
	}
}

char	**ft_split_helper(t_split *split, char **str, char c, const char *s)
{
	while (split->j < split->words)
	{
		while (s[split->i] && s[split->i] == c)
			split->i++;
		str[split->j] = malloc(sizeof(char) * (word_len(&s[split->i], c) + 1));
		if (!str)
		{
			while (split->j > 0)
				free (str[split->j--]);
			free (str);
			return (NULL);
		}
		copy_string(str[split->j], &s[split->i], c);
		while (s[split->i] && s[split->i] != c)
			split->i++;
		split->j++;
	}
	str[split->j] = NULL;
	return (str);
}

char	**ft_split(char const *s, char c)
{
	char	**str;
	t_split	split;

	split.words = 0;
	split.i = 0;
	split.j = 0;
	if (!s)
		return (NULL);
	skip_sep(s, c, &split);
	str = malloc(sizeof(char *) * (split.words + 1));
	if (!str)
		return (NULL);
	split.i = 0;
	if (ft_split_helper(&split, str, c, s) == NULL)
		return (NULL);
	return (str);
}

int main()
{
    char **str;
    str = ft_split(NULL, ' ');
    int i = 0;
    while (str[i] != NULL)
        printf("%s\n", str[i++]);
}