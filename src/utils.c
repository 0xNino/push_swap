/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: 0xNino <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 16:28:25 by 0xNino            #+#    #+#             */
/*   Updated: 2022/02/18 16:16:46 by 0xNino           ###   ########.fr       */
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
