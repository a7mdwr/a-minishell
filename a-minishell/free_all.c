/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradwan <aradwan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 17:48:45 by aradwan           #+#    #+#             */
/*   Updated: 2025/09/05 17:49:02 by aradwan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_strings(char **av)
{
	int	i;

	i = 0;
	while (av[i])
	{
		free(av[i]);
		i++;
	}
	free(av);
}

void	free_all(t_shell *pipe, t_cmds *cmd)
{
	int	i;
	int	j;

	i = -1;
	j = -1;
	while (++i < pipe->cmd_len)
	{
		j = -1;
		if (cmd[i].red_len > 0)
		{
			while (++j < cmd[i].red_len)
			{
				if (cmd[i].outs[j].file_name)
					free(cmd[i].outs[j].file_name);
			}
			if (cmd[i].outs)
				free(cmd[i].outs);
		}
		free_strings(cmd[i].cmds);
	}
	free_strings(pipe->cmds);
	free(cmd);
}