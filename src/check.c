/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: 0xNino <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 16:04:17 by 0xNino            #+#    #+#             */
/*   Updated: 2022/02/18 16:06:18 by 0xNino           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	check_args(char **arr, int i)
{
	int	j;

	if (!arr)
		return (0);
	while (arr[i])
	{
		if (arr[i][0] == '-')
			j = 1;
		else
			j = 0;
		while (arr[i][j])
		{
			if ((('0' <= arr[i][j] && arr[i][j] <= '9') || arr[i][j] == ' ')
			&& (INT_MIN <= ft_atol(arr[i]) && ft_atol(arr[i]) <= INT_MAX))
				j++;
			else
				return (0);
		}
		i++;
	}
	return (1);
}

int	check_dup(t_dlist *dlst)
{
	t_node	*node;
	t_node	*current;

	node = dlst->first;
	while (node->next)
	{
		current = node;
		while (current->next)
		{
			current = current->next;
			if (*(int *)current->content == *(int *)(node->content))
				return (0);
		}
		node = node->next;
	}
	return (1);
}

int	check_is_ordered(t_dlist *dlst)
{
	t_node	*current;

	current = dlst->first;
	while (current->next)
	{
		if (*(int *)current->content > *(int *)(current->next->content))
			return (0);
		current = current->next;
	}
	return (1);
}
