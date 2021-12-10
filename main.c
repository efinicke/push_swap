/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efinicke <efinicke@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 11:20:51 by efinicke          #+#    #+#             */
/*   Updated: 2021/09/21 14:51:45 by efinicke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	main(int argc, char **argv)
{
	int			i;
	t_loc		stack_a;
	t_loc		stack_b;
	t_config	config;

	stack_b.first = NULL;
	if (argc > 1)
	{
		if (argv_parsing(argc, argv) == 1)
			return (1);
		if (is_arg_sorted(argc, argv))
			return (0);
		create_stack_a(argv, &stack_a);
		go_algo(&stack_a, &stack_b, &config);
		i = is_nodes_sorted(stack_a.first);
		if (stack_a.first != NULL)
			lstclear(&stack_a);
		if (stack_b.first)
			lstclear(&stack_b);
		if (i == 1)
			return (0);
		return (1);
	}
	return (0);
}
