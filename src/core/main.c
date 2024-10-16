/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatahere <tatahere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 10:54:47 by tatahere          #+#    #+#             */
/*   Updated: 2024/10/16 09:21:14 by tatahere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include "libft.h"
#include "core.h"
#include "core_local.h"

static void	debug_print_function_info(char *cmd_str)
{
	printf("this is the run_command function\n");
	printf("\tthe cmd_str recived is:\n\t\t%s\n", cmd_str);
}

int	run_command(char *cmd_str)
{
	t_list	*token_list;
	
	debug_print_function_info(cmd_str);
	token_list = tokenizer(cmd_str);
	free(cmd_str);
	if (!token_list)
		return (ENOMEM);
	ft_lstclear(&token_list, &free_token);
	return (0);
}
