/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatahere <tatahere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 12:32:22 by tatahere          #+#    #+#             */
/*   Updated: 2024/10/22 17:46:20 by tatahere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

#include "core_local.h"
#include "tokenizer.h"
#include "libft.h"

static t_token	*get_next_token(char *cmd_str)
{
	static size_t	i = 0;
	t_token			*token;

	token = get_token(&cmd_str[i]);
	if (!token)
		return (NULL);
	if (token->kind == BLANK)
	{
		i += ft_strlen(token->content);
		free_token(token);
		token = get_token(&cmd_str[i]);
		if (!token)
			return (NULL);
	}
	if (token->kind == TERMINAL_TOKEN)
		i = 0;
	else
		i += ft_strlen(token->content);
	return (token);
}

static t_list	*get_next_node(char *cmd_str)
{
	t_token	*token;
	t_list	*node;

	token = get_next_token(cmd_str);
	if (!token)
		return (NULL);
	node = ft_lstnew(token);
	if (!node)
	{
		free_token(token);
		return (NULL);
	}
	return (node);
}


t_list	*tokenizer(char *cmd_str)
{
	t_list	*token_list;
	t_list	*node;

	token_list = NULL;
	node = get_next_node(cmd_str);
	while (((t_token *)node->content)->kind != TERMINAL_TOKEN)
	{
		ft_lstadd_back(&token_list, node);
		node = get_next_node(cmd_str);
		if (!node)
		{
			ft_lstclear(&token_list, &free_token);
			return (NULL);
		}
	}
	ft_lstadd_back(&token_list, node);
	debug_print_token_list(token_list);
	return (token_list);
}
