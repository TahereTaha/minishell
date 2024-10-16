/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_token.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatahere <tatahere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 07:28:21 by tatahere          #+#    #+#             */
/*   Updated: 2024/10/16 07:45:57 by tatahere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "core_local.h"

void	free_token(void *content)
{
	t_token	*token;

	if (!content)
		return ;
	token = content;
	free(token->content);
	free(token);
}
