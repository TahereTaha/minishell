/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatahere <tatahere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 07:54:21 by tatahere          #+#    #+#             */
/*   Updated: 2024/10/16 09:20:20 by tatahere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "core_local.h"
#include "tokenizer.h"
#include "libft.h"

static char	*get_token_kind_str(t_token_kind token_kind)
{
	if (token_kind == TERMINAL_TOKEN)
		return ("TERMINAL_TOKEN");
	if (token_kind == WORD)
		return ("WORD");
	if (token_kind == BLANK)
		return ("BLANK");
	return ("NO_TOKEN");
}

static void	print_token(t_token *token)
{
	printf("\t\t<< ");
	printf("token_kind = \"%s\"", get_token_kind_str(token->kind));
	printf(" , ");
	printf("token_content = \"%s\"", token->content);
	printf(" >>\n");
}

static void	print_token_list(t_list *token_list)
{
	t_list	*current_node;

	current_node = token_list;
	while (current_node)
	{
		print_token(current_node->content);
		current_node = current_node->next;
	}
}

void	debug_print_token_list(t_list *token_list)
{
	printf("\tthe cmd string has ben broken down into:\n");
	print_token_list(token_list);
}
