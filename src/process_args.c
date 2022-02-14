/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_args.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: 0xNino <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 00:23:13 by 0xNino            #+#    #+#             */
/*   Updated: 2022/02/14 23:12:44 by 0xNino           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_dlist	*str_to_dlst(char *str)
{
	t_dlist	*dlst;
	int		i;
	int		*content;
	char	**arr;

	dlst = ft_dlstnew();
	arr = ft_split(str, ' ');
	i = 0;
	while (arr[i])
	{
		content = malloc(sizeof(int));
		if (!content)
			return (NULL);
		*content = ft_atoi(arr[i]);
		ft_dlstadd_last(dlst, content);
		i++;
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

	dlst = ft_dlstnew();
	i = 1;
	while (i < argc)
	{
		content = malloc(sizeof(int));
		if (!content)
			return (NULL);
		*content = ft_atoi(argv[i]);
		ft_dlstadd_last(dlst, content);
		i++;
	}
	if (!content || !dlst)
		ft_dlstclear(&dlst);
	return (dlst);
}
/*
int	main(int argc, char **argv)
{
	t_dlist	*dlst;

	if (argc == 2)
	{
		dlst = str_to_dlst(argv[1]);
		ft_dlstprintint(dlst);
	}
	else if (argc > 2)
	{
		dlst = arr_to_dlst(argc, argv);
		ft_dlstprintint(dlst);
	}
	return (0);
}
*/