/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasroman <gasroman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 07:29:29 by gasroman          #+#    #+#             */
/*   Updated: 2024/10/22 18:30:48 by gasroman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

typedef enum e_node_type
{
	CMD_TYPE = 1 << 0,		// Nodo que representa un comando
	ARG_TYPE = 1 << 1,		// Nodo que representa un argumento
	PIPE_TYPE = 1 << 2,		// Nodo que representa un pipe '|'
	REDIR_TYPE = 1 << 3,	// Nodo que representa una redirección '>' o '<'
	FILE_TYPE = 1 << 4,		// Nodo que representa un archivo
}	t_node_type;

typedef struct s_tree_node
{
	char				*content;
	int					type;
	struct s_tree_node	*parent;
	struct s_tree_node	**children;
	int					num_children;
	int					capacity;
}	t_tree_node;
