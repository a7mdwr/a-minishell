/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ahmad_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradwan <aradwan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 12:08:42 by aradwan           #+#    #+#             */
/*   Updated: 2025/09/05 16:22:26 by aradwan          ###   ########.fr       */
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


static void	increment(char *str, t_variables *vars)
{
	if (str[vars->i] == ' ')
	{
		if (!vars->space_found)
		{
			str[vars->j++] = ' ';
			vars->space_found = 1;
		}
	}
	else
	{
		str[vars->j++] = str[vars->i];
		vars->space_found = 0;
	}
}

void	replace_spaces_tabs(char *str)
{
	t_variables	vars;

	vars.i = 0;
	vars.j = 0;
	vars.space_found = 0;
	vars.quote_char = 0;
	while (str[vars.i] != '\0')
	{
		if (str[vars.i] == '"' || str[vars.i] == '\'')
		{
			if (vars.quote_char == 0)
				vars.quote_char = str[vars.i];
			else if (vars.quote_char == str[vars.i])
				vars.quote_char = 0;
			vars.space_found = 0;
			str[vars.j++] = str[vars.i];
		}
		else if (vars.quote_char == 0)
			increment(str, &vars);
		else
			str[vars.j++] = str[vars.i];
		vars.i++;
	}
	str[vars.j] = '\0';
}