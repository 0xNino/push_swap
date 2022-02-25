/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_big.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: 0xNino <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 23:18:29 by 0xNino            #+#    #+#             */
/*   Updated: 2022/02/25 15:11:31 by 0xNino           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	solve_big(t_stacks *stacks)
{
	t_info	*info;
	int		tmp;

	info = malloc(sizeof(t_info));
	if (!info)
		return ;
	info->i_arr = dlst_to_arr(stacks->a);
	ft_print_i_arr(info->i_arr);
	ft_quicksort(info->i_arr, 0, stacks->a->size - 1);
	ft_print_i_arr(info->i_arr);
	while (stacks->a->size > 2)
	{
		info->pivot = dlst_median(stacks->a, stacks->a->size);
		tmp = stacks->a->size;
		sort(tmp, stacks, info);
	}
	operations_nb(stacks, "pb", 2);
	push_a(stacks, info);
}

void	sort(int tmp, t_stacks *stacks, t_info *info)
{
	while (tmp && stacks->a->size > 2)
	{
		if (*(int *)stacks->a->first->content <= info->pivot)
		{
			operations(stacks, "pb");
			if (*(int *)stacks->b->first->content
				< dlst_median(stacks->b, stacks->b->size)
				&& stacks->b->size > 1)
			{
				if (*(int *)stacks->a->first->content > info->pivot)
					operations(stacks, "rr");
				else
					operations(stacks, "rb");
			}
		}
		else
			operations(stacks, "ra");
		tmp--;
	}
}

void	push_a(t_stacks *stacks, t_info *info)
{
	while (stacks->b->size)
	{
		info->flag_a = 0;
		info->flag_b = 0;
		info->max_b = dlst_max(stacks->b, INT_MIN);
		info->max_a = dlst_max(stacks->b, info->max_b);
		info->pos_a = dlst_pos(stacks->b, info->max_b);
		info->pos_b = dlst_pos(stacks->b, info->max_a);
		if (info->pos_a < (int)stacks->b->size / 2)
			info->flag_b = 1;
		if (info->max_a != INT_MIN && info->pos_b < (int)stacks->b->size / 2)
			info->flag_b = 1;
		info->flags = info->flag_a;
		if (info->max_a != INT_MIN && info->flag_a == info->flag_b
			&& ((info->pos_a > info->pos_b && info->flag_a)
				|| (info->pos_a < info->pos_b && !info->flag_a)))
		{
			push_max(stacks, info->max_a, info);
			push_max(stacks, info->max_b, info);
			operations(stacks, "sa");
		}
		else
			push_max(stacks, info->max_b, info);
	}
}

void	push_max(t_stacks *stacks, int m, t_info *info)
{
	int		f;
	t_node	*current;

	f = 0;
	current = stacks->b->first;
	if (*(int *)current->content < m)
	{
		while (*(int *)current->content != m)
		{
			if (*(int *)current->content == m)
			{
				operations(stacks, "sb");
				operations(stacks, "pa");
				f = 1;
				break ;
			}
			if (info->flags == 1)
				operations(stacks, "rb");
			else
				operations(stacks, "rrb");
		}
	}
	if (!f)
		operations(stacks, "pa");
}
