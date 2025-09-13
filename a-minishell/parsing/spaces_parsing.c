/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spaces_parsing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradwan <aradwan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 14:31:19 by aradwan           #+#    #+#             */
/*   Updated: 2025/09/13 17:13:46 by aradwan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static void	add_space(int *j, char **new_str, int type)
{
	(*new_str)[(*j)++] = ' ';
	if (type == 0)
		(*new_str)[(*j)++] = '<';
	else if (type == 1)
	{
		(*new_str)[(*j)++] = '<';
		(*new_str)[(*j)++] = '<';
	}
	else if (type == 2)
		(*new_str)[(*j)++] = '>';
	else if (type == 3)
	{
		(*new_str)[(*j)++] = '>';
		(*new_str)[(*j)++] = '>';
	}
	else if (type == 4)
		(*new_str)[(*j)++] = ' ';
	(*new_str)[(*j)++] = ' ';
}

static void	add_spaces_helper(char **input, int *i, int *j, char **new_input)
{
	char c;
	char next;

	c = (*input)[*i];
	next = (*input)[*i + 1];
	if (c == '<' && next != '<')
		add_space(j, new_input, 0);
	else if (c == '<' && next == '<')
	{
		(*i)++;
		add_space(j, new_input, 1);
	}
	else if (c == '>' && c != '>')
		add_space(j, new_input, 2);
	else if (c == '>' && next == '>')
	{
		(*i)++;
		add_space(j, new_input, 3);
	}
	else if (c == '\t')
		add_space(j, new_input, 4);
	else
		(*new_input)[(*j)++] = c;
}

char	*ft_add_spaces(char *input)
{
	char	*new_input;
	int		i;
	int		j;
	t_variables v;

	i = -1;
	j = 0;
	v.i = 0;
	v.in_quotes = 0;
	v.in_d_quotes = 0;
	new_input = malloc(ft_strlen(input) * 3 + 2);
	while (input[++i])
	{
		v.i = i;
		quotes_check(&input, &v);
		if (!v.in_quotes && !v.in_d_quotes)
			add_spaces_helper(&input, &i, &j, &new_input);
		else
			new_input[j++] = input[i];
	}
	new_input[j] = '\0';
	free(input);
	return (new_input);
}
