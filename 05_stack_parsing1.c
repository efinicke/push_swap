/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   05_stack_parsing1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efinicke <efinicke@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 17:38:17 by efinicke          #+#    #+#             */
/*   Updated: 2021/09/13 12:50:56 by efinicke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	find_smallest_nbr_position(t_loc *stack)
{
	int		i;
	int		tmp;
	int		len;
	t_list	*stock;

	i = 0;
	tmp = stack->first->data;
	len = lstsize(stack);
	stock = stack->first;
	while (i < len)
	{
		if (tmp > stack->first->next->data)
			tmp = stack->first->next->data;
		stack->first = stack->first->next;
		i++;
	}
	stack->first = stock;
	i = 1;
	while (stack->first->data != tmp)
	{
		stack->first = stack->first->next;
		i++;
	}
	stack->first = stock;
	return (i);
}

int	find_highest_nbr_position(t_loc *stack)
{
	int		i;
	int		tmp;
	int		len;
	t_list	*stock;

	i = 1;
	tmp = stack->first->data;
	len = lstsize(stack);
	stock = stack->first;
	while (i <= len)
	{
		if (tmp < stack->first->next->data)
			tmp = stack->first->next->data;
		stack->first = stack->first->next;
		i++;
	}
	stack->first = stock;
	i = 1;
	while (stack->first->data != tmp)
	{
		stack->first = stack->first->next;
		i++;
	}
	stack->first = stock;
	return (i);
}

int	find_highest_nbr(t_loc *stack)
{
	int		i;
	int		tmp;
	int		len;
	t_list	*stock;

	i = 0;
	tmp = stack->first->data;
	len = lstsize(stack);
	stock = stack->first;
	while (i < len)
	{
		if (tmp < stack->first->next->data)
			tmp = stack->first->next->data;
		stack->first = stack->first->next;
		i++;
	}
	stack->first = stock;
	return (tmp);
}

int	find_smallest_nbr(t_loc *stack)
{
	int		i;
	int		tmp;
	int		len;
	t_list	*stock;

	i = 0;
	tmp = stack->first->data;
	len = lstsize(stack);
	stock = stack->first;
	while (i < len)
	{
		if (tmp > stack->first->next->data)
			tmp = stack->first->next->data;
		stack->first = stack->first->next;
		i++;
	}
	stack->first = stock;
	return (tmp);
}
