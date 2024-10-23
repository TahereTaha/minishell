/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   __prompt.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasroman <gasromann@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 16:28:47 by gasroman          #+#    #+#             */
/*   Updated: 2024/10/23 19:24:21 by tatahere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <readline/readline.h>
#include <readline/history.h>

#include "prompt.h"
#include "core.h"

/*
int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

void	_heredoc(char *str)
{
	char	*hd_input;
	char	**_name;

	_name = ft_split(str, ' ');
	while (1)
	{
		hd_input = readline("> ");
		if (!ft_strcmp(hd_input, _name[1]))
		{
			free(hd_input);
			break ;
		}
	}
}

int	check_heredoc(char *haystak)
{
	int	i;

	i = 0;
	while (haystak[i])
	{
		if (haystak[i] == '<' && haystak[i++] == '<')
			return (0);
		else
			i++;
	}
	return (1);
}
*/
int	exec_prompt(void)
{
	char	*input;

	while (1)
	{
		input = readline("WaitingShell: ");
		if (!input)
			return (0);
		run_command(input);
	}
	return (0);
}
