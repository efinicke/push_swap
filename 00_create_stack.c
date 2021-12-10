/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_create_stack.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efinicke <efinicke@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 17:23:13 by efinicke          #+#    #+#             */
/*   Updated: 2021/09/21 15:24:28 by efinicke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	init_lst(t_loc *stack, char **argv)
{
	t_list	*first;

	stack->first = malloc(sizeof(t_list));
	first = stack->first;
	if (!first)
		return ;
	else
	{
		first->data = ft_atoll(argv[1]);
		first->prev = NULL;
		first->next = NULL;
	}
}

void	add_new(t_list *prev, char *str, t_loc *stack)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	if (!new)
		return ;
	else
	{
		prev->next = new;
		new->data = ft_atoll(str);
		new->prev = prev;
		new->next = NULL;
	}
	stack->last = new;
}

void	create_stack_a(char **argv, t_loc *stack_a)
{
	int		i;

	i = 1;
	if (argv[i])
		init_lst(stack_a, argv);
	stack_a->last = stack_a->first;
	while (argv[++i])
	{
		add_new(stack_a->last, argv[i], stack_a);
	}
	stack_a->last->next = stack_a->first;
	stack_a->first->prev = stack_a->last;
	define_position(stack_a);
}
