/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_token.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatahere <tatahere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 07:14:22 by tatahere          #+#    #+#             */
/*   Updated: 2024/10/16 09:14:11 by tatahere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <errno.h>

#include "core_local.h"
#include "tokenizer.h"
#include "libft.h"

t_token_kind	get_token_kind(char *cmd_str)
{
	if (cmd_str[0] == '\0')
		return (TERMINAL_TOKEN);
	if (tokenizer_isblank(cmd_str[0]))
		return (BLANK);
	return (WORD);
}

size_t	get_token_size(char *cmd_str, t_token_kind token_kind)
{
	size_t	i;

	i = 0;
	if (token_kind == TERMINAL_TOKEN)
		return (0);
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
