/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatahere <tatahere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 10:54:47 by tatahere          #+#    #+#             */
/*   Updated: 2024/10/18 08:37:24 by tatahere         ###   ########.fr       */
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

int	build_token_list(char **cmd_str_ref, t_list **token_list_ref)
{
	char	*cmd_str;
	t_list	*token_list;

	cmd_str = *cmd_str_ref;
	token_list = tokenizer(cmd_str);
	free(cmd_str);
	*cmd_str_ref = NULL;
	if (!token_list)
		return (ENOMEM);
	*token_list_ref = token_list;
	return (0);
}

int	build_sintax_tree(t_list **token_list_ref, void **ast_ref)
{
	t_list	*token_list;
	void	*ast;

	token_list = *token_list_ref;
	ast = NULL;
	ft_lstclear(&token_list, &free_token);
	*token_list_ref = NULL;
	*ast_ref = ast;
	return (0);
}

int	execute(void **ast_ref)
{
	(void)ast_ref;
	return (0);
}

int	run_command(char *cmd_str)
{
	int		error_value;
	t_list	*token_list;
	void	*ast;

	ast = NULL;
	token_list = NULL;
	debug_print_function_info(cmd_str);
	error_value = build_token_list(&cmd_str, &token_list);
	if (error_value)
		return (error_value);
	error_value = build_sintax_tree(&token_list, &ast);
	if (error_value)
		return (error_value);
	error_value = execute(&ast);
	if (error_value)
		return (error_value);

	return (0);
}
