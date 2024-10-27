/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: filferna <filferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 14:16:35 by filferna          #+#    #+#             */
/*   Updated: 2024/10/27 15:20:08 by filferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>
#include "libs/libft/libft.h"
#include "libs/ft_printf/ft_printf.h"

#define	BUILT		1
#define CMD			2
#define ARG			3
#define	PIPE		4
#define RED_OUT		5
#define APP_OUT		6
#define	RED_IN		7
#define	HERE_DOC	8

typedef struct s_args{
	char 			*token;
	int				type;
	struct	s_args	*next;
}	t_args;

void	lexer(t_args **mshh, char **line);
int		is_cmd(char *str);
void	expand(t_args **args);
char	*ft_expander(char *str);
char	*get_var_name(char *env_var);
char	*ft_final_expand(char *str, char *var, char *var_name);

#endif