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
//                                  echo "hi" "hello" "sjanjan" >          file1 > file2 "mmmm"
typedef enum e_token_type
{
    TOKEN_WORD,
    TOKEN_PIPE,
    TOKEN_REDIRECT_IN,   // <
    TOKEN_REDIRECT_OUT,  // >
    TOKEN_REDIRECT_APPEND, // >>
    TOKEN_HEREDOC        // <<
} t_token_type;

// struct s_red
// {
//     char *filename;
//     int token;
// }   t_red;


// struct s_cmds
// {
//     char **args;
//     t_redirection *redirect;
//     int nun_of_redirect;
// } t_cmds;


typedef struct s_shell
{
    char *input;
    int num_cmd;
    // t_cmds *cmd;
} t_shell;

int handle_quotes(char *input);
int handle_all_errors(char *input);
int handle_pipes(char *input);
int handle_redirections(char *input);
int is_spacee(int c);

#endif