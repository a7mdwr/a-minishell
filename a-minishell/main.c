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

int handle_all_errors(t_shell *s)
{
    if (!handle_quotes(s->input))
        return 0;
    if (!handle_pipe(s->input))
        return 0;
    return 1;
}

int handle_pipes(t_shell *s)
{
    int len;
    int i;

    i = 0;
    len = ft_strlen(s->input);
    if (!s->input)
        return 0;
    while (s->input[i])
    {
        if(s->input[0] == '\'' || s->input[len - 1])
    }
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
        if ((s->input[i] == '\'' || s->input[i] == '\''))
        {
            if (!quote)
                quote = s->input[i];
            
        }
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
        if (!handle_quotes(s.input))
            continue ;
        add_history(s.input);
    }
    return 0;
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