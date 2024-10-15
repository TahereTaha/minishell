/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatahere <tatahere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 10:54:47 by tatahere          #+#    #+#             */
/*   Updated: 2024/10/15 19:02:02 by tatahere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "libft.h"
#include "core.h"
#include "core_local.h"

void	run_command(char *cmd)
{
	t_list	*token_list;

	printf("this is the mock of the run_command function\n");
	printf("\tthe cmd recived is: %s\n", cmd);
	token_list = tokenizer(cmd);
	if (!token_list)
	{
		printf("something really bad hapened\n");
		free(cmd);
		return ;
	}
	printf("the cmd string has ben broken down into:\n");
	print_token_list(token_list);

}
