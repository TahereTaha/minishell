/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core_local.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatahere <tatahere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 13:34:48 by tatahere          #+#    #+#             */
/*   Updated: 2024/10/15 18:47:44 by tatahere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CORE_LOCAL_H
#define CORE_LOCAL_H

#include "libft.h"

//===================//
//==== tokenizer ====//
//===================//

//	BLANK
//		any of the following: " ", "\t", "\n", "\0".
//
//	WORD
//		any string that dosent pertain to the other categories.
//
//	REDIRECTION
//		any of the following: "<", ">", "<<", ">>".
//
//	PIPE
//		this one: "|".
//
//	OPEN_PARENTESIS
//		this one: "(".
//
//	CLOSE_PARENTESIS
//		this one: ")".
//
//	CONTROL
//		any of the following: "&&", "||".

typedef enum e_token_kind
{
	WORD,
	BLANK,
//	REDIRECTION,
//	CONTROL,
//	OPEN_PARENTESIS,
//	CLOSE_PARENTESIS,
}	t_token_kind;

typedef struct s_token
{
	t_token_kind	kind;
	char			*content;
}	t_token;

void	free_token(void *content);

t_list	*tokenizer(char *cmd_str);

void	print_token(t_token *token);
void	print_token_list(t_list *cmd_str);

//======================//
//==== other things ====//
//======================//

#endif