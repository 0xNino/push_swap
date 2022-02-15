/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_args.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: 0xNino <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 00:23:13 by 0xNino            #+#    #+#             */
/*   Updated: 2022/02/15 14:06:12 by 0xNino           ###   ########.fr       */
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
	printf("arr[0] = %s\n", arr[0]);
	i = 0;
	while (arr[i] && check_args(arr[i]))
	{
		printf("start while strtodl\n");
		content = malloc(sizeof(int));
		if (!content)
			return (NULL);
		*content = ft_atoi(arr[i]);
		ft_dlstadd_last(dlst, content);
		i++;
	}
	printf("end while strtodl\n");
	if (!content || !dlst || !check_args(arr[i - 1]))
		ft_dlstclear(&dlst);
	printf("arr[0] = %s\n", arr[0]);
	ft_free_arr(arr);
	printf("test\n");
	return (dlst);
}

t_dlist	*arr_to_dlst(int argc, char **argv)
{
	t_dlist	*dlst;
	int		i;
	int		*content;

	dlst = ft_dlstnew();
	i = 1;
	while (i < argc && check_args(argv[i]))
	{
		content = malloc(sizeof(int));
		if (!content)
			return (NULL);
		*content = ft_atoi(argv[i]);
		ft_dlstadd_last(dlst, content);
		i++;
	}
	if (!content || !dlst || !check_args(argv[i - 1]))
		printf("test\n");
//		ft_dlstclear(&dlst);
	return (dlst);
}

int	check_args(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (('0' <= str[i] && str[i] <= '9') || str[i] == ' ')
			i++;
		else
			return (0);
	}
	return (1);
}

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
