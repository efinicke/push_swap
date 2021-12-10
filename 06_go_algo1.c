/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   06_go_algo1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efinicke <efinicke@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 17:25:19 by efinicke          #+#    #+#             */
/*   Updated: 2021/09/13 12:53:37 by efinicke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	go_algo(t_loc *stack_a, t_loc *stack_b, t_config *config)
{
	if (simple_sort(stack_a, stack_b))
		return ;
	else if (lstsize(stack_a) == 5)
		algo_five(stack_a, stack_b);
	else if (lstsize(stack_a) <= 50)
	{
		pb_mid_sort(stack_a, stack_b);
	}
	else if (lstsize(stack_a) > 50)
	{
		chunks_pb(config, stack_a, stack_b);
		pa_mid_sort(stack_b, stack_a);
	}
}

void	until_three_sort(t_loc *stack_a, t_loc *stack_b)
{
	if (stack_a->first->data < stack_a->first->next->data)
	{
		if (stack_a->first->next->data < stack_a->last->data)
			return ;
		else if (stack_a->first->data > stack_a->last->data)
			command(stack_a, stack_b, "rra");
		else if (stack_a->first->data < stack_a->last->data)
		{
			command(stack_a, stack_b, "rra");
			command(stack_a, stack_b, "sa");
		}
	}
	else
	{
		if (stack_a->first->next->data > stack_a->last->data)
		{
			command(stack_a, stack_b, "sa");
			command(stack_a, stack_b, "rra");
		}
		else if (stack_a->first->data < stack_a->last->data)
			command(stack_a, stack_b, "sa");
		else if (stack_a->first->data > stack_a->last->data)
			command(stack_a, stack_b, "ra");
	}
}

void	pb_mid_sort(t_loc *stack_a, t_loc *stack_b)
{
	int	len;
	int	mid;

	len = lstsize(stack_a);
	while (lstsize(stack_a) > 3 )
	{
		while (find_smallest_nbr_position(stack_a) != 1)
		{
			if (find_smallest_nbr_position(stack_a) <= mid)
				command(stack_a, stack_b, "ra");
			else
				command(stack_a, stack_b, "rra");
		}
		command(stack_a, stack_b, "pb");
		mid = find_mid(stack_a);
	}
	until_three_sort(stack_a, stack_b);
	while (lstsize(stack_a) != len)
		command(stack_a, stack_b, "pa");
}

void	algo_five(t_loc *stack_a, t_loc *stack_b)
{
	while (is_ready_to_sort(stack_a) == 0)
	{
		move_smallest_up(stack_a, stack_b);
		if (is_ready_to_sort(stack_a) == 0)
			command(stack_a, stack_b, "pb");
		if (lstsize(stack_a) == 3)
			until_three_sort(stack_a, stack_b);
	}
	if (lstsize(stack_a) == 3)
		until_three_sort(stack_a, stack_b);
	while (lstsize(stack_a) != 5)
		command(stack_a, stack_b, "pa");
}

void	move_smallest_up(t_loc *stack_a, t_loc *stack_b)
{
	int	mid;

	mid = find_mid(stack_a);
	while (find_smallest_nbr_position(stack_a) != 1)
	{	
		if (find_smallest_nbr_position(stack_a) <= mid)
			command(stack_a, stack_b, "ra");
		else
			command(stack_a, stack_b, "rra");
	}
}
