/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: 0xNino <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 13:41:06 by 0xNino            #+#    #+#             */
/*   Updated: 2022/03/01 18:10:37 by 0xNino           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	radix_sort(t_stacks *stacks)
{
	int		i;
	int		bits;
	int		max_size;

	normalize(stacks->a);
	bits = 0;
	max_size = stacks->a->size;
	while (!check_is_ordered(stacks->a))
	{
		i = 0;
		while (i++ < max_size)
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
