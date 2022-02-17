/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: 0xNino <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 16:47:14 by 0xNino            #+#    #+#             */
/*   Updated: 2022/02/17 16:52:05 by 0xNino           ###   ########.fr       */
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

// operations
void	swap(t_dlist *dlst);
void	operations(t_stacks *stacks, char *operation);

// process args
t_dlist	*str_to_dlst(char *str);
t_dlist	*arr_to_dlst(int argc, char **argv);

// solve
void	solve(t_stacks *stacks);
void	solve_2(t_stacks *stacks);
void	solve_3(t_stacks *stacks);
void	solve_5(t_stacks *stacks);
void	solve_big(t_stacks *stacks);

int		check_args(char **arr, int i);
int		check_dup(t_dlist *dlst);
int		dlst_is_ordered(t_dlist *dlst);

// utils
int		node_isbigger(t_node *node1, t_node *node2);
void	print_solution(t_stacks *stacks);

#endif