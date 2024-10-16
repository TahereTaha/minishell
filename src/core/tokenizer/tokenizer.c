/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatahere <tatahere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 12:32:22 by tatahere          #+#    #+#             */
/*   Updated: 2024/10/15 19:03:45 by tatahere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

#include "core_local.h"
#include "libft.h"

//	thing to do
//

int		ms_isblank(int c)
{
	if (c == ' ' || c == '\t' || c == '\n' || c == '\0')
		return (1);
	return (0);
}

t_token_kind	get_token_kind(char *cmd_str)
{
	if (ms_isblank(cmd_str[0]))
		return (BLANK);
	return (WORD);
}

size_t	get_token_size(char *cmd_str, t_token_kind token_kind)
{
	size_t	i;

	i = 0;
	while (get_token_kind(&cmd_str[i]) == token_kind)
		i++;
	return (i);
}

t_token	*get_token(char *cmd_str)
{
	t_token	*token;
	size_t	token_size;

	token = calloc(sizeof(t_token), 1);
	if (!token)
		return (NULL);
	token->kind = get_token_kind(cmd_str);
	token_size = get_token_size(cmd_str, token->kind);
	token->content = ft_substr(cmd_str, 0, token_size);
	if (!token->content)
	{
		free(token);
		return (NULL);
	}
	return (token);
}

void	free_token(void *content)
{
	t_token	*token;

	token = content;
	free(token->content);
	free(token);
}

t_list	*tokenizer(char *cmd_str)
{
	size_t	i;
	t_list	*token_list;
	t_token	*token;
	t_list	*node;

	token_list = NULL;
	i = 0;
	while (cmd_str[i])
	{
		token = get_token(&cmd_str[i]);
		node = ft_lstnew(token);
		if (!node)
		{
			free_token(token);
			ft_lstclear(&token_list, &free_token);
			return (NULL);
		}
		ft_lstadd_back(&token_list, node);
		i += ft_strlen(token->content);
	}
	return (token_list);
}

char	*get_token_kind_str(t_token_kind token_kind)
{
	if (token_kind == WORD)
		return ("WORD");
	if (token_kind == BLANK)
		return ("BLANK");
	return ("no bueno");
}

void	print_token(t_token *token)
{
	printf("<< ");
	printf("token_kind = \"%s\"", get_token_kind_str(token->kind));
	printf(" , ");
	printf("token_content = \"%s\"", token->content);
	printf(" >>\n");
}

void	print_token_list(t_list *token_list)
{
	t_list	*current_node;

	current_node = token_list;
	while (current_node)
	{
		print_token(current_node->content);
		current_node = current_node->next;
	}
}
