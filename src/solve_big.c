/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_big.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: 0xNino <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 23:18:29 by 0xNino            #+#    #+#             */
/*   Updated: 2022/02/28 19:05:51 by 0xNino           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	solve_big(t_stacks *stacks)
{
	t_info	*info;
	int		tmp;
	int		i;

	i = 0;
	info = malloc(sizeof(t_info));
	if (!info)
		return ;
//	ft_dlstprintint(stacks->a, "a");
//	info->i_arr = dlst_to_arr(stacks->a);
//	ft_print_i_arr(info->i_arr, stacks->a->size, "a");
//	ft_quicksort(info->i_arr, 0, stacks->a->size - 1);
//	ft_print_i_arr(info->i_arr, stacks->a->size, "a");
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
//		ft_dlstprintint(stacks->a, "a");
//		ft_dlstprintint(stacks->b, "b");
//		printf("tmp = %i\n", tmp);
		tmp--;
	}
}

void	push_a(t_stacks *stacks, t_info *info)
{
//	printf("start push_a\n");
	while (stacks->b->size)
	{
//		ft_dlstprintint(stacks->a, "a");
//		ft_dlstprintint(stacks->b, "b");
		info->flag_a = 0;
		info->flag_b = 0;
		info->max_b = dlst_max(stacks->b, INT_MIN);
//		printf("max_b = %i\n", info->max_b);
		info->max_a = dlst_max(stacks->b, info->max_b);
//		printf("max_a = %i\n", info->max_a);
		info->pos_a = dlst_pos(stacks->b, info->max_b);
//		printf("pos_a = %i, b size / 2 = %lu\n", info->pos_a, stacks->b->size / 2);
		info->pos_b = dlst_pos(stacks->b, info->max_a);
//		printf("pos_b = %i, b size / 2 = %lu\n", info->pos_b, stacks->b->size / 2);
		if (info->pos_a < (int)stacks->b->size / 2)
			info->flag_a = 1;
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
//	printf("end push_a\n");
}

void	push_max(t_stacks *stacks, int m, t_info *info)
{
	int		f;
	t_node	*current;

//	printf("start push_max\n");
	f = 0;
	current = stacks->b->first;
	if (*(int *)current->content < m)
	{
		while (*(int *)current->content != m && current->next)
		{
			if (*(int *)current->next->content == m)
			{
				operations(stacks, "sb");
				operations(stacks, "pa");
//				ft_dlstprintint(stacks->a, "a");
//				ft_dlstprintint(stacks->b, "b");
				f = 1;
				break ;
			}
			if (info->flags == 1)
				operations(stacks, "rb");
			else
				operations(stacks, "rrb");
//			ft_dlstprintint(stacks->a, "a");
//			ft_dlstprintint(stacks->b, "b");
		}
	}
	if (!f)
		operations(stacks, "pa");
//	printf("end push_max\n");
}
