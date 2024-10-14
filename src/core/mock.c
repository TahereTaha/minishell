/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mock.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatahere <tatahere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 09:57:52 by tatahere          #+#    #+#             */
/*   Updated: 2024/10/14 11:22:51 by tatahere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "core.h"

void	run_command(char *cmd)
{
	printf("this is the mock of the run_command function\n");
	printf("\tthe cmd recived is: %s\n", cmd);
}
