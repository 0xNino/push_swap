/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: 0xNino <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 15:33:52 by 0xNino            #+#    #+#             */
/*   Updated: 2022/02/17 21:02:52 by 0xNino           ###   ########.fr       */
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
		ft_dlstput_first(stacks->a, ft_dlstpush_first(stacks->b));
	if (!ft_strcmp(operation, "pb"))
		ft_dlstput_first(stacks->b, ft_dlstpush_first(stacks->a));
	if (!ft_strcmp(operation, "ra") || !ft_strcmp(operation, "rr"))
		ft_dlstput_last(stacks->a, ft_dlstpush_first(stacks->a));
	if (!ft_strcmp(operation, "rb") || !ft_strcmp(operation, "rr"))
		ft_dlstput_last(stacks->b, ft_dlstpush_first(stacks->b));
	if (!ft_strcmp(operation, "rra") || !ft_strcmp(operation, "rrr"))
		ft_dlstput_first(stacks->a, ft_dlstpush_last(stacks->a));
	if (!ft_strcmp(operation, "rrb") || !ft_strcmp(operation, "rrr"))
		ft_dlstput_first(stacks->b, ft_dlstpush_last(stacks->b));
	ft_dlstadd_last(stacks->solution, ft_strdup(operation));
}
