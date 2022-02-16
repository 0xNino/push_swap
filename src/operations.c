/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: 0xNino <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 15:33:52 by 0xNino            #+#    #+#             */
/*   Updated: 2022/02/16 17:23:53 by 0xNino           ###   ########.fr       */
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

void	operations(t_stacks stacks, char *operation)
{
	if (ft_strncmp(operation, "sa", ft_strlen(operation)))
		swap(stacks.a);
}
