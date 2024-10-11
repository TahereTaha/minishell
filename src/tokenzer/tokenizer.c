/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasroman <gasroman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 07:40:13 by gasroman          #+#    #+#             */
/*   Updated: 2024/10/10 19:01:21 by gasroman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./token.h"

e'c'"h"$a lol
ech$a hola "queso" 'paan' | cat | ls | sleep 5

t_tree_node	*create_tree_node(char *value, t_node_type type)
{
	t_tree_node	*node;

	node = (t_tree_node *)malloc(sizeof(t_tree_node));
	if (!node)
		return (NULL);
	node->content = ft_strdup(value);
	node->type = type;
	node->left = NULL;
	node->right = NULL;
	node->parent = NULL;
	return (node);
}

void	add_child(t_tree_node *parent, t_tree_node *child)
{
	t_tree_node	*current;

	if (!parent->child)
		parent->child = child;
	else
	{
		current = parent->child;
		while (current->next)
			current = current->next;
		current->next = child;
	}
	child->parent = parent;
}

void	add_sibling(t_tree_node *node, t_tree_node *sibling)
{
	t_tree_node	*current;

	current = node;
	while (current->next)
		current = current->next;
	current->next = sibling;
	sibling->parent = node->parent;
}
 