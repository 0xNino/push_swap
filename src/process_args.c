/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_args.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: 0xNino <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 00:23:13 by 0xNino            #+#    #+#             */
/*   Updated: 2022/02/26 13:25:51 by 0xNino           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_dlist	*str_to_dlst(char *str)
{
	t_dlist	*dlst;
	int		i;
	int		*content;
	char	**arr;

	arr = ft_split(str, ' ');
	if (!check_args(arr, 0))
	{
		ft_free_arr(arr);
		return (NULL);
	}
	dlst = ft_dlstnew();
	i = -1;
	while (arr[++i])
	{
		content = malloc(sizeof(int));
		if (!content)
			return (NULL);
		*content = ft_atoi(arr[i]);
		ft_dlstadd_last(dlst, content);
	}
	if (!content || !dlst)
		ft_dlstclear(&dlst);
	ft_free_arr(arr);
	return (dlst);
}

t_dlist	*arr_to_dlst(int argc, char **argv)
{
	t_dlist	*dlst;
	int		i;
	int		*content;

	if (!check_args(argv, 1))
		return (NULL);
	dlst = ft_dlstnew();
	i = 0;
	while (++i < argc)
	{
		content = malloc(sizeof(int));
		if (!content)
			return (NULL);
		*content = ft_atoi(argv[i]);
		ft_dlstadd_last(dlst, content);
	}
	if (!content || !dlst)
		ft_dlstclear(&dlst);
	return (dlst);
}

int	*dlst_to_arr(t_dlist *dlst)
{
	t_node	*current;
	int		*i_arr;
	int		i;

	if (!dlst || dlst->size == 0)
		return (NULL);
	i_arr = malloc(sizeof(int) * dlst->size);
	if (!i_arr)
		return (NULL);
	current = dlst->first;
	i = 0;
	while (current)
	{
		i_arr[i++] = *(int *)current->content;
		current = current->next;
	}
	return (i_arr);
}
