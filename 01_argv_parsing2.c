/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_argv_parsing2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efinicke <efinicke@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 11:49:57 by efinicke          #+#    #+#             */
/*   Updated: 2021/09/13 11:58:24 by efinicke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

/*
** Return 1 : nodes are sorted.
*/
int	is_nodes_sorted(t_list *first_node)
{
	t_list	*node;
	t_list	*last;

	node = first_node;
	last = first_node->prev;
	while (node->next != last)
	{
		if (node->data > node->next->data)
			return (0);
		node = node->next;
	}
	if (node->data > node->next->data)
		return (0);
	return (1);
}

/*
** return 1 : tous les maillons se suivent dans l'ordre croissant, 
** mais le plus petit element n'est pas encore en tete de liste.
*/
int	is_ready_to_sort(t_loc *stack)
{
	t_list	*node;
	t_list	*tmp;

	node = stack->first;
	tmp = stack->first;
	while (node->data != find_smallest_nbr(stack))
		node = node->next;
	node = tmp;
	if (is_nodes_sorted(node) == 1)
		return (1);
	return (0);
}

/*
** return 1 : Deplace le plus petit element d'une liste circulaire 
** en premiere position si is_ready_to_sort == 1.
*/
int	simple_sort(t_loc *stack_a, t_loc *stack_b)
{
	if (is_ready_to_sort(stack_a))
	{
		move_smallest_up(stack_a, stack_b);
		return (1);
	}
	return (0);
}
