/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dlst_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: 0xNino <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 22:14:47 by 0xNino            #+#    #+#             */
/*   Updated: 2022/02/25 15:21:30 by 0xNino           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	dlst_median(t_dlist *dlst, int size)
{
	int	*i_arr;
	int	median;

	i_arr = dlst_to_arr(dlst);
	ft_print_i_arr(i_arr);
	ft_quicksort(i_arr, 0, size - 1);
	ft_print_i_arr(i_arr);
	median = i_arr[size / 2];
	free(i_arr);
	return (median);
}

int	dlst_pos(t_dlist *dlst, int n)
{
	int		pos;
	t_node	*current;

	pos = 0;
	current = dlst->first;
	while (*(int *)current->content != n)
	{
		current = current->next;
		pos++;
	}
	return (pos);
}

int	dlst_max(t_dlist *dlst, int skip)
{
	int		max;
	t_node	*current;

	max = INT_MIN;
	current = dlst->first;
	while (current)
	{
		if (*(int *)current->content > max && *(int *)current->content != skip)
			max = *(int *)current->content;
		current = current->next;
	}
	return (max);
}
