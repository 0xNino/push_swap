/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: 0xNino <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 17:06:40 by 0xNino            #+#    #+#             */
/*   Updated: 2022/03/07 17:27:37 by 0xNino           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	solve(t_stacks *stacks)
{
	if (stacks->a->size == 2)
		solve_2(stacks);
	else if (stacks->a->size == 3)
		solve_3(stacks);
	else if (stacks->a->size < 6)
		solve_5(stacks);
	else
		radix_sort(stacks);
}

void	solve_2(t_stacks *stacks)
{
	if (*(int *)stacks->a->first->content > *(int *)stacks->a->last->content)
		operations(stacks, "sa");
}

void	solve_3(t_stacks *stacks)
{
	t_node	*first;
	t_node	*middle;
	t_node	*last;

	first = stacks->a->first;
	middle = stacks->a->first->next;
	last = stacks->a->last;
	if (node_isbigger(first, middle) && node_isbigger(first, last))
		operations(stacks, "ra");
	else if (node_isbigger(middle, first) && node_isbigger(middle, last))
		operations(stacks, "rra");
	if (node_isbigger(stacks->a->first, stacks->a->first->next))
		operations(stacks, "sa");
	if (node_isbigger(stacks->a->first, stacks->a->last))
		operations(stacks, "rra");
}

void	solve_5(t_stacks *stacks)
{
	int	*i_arr;

	i_arr = dlst_to_arr(stacks->a);
	ft_quicksort(i_arr, 0, stacks->a->size - 1);
	pb_5(stacks, i_arr[0]);
	pb_5(stacks, i_arr[stacks->a->size]);
	free(i_arr);
	if (stacks->a->size == 2)
		solve_2(stacks);
	else
		solve_3(stacks);
	operations(stacks, "pa");
	if (node_isbigger(stacks->a->first, stacks->a->first->next))
		operations(stacks, "ra");
	operations(stacks, "pa");
	if (node_isbigger(stacks->a->first, stacks->a->first->next))
		operations(stacks, "ra");
}

void	radix_sort(t_stacks *stacks)
{
	int		i;
	int		bits;
	int		size;

	normalize(stacks->a);
	bits = 0;
	size = stacks->a->size;
	while (!check_is_ordered(stacks->a))
	{
		i = 0;
		while (i++ < size)
		{
			if (((*(int *)stacks->a->first->content >> bits) & 1) == 1)
				operations(stacks, "ra");
			else
				operations(stacks, "pb");
		}
		while (stacks->b->size)
			operations(stacks, "pa");
		bits++;
	}
}
