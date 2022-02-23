/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_big.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: 0xNino <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 23:18:29 by 0xNino            #+#    #+#             */
/*   Updated: 2022/02/23 23:28:32 by 0xNino           ###   ########.fr       */
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
	ft_quicksort(info->i_arr, 0, stacks->a->size - 1);
	ft_print_i_arr(info->i_arr);
	while (stacks->a->size > 2)
	{
		info->pivot = dlst_median(stacks->a, stacks->a->size);
		tmp = stacks->a->size;
		sort(tmp, stacks, info);
	}
	operations_nb(stacks, "pb", 2);
}

int	dlst_median(t_dlist *stack, int size)
{
	int	*i_arr;
	int	median;

	i_arr = dlst_to_arr(stack);
	ft_quicksort(i_arr, 0, size - 1);
	median = i_arr[size / 2];
	free(i_arr);
	return (median);
}

void	sort(int tmp, t_stacks *stacks, t_info *info)
{
	while (tmp && stacks->a->size > 2)
	{
		if (*(int *)stacks->a->first->content <= info->pivot)
		{
			operations(stacks, "pb");
			if (*(int *)stacks->b->first->content < dlst_median(stacks->b, stacks->b->size)
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
		ft_dlstprintint(stacks->a);
		tmp--;
	}
}
