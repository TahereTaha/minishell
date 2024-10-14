/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mock.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatahere <tatahere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 09:57:52 by tatahere          #+#    #+#             */
/*   Updated: 2024/10/10 10:01:01 by tatahere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "core.h"

void	run_command(char *cmd, void *env)
{
	(void)env;
	(void)cmd;
	printf("this is the mock of the run_command function\n");
}
