/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: 0xNino <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 17:06:40 by 0xNino            #+#    #+#             */
/*   Updated: 2022/02/16 17:30:49 by 0xNino           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	solve(t_dlist *dlst)
{
	if (dlst->size == 2)
		solve_2(dlst);
	else if (dlst->size == 3)
		solve_3(dlst);
	else if (dlst->size < 6)
		solve_5(dlst);
	else
		solve_big(dlst);
}

void	solve_2(t_dlist *dlst)
{
	if (dlst)
		return ;
}

void	solve_3(t_dlist *dlst)
{
	if (dlst)
		return ;
}

void	solve_5(t_dlist *dlst)
{
	if (dlst)
		return ;
}

void	solve_big(t_dlist *dlst)
{
	if (dlst)
		return ;
}
