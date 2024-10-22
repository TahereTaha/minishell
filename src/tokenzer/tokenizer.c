/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasroman <gasroman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 07:40:13 by gasroman          #+#    #+#             */
/*   Updated: 2024/10/22 18:36:51 by gasroman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "token.h"

t_tree_node	*create_node(char *content, int type)
{
	t_tree_node	*new_node;

	new_node = (t_tree_node *)malloc(sizeof(t_tree_node));
	if (!new_node)
		return (NULL);
	new_node->content = strdup(content);
	new_node->type = type;
	new_node->parent = NULL;
	new_node->children = NULL;
	new_node->num_children = 0;
	new_node->capacity = 0;
	return (new_node);
}

void	add_child(t_tree_node *parent, t_tree_node *child)
{
	t_tree_node	**new_children;
	int			new_capacity;
	int			i;

	i = 0;
	if (parent->num_children >= parent->capacity)
	{
		new_capacity = parent->capacity + 1;
		new_children = malloc(sizeof(t_tree_node *) * new_capacity);
		if (!new_children)
		{
			perror("malloc");
			return (NULL);
		}
		while (i < parent->num_children)
			new_children[i] = parent->children[i];
		free(parent->children);
		parent->children = new_children;
		parent->capacity = new_capacity;
	}
	parent->children[parent->num_children] = child;
	parent->num_children++;
}
