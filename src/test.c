/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasroman <gasroman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 15:26:40 by gasroman          #+#    #+#             */
/*   Updated: 2024/09/23 05:42:38 by gasroman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

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

int	main(void)
{
	char	*input;

	while (1)
	{
		input = readline("WaitingShell: ");
		if (!check_heredoc(input))
		{
			_heredoc(input);
		}
		else if (!ft_strcmp(input, "exit"))
		{
			printf("I don't feel so good Mr. Stark...\n");
			free(input);
			break ;
		}
		else if (*input == '\0')
		{
			free(input);
			continue ;
		}
		else
		{
			add_history(input);
			printf("%s\n", input);
			free(input);
		}
	}
	return (0);
}
