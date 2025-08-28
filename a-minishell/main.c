/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradwan <aradwan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 16:44:29 by aradwan           #+#    #+#             */
/*   Updated: 2025/08/15 21:17:36 by aradwan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int is_spacee(int c)
{
    return (c == ' ' || c == '\t' || c == '\n');
}

int handle_all_errors(t_shell *s)
{
    if (!handle_quotes(s))
        return 0;
    if (!handle_pipes(s))
        return 0;
    if (!handle_redirections(s))
        return 0;
    return 1;
}

int handle_pipes(t_shell *s)
{
    int i;

    i = 0;
    while (is_spacee(s->input[i]))
        i++;
    if (s->input[i] == '|')
        return 0;
    while (s->input[i])
    {
        if (s->input[i] == '|')
        {
            i++;
            while (is_spacee(s->input[i]))
                i++;
            if (s->input[i] == '\0' || s->input[i] == '|')
                return 0;
        }
        else 
            i++;
    }
    return 1;
}

int handle_quotes(t_shell *s)
{
    int i;
    int quote;
    
    if (!s->input)
        return 0;
    i = 0;
    quote = 0;
    while (s->input[i])
    {
        if ((s->input[i] == '\'' || s->input[i] == '\"'))
        {
            if (!quote)
                quote = s->input[i];
            else if (quote == s->input[i])
                quote = 0;
        }
        i++;
    }
    if (quote != 0)
        return 0;
    return 1;
}

int handle_redirections(t_shell *s)
{
    int i;
    int redirections_num;
    char c;

    redirections_num = 0;
    i = 0;
    while (s->input[i])
    {
        if (s->input[i] == '<' || s->input[i] == '>')
        {
            c = s->input[i];
            redirections_num = 0;
            while (s->input[i] == c)
            {
                redirections_num++;
                i++;
            }
            if (redirections_num > 2)
                return 0;
            while (is_spacee(s->input[i]))
                i++;
            if (s->input[i] == '\0'
				|| s->input[i] == '|'
				|| s->input[i] == '<'
				|| s->input[i] == '>')
				return (0);
        }
        else
            i++;
    }
    return 1;
}

void	clean_quotes(char *str)
{
	int	i;
	int	quote;

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
		}
		i++;
	}
}

int main(int ac, char **av)
{
    t_shell s;
    (void)ac;
    (void)av;
    
    while (1)
    {
        s.input = readline("minishell >");
        if (!s.input)
            break ;
        if (!handle_all_errors(&s))
        {
            printf("minishell: syntax error\n");
            free(s.input);
            continue;
        }
        add_history(s.input);
    }
    return 0;
}
