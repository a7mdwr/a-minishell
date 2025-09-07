/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ahmad_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradwan <aradwan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 12:08:42 by aradwan           #+#    #+#             */
/*   Updated: 2025/09/06 15:42:29 by aradwan          ###   ########.fr       */
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
		if (str[v.i] == '"' || str[v.i] == '\'')
		{
			if (v.quote_char == 0)
				v.quote_char = str[v.i];
			else if (v.quote_char == str[v.i])
				v.quote_char = 0;
			v.space_found = 0;
			str[v.indx++] = str[v.i];
		}
		else if (v.quote_char == 0)
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
	int	in_quote;

	i = 0;
	num = 0;
	in_quote = 0;
	while (str[i])
	{
		if (str[i] == '\'' || str[i] == '\"')
		{
			if (!in_quote)
				in_quote = str[i];
			else if (in_quote == str[i])
				in_quote = 0;
		}
		else if (!in_quote && (str[i] == '>' || str[i] == '<'))
		{
			if (str[i + 1] == '>' || str[i + 1] == '<')
				i++;
			num++;
		}
		i++;
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

// echo "'jsdnbjkdsnbkjsnkjs'"