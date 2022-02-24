/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: 0xNino <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 16:28:25 by 0xNino            #+#    #+#             */
/*   Updated: 2022/02/24 16:02:36 by 0xNino           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	node_isbigger(t_node *node1, t_node *node2)
{
	return (*(int *)node1->content > *(int *)node2->content);
}

void	print_solution(t_stacks *stacks)
{
	t_node	*current;

	current = stacks->solution->first;
	while (current)
	{
		ft_putendl_fd(current->content, STDOUT_FILENO);
		current = current->next;
	}
}

void	pb_5(t_stacks *stacks, int nb)
{
	size_t	pos;
	t_node	*current;

	pos = 0;
	current = stacks->a->first;
	while (current)
	{
		if (*(int *)current->content == nb)
		{
			if (pos == stacks->a->size - 1)
				operations(stacks, "rra");
			else if (pos == stacks->a->size - 2)
				operations_nb(stacks, "rra", 2);
			else if (pos == 2)
				operations_nb(stacks, "ra", 2);
			else if (pos == 1)
				operations(stacks, "sa");
			operations(stacks, "pb");
		}
		current = current->next;
		pos++;
	}
}

int	dlst_median(t_dlist *dlst, int size)
{
	int	*i_arr;
	int	median;

	i_arr = dlst_to_arr(dlst);
	ft_quicksort(i_arr, 0, size - 1);
	median = i_arr[size / 2];
	free(i_arr);
	return (median);
}

int	dlst_pos(int n, t_dlist *dlst)
{
	int		pos;
	t_node	*current;

	pos = 0;
	current = dlst->first;
	while (current->content != n)
	{
		current = current->next;
		pos++;
	}
	return (pos);
}
