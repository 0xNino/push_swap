/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: 0xNino <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 17:06:40 by 0xNino            #+#    #+#             */
/*   Updated: 2022/02/23 18:52:11 by 0xNino           ###   ########.fr       */
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
		solve_big(stacks);
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
	pb_5(stacks, i_arr[4]);
	solve_3(stacks);
	operations(stacks, "pa");
	if (node_isbigger(stacks->a->first, stacks->a->first->next))
		operations(stacks, "ra");
	operations(stacks, "pa");
	if (node_isbigger(stacks->a->first, stacks->a->first->next))
		operations(stacks, "ra");
}

void	sort(int tmp, t_stacks *stacks, t_ps *ps)
{
	t_node	*top_a;
	t_node	*top_b;

	top_a = stacks->a->first;
	top_b = stacks->b->first;
	while (tmp && stacks->a->size > 2)
	{
		printf("top_a = %i pivot = %i\n", *(int *)top_a->content, ps->pivot);
		if (*(int *)top_a->content <= ps->pivot)
		{
			operations(stacks, "pb");
			ft_dlstprintint(stacks->a);
			if (*(int *)top_b->content < ps->i_arr[stacks->b->size / 2] && stacks->b->size > 1)
			{
				if (*(int *)top_a->content > ps->pivot)
					operations(stacks, "rr");
				else
					operations(stacks, "rb");
			}
		}
		else
			operations(stacks, "ra");
//		printf("tmp = %i size a = %zu\n", tmp, stacks->a->size);
		tmp--;
	}
}

void	solve_big(t_stacks *stacks)
{
	t_ps	*ps;
	int		tmp;

	ps = malloc(sizeof(t_ps));
	if (!ps)
		return ;
	ps->i_arr = dlst_to_arr(stacks->a);
	ft_quicksort(ps->i_arr, 0, stacks->a->size - 1);
	ft_print_i_arr(ps->i_arr);
	while (stacks->a->size > 2)
	{
		ps->pivot = ps->i_arr[stacks->a->size / 2];
		tmp = stacks->a->size;
		sort(tmp, stacks, ps);
		break;
	}
	operations_nb(stacks, "pb", 2);
	operations(stacks, "pa");
}
