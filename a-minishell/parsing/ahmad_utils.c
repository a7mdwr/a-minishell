/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ahmad_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradwan <aradwan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 12:08:42 by aradwan           #+#    #+#             */
/*   Updated: 2025/09/05 12:23:35 by aradwan          ###   ########.fr       */
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