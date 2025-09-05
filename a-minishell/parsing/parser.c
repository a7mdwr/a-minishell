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

#include "../minishell.h"

int exit_code = 0;

int	ms_main_helper(t_shell *pipe, t_cmds *cmds, char *input)
{
	if (spaces(input))
		return (1);
	if (!redirections_parse(input))
	{
		printf("syntax error, unexpected redirection token\n");
		add_history(input);
		exit_code = 258;
		return (1);
	}
	else if (!check_pipes(pipe, read, cmds))
	{
		printf("Error\n");
		add_history(read);
		exit_code = 258;
		return (1);
	}
	return (0);
}




///////////////////////////////////////////////////////////////////



















int handle_pipes(char *input)
{
    int i;

    i = 0;
    while (is_spacee(input[i]))
        i++;
    if (input[i] == '|')
        return 0;
    while (input[i])
    {
        if (input[i] == '|' && !in_quotes(input, i))
        {
            i++;
            while (is_spacee(input[i]))
                i++;
            if (input[i] == '\0' || input[i] == '|')
                return 0;
        }
        else 
            i++;
    }
    return 1;
}

int handle_quotes(char *input)
{
    int i;
    int quote;
    
    if (!input)
        return 0;
    i = 0;
    quote = 0;
    while (input[i])
    {
        if ((input[i] == '\'' || input[i] == '\"'))
        {
            if (!quote)
                quote = input[i];
            else if (quote == input[i])
                quote = 0;
        }
        i++;
    }
    if (quote != 0)
        return 0;
    return 1;
}

