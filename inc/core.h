/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatahere <tatahere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 14:34:33 by tatahere          #+#    #+#             */
/*   Updated: 2024/09/23 18:35:39 by tatahere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CORE_H
#define CORE_H

//	this function will give the line to the core to interpret and execute
int	run_comand(char *str, void *env_struct);

//	comands to work with the env module
char	**read_env(void *env_struct);
void	push_env(void *env_env);
void	pop_env(void *env_env);

#endif
