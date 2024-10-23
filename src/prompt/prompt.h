/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasroman <gasroman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 17:34:04 by gasroman          #+#    #+#             */
/*   Updated: 2024/10/23 19:15:42 by gasroman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROMPT_H
# define PROMPT_H

# include <stdio.h>
# include <limits.h>
# include <stdlib.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "libft/libft.h"

# define FALSE					0
# define TRUE					1
# define ERROR				   -1
# define IN_FILE				0
# define OUT_FILE				1

# define CHILD					0

# define ERROR_CMD_NF			2
# define ERROR_MALLOC			3
# define ERROR_PATH				4
# define ERROR_FD				5
# define ERROR_CHILD			6
# define ERROR_NO_PRMT			7

# define EXIT_CMD_NOT_FOUND	  127
# define EXIT_CMD_ERROR		  126

# define NO_FILE 		"No such file or directory\n"
# define NO_PERMITS		"Permission denied\n"
# define NO_COMMAND		"Command not found\n"
# define NO_ARGUMENTS	"Invalid number of arguments\n"
# define NO_MEMORY 		"Error trying to allocate memory\n"
# define NO_PATH		"command not found\n"
# define NO_PIPE 		"Insert ERROR MESSAGE\n"
# define NO_CHILD 		"ABORT:\n"

typedef struct s_tree_node
{
	char				*content;
	int					type;
	struct s_tree_node	*parent;
	struct s_tree_node	**children;
	int					num_children;
}	t_tree_node;

//#-----pipex.c----#//
int	exec_promp(char **env);

//#-----init.c-----#//

//#-----aux.c------#//

#endif
