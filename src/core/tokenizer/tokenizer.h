/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatahere <tatahere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 16:39:47 by tatahere          #+#    #+#             */
/*   Updated: 2024/10/16 08:18:03 by tatahere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKENIZER_H
# define TOKENIZER_H

# include "core_local.h"

//	utils
int	tokenizer_isblank(int c);

//	token creation
size_t	get_token_size(char *cmd_str, t_token_kind token_kind);
t_token	*get_token(char *cmd_str);

//	debug
void	debug_print_token_list(t_list *token_list);

#endif

