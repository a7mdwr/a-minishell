/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradwan <aradwan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 16:18:39 by aradwan           #+#    #+#             */
/*   Updated: 2025/08/15 20:16:07 by aradwan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <pthread.h>
# include <unistd.h>
# include <stdio.h>
# include "libft/libft.h"
# include <time.h>
# include <sys/time.h>
# include <string.h>
# include <limits.h>
# include <stdlib.h> 
# include <stdbool.h>
# include <errno.h>
#include <readline/readline.h>
#include <readline/history.h>

typedef struct s_shell
{
    char *input;
} t_shell;

int handle_quotes(char *input);
int handle_all_errors(char *input);
int handle_pipes(char *input);

#endif