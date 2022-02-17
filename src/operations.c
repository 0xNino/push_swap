/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: 0xNino <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 15:33:52 by 0xNino            #+#    #+#             */
/*   Updated: 2022/02/17 20:56:32 by 0xNino           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	swap(t_dlist *dlst)
{
	void	*tmp;

	if (dlst->size < 2)
		return ;
	tmp = dlst->first->content;
	dlst->first->content = dlst->first->next->content;
	dlst->first->next->content = tmp;
}

void	operations(t_stacks *stacks, char *operation)
{
	if (!ft_strcmp(operation, "sa"))
		swap(stacks->a);
	if (!ft_strcmp(operation, "sb"))
		swap(stacks->b);
	if (!ft_strcmp(operation, "pa"))
		ft_dlstputfirst(stacks->a, ft_dlstpushfirst(stacks->b));
	if (!ft_strcmp(operation, "pb"))
		ft_dlstputfirst(stacks->b, ft_dlstpushfirst(stacks->a));
	if (!ft_strcmp(operation, "ra") || !ft_strcmp(operation, "rr"))
		ft_dlstputlast(stacks->a, ft_dlstpushfirst(stacks->a));
	if (!ft_strcmp(operation, "rb") || !ft_strcmp(operation, "rr"))
		ft_dlstputlast(stacks->b, ft_dlstpushfirst(stacks->b));
	if (!ft_strcmp(operation, "rra") || !ft_strcmp(operation, "rrr"))
		ft_dlstputfirst(stacks->a, ft_dlstpushlast(stacks->a));
	if (!ft_strcmp(operation, "rrb") || !ft_strcmp(operation, "rrr"))
		ft_dlstputfirst(stacks->b, ft_dlstpushlast(stacks->b));
	ft_dlstadd_last(stacks->solution, ft_strdup(operation));
}
