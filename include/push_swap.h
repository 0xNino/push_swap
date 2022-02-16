/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: 0xNino <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 16:47:14 by 0xNino            #+#    #+#             */
/*   Updated: 2022/02/16 17:27:25 by 0xNino           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <unistd.h>
# include "../libft/include/libft.h"

typedef struct s_stacks
{
	t_dlist	*a;
	t_dlist	*b;
	t_dlist	*solution;
}	t_stacks;

t_dlist	*str_to_dlst(char *str);
t_dlist	*arr_to_dlst(int argc, char **argv);

int		check_args(char **arr, int i);
int		check_dup(t_dlist *dlst);
int		dlst_is_ordered(t_dlist *dlst);

void	solve(t_dlist *dlst);
void	solve_2(t_dlist *dlst);
void	solve_3(t_dlist *dlst);
void	solve_5(t_dlist *dlst);
void	solve_big(t_dlist *dlst);

void	swap(t_dlist *dlst);
void	operations(t_stacks stacks, char *operation);

#endif