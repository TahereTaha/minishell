/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasroman <gasroman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 15:26:40 by gasroman          #+#    #+#             */
/*   Updated: 2024/10/11 15:08:30 by gasroman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/prompt.h"

t_tree_node	*create_node(char *value, t_tree_node *parent)
{
	t_tree_node	*new_node;

	new_node = malloc(sizeof(t_tree_node));
	if (!new_node)
		exit(1);
	new_node->value = value;
	new_node->left = NULL;
	new_node->right = NULL;
	new_node->parent = parent;
	return (new_node);
}

void	insert(t_tree_node **root, char *value, t_tree_node *parent)
{
	if (*root == NULL)
	{
		*root = create_node(value, parent);
	}
	else if (strcmp(value, (*root)->value) < 0)
	{
		insert(&(*root)->left, value, *root);
	}
	else
	{
		insert(&(*root)->right, value, *root);
	}
}
