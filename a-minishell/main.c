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

int check_last(char *input)
{
    int len;

    len = ft_strlen(input);
    while (is_spacee(input[len]))
        len--;
    if (input[len] == '\0'|| input[len] == '|' || input[len] == '<' || input[len] == '>')
		return (0);
    return 1;
}

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

int in_quotes(char *str, int index)
{
    int i;
    char quote;

    i = 0;
    while (i < index && str[i])
    {
        if (str[i] == '\'' || str[i] == '\"')
            quote = str[i];
        else if (quote == str[i])
            quote = 0;
    }
    if (quote != 0)
        return 1;
    else
        return 0;
}

int handle_all_errors(char *input)
{
    if (spaces(input))
        return 0;
    if (!handle_quotes(input))
        return 0;
    if (!handle_pipes(input))
        return 0;
    if (!handle_redirections(input))
        return 0;
    return 1;
}

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

int handle_redirections(char *input)
{
    int i;
    int redirections_num;
    char c;

    redirections_num = 0;
    i = 0;
    while (input[i])
    {
        if ((input[i] == '<' || input[i] == '>') && !in_quotes(input, i))
        {
            c = input[i];
            redirections_num = 0;
            while (input[i] == c)
            {
                redirections_num++;
                i++;
            }
            if (redirections_num > 2)
                return 0;
            while (is_spacee(input[i]))
                i++;
            if(check_last(input))
                return 0;
        }
        else
            i++;
    }
    return 1;
}

// void	clean_quotes(char *inputtr)
// {
// 	int	i;
// 	int	quote;

// 	i = 0;
// 	quote = 0;
// 	while (str[i])
// 	{
// 		if (str[i] == '\'' || str[i] == '\"')
// 		{
// 			if (!quote)
// 				quote = str[i];
// 			else if (quote == str[i])
// 				quote = 0;
// 		}
// 		i++;
// 	}
// }

int main(int ac, char **av, char **env)
{
    char *input;
    t_shell s;
    (void)av;
    if (ac != 1)
        return (0);
    copy_env(&s, env);
    while (1)
    {
        signal(SIGINT, handle_signals);
        signal(SIGQUIT, SIG_IGN);
        input = readline("minishell >");
        if (!input)
            return (printf("exit\n"), 0);
        add_history(input);
        if (!handle_all_errors(input))
        {
            printf("minishell: syntax error\n");
            continue;
        }
    }
    return 0;
}
