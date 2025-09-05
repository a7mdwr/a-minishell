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
# include <signal.h>
# include <errno.h>
#include <readline/readline.h>
#include <readline/history.h>
//                                  echo "hi" "hello" "sjanjan" >          file1 > file2 "mmmm"
extern int exit_code;
enum e_types
{
	IN_FILE,
	OUT_FILE,
	APPEND,
	HERE_DOC,
};

typedef struct s_redirect
{
	int		flag;
	char	*file_name;
}	t_redirect;

typedef struct s_cmds
{
	int			red_len;
	int			cmd_len;
	char		**cmds;
	t_redirect	*outs;
}	t_cmds;

typedef struct s_varibles
{
    int	i;
	int	j;
	int	h;
	int	empty;
	int	space_found;
	int	quote_char;
	int	x;
	int	start;
	int	len;
	int	xy;
	int	in_d_quotes;
	int	in_quotes;
} t_variables;

typedef struct s_shell
{
    int     cmd_len;
    int     num_cmd;
    t_list  *environment;
    int     environment_num;
    char    **cmds;
} t_shell;

void	files_saving(t_shell *pipe, t_cmds **tmp);
int		parsing(t_shell *pipe, t_cmds *cmds, char *input);
void    copy_env(t_shell *s, char **env);
char	*ft_add_spaces(char *input);
void	replace_spaces_tabs(char *str);
char	*my_getenv(const char *name, t_shell *pipe);
void	clean_quotes(char *str);
int		num_of_redirects(char *str);
void	remove_substr(char *s, unsigned int start, size_t len);
void	free_all(t_shell *pipe, t_cmds *cmd);
void	free_strings(char **av);
//            utils.c            \\.
int     spaces(char *str);
int     is_spacee(int c);

//            signals            \\.
void    handle_signals(int signal);

//            redirect           \\.
int     redirections_parse(char *str);

//             pipes             \\.
int	    handle_pipes(t_shell *pipe, char *input, t_cmds *cmds);


#endif