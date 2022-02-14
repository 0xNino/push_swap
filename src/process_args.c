/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_args.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: 0xNino <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 00:23:13 by 0xNino            #+#    #+#             */
/*   Updated: 2022/02/14 16:56:30 by 0xNino           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
/*
t_dlist	*str_to_dlst(char *str)
{
	t_dlist	*dlst;
	int		i;
	int		*content;

	dlst = ft_dlstnew();
	i = 0;
	while (str[i])
	{
		if (ft_isnumber(str + i))
		{
			content = malloc(sizeof(int));
			if (!content)
				return (NULL);
			content = ft_atoi(str + i);
			ft_dlstadd_last(dlst, content);
			i += ft_abs(ft_isnumber(str + i));
		}
		else if (str[i] == ' ')
			i++;
	}
	if (!content || !dlst)
		ft_dlstclear(&dlst);
	return (dlst);
}
*/
t_dlist	*str_to_dlst(char *str)
{
	t_dlist	*dlst;
	int		i;
	int		content;
	char	**arr;

	dlst = ft_dlstnew();
	arr = ft_split(str, ' ');
	i = 0;
	while (arr[i])
	{
		content = ft_atoi(arr[i]);
		ft_dlstadd_last(dlst, &content);
		i++;
	}
	if (!content || !dlst)
		ft_dlstclear(&dlst);
	return (dlst);
}

t_dlist	*arr_to_dlst(int argc, char **argv)
{
}
