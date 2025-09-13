/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ahmad_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradwan <aradwan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 12:08:42 by aradwan           #+#    #+#             */
/*   Updated: 2025/09/13 21:10:28 by aradwan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int spaces(char *str)
{
	int	i;

	i = 0;
	while (str[i] && (str[i] == ' ' || str[i] == '\t'))
		i++;
	if (str[i] == '\0')
		return (1);
	return (0);
}

int is_spacee(int c)
{
    return (c == ' ' || c == '\t' || c == '\n');
}


static void	increment(char *str, t_variables *v)
{
	if (str[v->i] == ' ')
	{
		if (!v->space_found)
		{
			str[v->indx++] = ' ';
			v->space_found = 1;
		}
	}
	else
	{
		str[v->indx++] = str[v->i];
		v->space_found = 0;
	}
}

void	replace_spaces_tabs(char *str)
{
	t_variables	v;

	v.i = 0;
	v.indx = 0;
	v.space_found = 0;
	v.quote_char = 0;
	while (str[v.i] != '\0')
	{
		quotes_check(&str, &v);
		if (v.quote_char == 0)
			increment(str, &v);
		else
			str[v.indx++] = str[v.i];
		v.i++;
	}
	str[v.indx] = '\0';
}

void	clean_quotes(char *str)
{
	int	i;
	int	j;
	int	quote;

	j = 0;
	i = 0;
	quote = 0;
	while (str[i])
	{
		if (str[i] == '\'' || str[i] == '\"')
		{
			if (!quote)
				quote = str[i];
			else if (quote == str[i])
				quote = 0;
			else
				str[j++] = str[i];
		}
		else
			str[j++] = str[i];
		i++;
	}
	str[j] = '\0';
}

int	num_of_redirects(char *str)
{
	int	i;
	int	num;
	t_variables v;

	i = 0;
	num = 0;
	v.i = 0;
	v.in_quotes = 0;
	v.in_d_quotes = 0;
	while (str[i])
	{
		quotes_check(&str, &v);
		if (!v.in_quotes && !v.in_d_quotes && (str[i] == '>' || str[i] == '<'))
		{
			if (str[i + 1] == '>' || str[i + 1] == '<')
				i++;
			num++;
		}
		i++;
		v.i = i;
	}
	return (num);
}

void	remove_substr(char *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (s[i])
	{
		if (i < start || i >= len)
		{
			s[j] = s[i];
			j++;
		}
		i++;
	}
	s[j] = '\0';
}
