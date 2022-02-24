/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: 0xNino <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 16:47:14 by 0xNino            #+#    #+#             */
/*   Updated: 2022/02/24 16:02:47 by 0xNino           ###   ########.fr       */
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

typedef struct s_info
{
	int	pivot;
	int	*i_arr;
	int	max_a;
	int	max_b;
	int	flag_a;
	int	flag_b;
	int	pos_a;
	int	pos_b;
}	t_info;

// check
int		check_args(char **arr, int i);
int		check_dup(t_dlist *dlst);
int		check_is_ordered(t_dlist *dlst);

// operations
void	swap(t_dlist *dlst);
void	operations(t_stacks *stacks, char *operation);
void	operations_nb(t_stacks *stacks, char *operation, int nb);

// process args
t_dlist	*str_to_dlst(char *str);
t_dlist	*arr_to_dlst(int argc, char **argv);
int		*dlst_to_arr(t_dlist *dlst);

// solve_big
void	solve_big(t_stacks *stacks);
void	sort(int tmp, t_stacks *stacks, t_info *info);
void	push_a(t_stacks *stacks, t_info *info);

// solve
void	solve(t_stacks *stacks);
void	solve_2(t_stacks *stacks);
void	solve_3(t_stacks *stacks);
void	solve_5(t_stacks *stacks);

// utils
int		node_isbigger(t_node *node1, t_node *node2);
void	print_solution(t_stacks *stacks);
void	pb_5(t_stacks *stacks, int nb);
int		dlst_median(t_dlist *dlst, int size);
int		dlst_pos(int n, t_dlist *dlst);

#endif