/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   04_commands3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efinicke <efinicke@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 12:36:49 by efinicke          #+#    #+#             */
/*   Updated: 2021/09/13 12:36:51 by efinicke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	pa_pb(t_loc *stack_src, t_loc *stack_dest)
{
	t_list	*front;

	front = stack_src->first;
	if (!stack_src)
		return (0);
	if (front && lstsize(stack_src) > 1)
	{
		stack_src->first = stack_src->first->next;
		stack_src->last->next = stack_src->first;
		stack_src->first->prev = stack_src->last;
	}
	else if (front && lstsize(stack_src) == 1)
	{
		stack_src->first = NULL;
		stack_src->last = NULL;
		stack_src = NULL;
	}
	if (!stack_dest->first && front)
		ergo_pa_pb(front, stack_dest, 1);
	else if (stack_dest->first && front)
		ergo_pa_pb(front, stack_dest, 2);
	return (1);
}

void	ergo_pa_pb(t_list *front, t_loc *stack_dest, int i)
{
	if (i == 1)
	{
		stack_dest->first = front;
		stack_dest->first->next = front;
		stack_dest->first->prev = front;
		stack_dest->last = stack_dest->first;
	}
	else if (i == 2)
	{
		front->next = stack_dest->first;
		front->prev = stack_dest->last;
		stack_dest->last->next = front;
		stack_dest->first->prev = front;
		stack_dest->first = stack_dest->first->prev;
	}
}
