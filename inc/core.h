/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasroman <gasroman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 14:34:33 by tatahere          #+#    #+#             */
/*   Updated: 2024/10/24 15:50:52 by gasroman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CORE_H
# define CORE_H

//	this function will give the line to the core to interpret and execute
int		run_comand(char *str, void *env_struct);

//	comands to work with the env module
char	**read_env(void *env_struct);
void	push_env(void *env_env);
void	pop_env(void *env_env);

#endif
