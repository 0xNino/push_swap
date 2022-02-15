/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_args.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: 0xNino <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 00:23:13 by 0xNino            #+#    #+#             */
/*   Updated: 2022/02/15 23:23:36 by 0xNino           ###   ########.fr       */
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

int	check_args(char **arr, int i)
{
	int	j;

	while (arr[i])
	{
		j = 0;
		while (arr[i][j])
		{
			if ((('0' <= arr[i][j] && arr[i][j] <= '9') || arr[i][j] == ' ') &&
			(FT_INT_MIN <= ft_atol(arr[i]) && ft_atol(arr[i]) <= FT_INT_MAX))
				j++;
			else
				return (0);
		}
		i++;
	}
	return (1);
}
