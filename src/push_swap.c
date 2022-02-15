/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: 0xNino <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 22:34:54 by 0xNino            #+#    #+#             */
/*   Updated: 2022/02/15 21:47:29 by 0xNino           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	main(int argc, char **argv)
{
	t_stacks	stacks;

	if (argc < 2)
		ft_putendl_fd("Error\nToo few arguments", STDERR_FILENO);
	if (argc == 2)
		stacks.a = str_to_dlst(argv[1]);
	else
		stacks.a = arr_to_dlst(argc, argv);
	if (!stacks.a)
		ft_putendl_fd("Error\n", STDERR_FILENO);
	else
		ft_dlstprintint(stacks.a);
}
