/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasroman <gasroman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 15:26:40 by gasroman          #+#    #+#             */
/*   Updated: 2024/10/24 15:50:36 by gasroman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./prompt.h"

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

int	exec_promp(char **env)
{
	char	*input;

	while (1)
	{
		input = readline("WaitingShell: ");
		run_comand(input, env);
	}
	return (0);
}

int main(int ac, char **av, char **env)
{
	ac = 0;
	av = NULL;

	exec_promp(env);
	return (0);
}
