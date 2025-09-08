/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmds.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradwan <aradwan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 17:36:21 by aradwan           #+#    #+#             */
/*   Updated: 2025/09/08 19:11:35 by aradwan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	store_the_file_name(char *str, char **file_name, int i, t_variables *var)
{
	int	start;
	int	in_quote;

	start = i;
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
		if ((str[i] == ' ' || str[i] == '\t') && !in_quote)
			break ;
		i++;
	}
	var->i = i;
	(*file_name) = ft_substr(str, start, i - start);
}


void	files_fillings(t_shell *pipe, t_cmds *cmds, t_variables *v)
{
	v->start = v->char_i - 1;
	if (pipe->cmds[v->cmd_i][v->char_i + 1] == '>' \
		|| pipe->cmds[v->cmd_i][v->char_i + 1] == '<')
	{
		if (pipe->cmds[v->cmd_i][v->char_i + 1] == '>')
			cmds[v->cmd_i].outs[v->xy].flag = APPEND;
		else if (pipe->cmds[v->cmd_i][v->char_i + 1] == '<')
			cmds[v->cmd_i].outs[v->xy].flag = HERE_DOC;
		v->char_i = v->char_i + 2;
	}
	else if (pipe->cmds[v->cmd_i][v->char_i] == '>')
	{
		cmds[v->cmd_i].outs[v->xy].flag = OUT_FILE;
		v->char_i++;
	}
	else if (pipe->cmds[v->cmd_i][v->char_i] == '<')
	{
		cmds[v->cmd_i].outs[v->xy].flag = IN_FILE;
		v->char_i++;
	}
}

void	utils_saving(t_shell *pipe, t_cmds *cmds, t_variables *v)
{
	v->xy = 0;
	v->char_i = -1;
	while (pipe->cmds[v->cmd_i][++v->char_i])
	{
		if (pipe->cmds[v->cmd_i][v->char_i] == '"' || pipe->cmds[v->cmd_i][v->char_i] == '\'')
		{
			if (v->quote_char == 0)
				v->quote_char = pipe->cmds[v->cmd_i][v->char_i];
			else if (v->quote_char == pipe->cmds[v->cmd_i][v->char_i])
				v->quote_char = 0;
		}
		if ((pipe->cmds[v->cmd_i][v->char_i] == '>' || \
			pipe->cmds[v->cmd_i][v->char_i] == '<') && !v->quote_char)
		{
			files_fillings(pipe, cmds, v);
			store_the_file_name(pipe->cmds[v->cmd_i], \
				&cmds[v->cmd_i].outs[v->xy].file_name, v->char_i + 1, v);
			clean_quotes(cmds[v->cmd_i].outs[v->xy].file_name);
			remove_substr(pipe->cmds[v->cmd_i], v->start, v->i);
			v->char_i = v->start - 1;
			v->xy++;
		}
	}
}

void	init_commands(t_shell *pipe, t_cmds **tmp)
{
	t_cmds	*cmds;
	t_variables	v;

	v.start = 0;
	v.quote_char = 0;
	v.arg_i = 0;
	v.cmd_i = -1;
	v.char_i = 0;
	*tmp = malloc(sizeof(t_cmds) * pipe->cmd_len);
	cmds = *tmp;
	cmds->red_len = 0;
	while (++v.cmd_i < pipe->cmd_len)
	{
		cmds[v.cmd_i].red_len = num_of_redirects(pipe->cmds[v.cmd_i]);
		if (cmds[v.cmd_i].red_len)
			cmds[v.cmd_i].outs = malloc(sizeof(t_redirect) * cmds[v.cmd_i].red_len);
		utils_saving(pipe, cmds, &v);
		cmds[v.cmd_i].cmds = ft_split(pipe->cmds[v.cmd_i], ' ');
		v.arg_i = 0;
		while (cmds[v.cmd_i].cmds[v.arg_i])
			clean_quotes(cmds[v.cmd_i].cmds[v.arg_i++]);
	}
}

