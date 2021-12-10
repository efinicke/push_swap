/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   04_commands2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efinicke <efinicke@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 17:29:07 by efinicke          #+#    #+#             */
/*   Updated: 2021/09/13 12:39:41 by efinicke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	ra_rb(t_loc *stack)
{
	if (stack && lstsize(stack) >= 2)
	{
		stack->last = stack->last->next;
		stack->first = stack->first->next;
		return (1);
	}
	return (0);
}

int	rr(t_loc *stack_a, t_loc *stack_b)
{
	if (stack_a && stack_b)
	{
		if (lstsize(stack_a) >= 2 || lstsize(stack_b) >= 2 )
		{
			ra_rb(stack_a);
			ra_rb(stack_b);
			return (1);
		}
	}
	return (0);
}

int	rra_rrb(t_loc *stack)
{
	if (stack && lstsize(stack) >= 2)
	{
		stack->first = stack->first->prev;
		stack->last = stack->last->prev;
		return (1);
	}
	return (0);
}

int	rrr(t_loc *stack_a, t_loc *stack_b)
{
	if (stack_a && stack_b)
	{
		if (lstsize(stack_a) >= 2 || lstsize(stack_b) >= 2 )
		{
			rra_rrb(stack_a);
			rra_rrb(stack_b);
			return (1);
		}
	}
	return (0);
}
