/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   06_go_algo2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efinicke <efinicke@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 17:36:14 by efinicke          #+#    #+#             */
/*   Updated: 2021/09/21 15:12:14 by efinicke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	chunks_pb(t_config *config, t_loc *stack_a, t_loc *stack_b)
{	
	int	chunk;

	chunk = 0;
	chunks_config(config, stack_a);
	while (chunk <= config->chunk_nb)
	{
		chunk_pb(config, stack_a, stack_b);
		chunk++;
		define_chunk_limits(config, chunk);
	}
}

void	chunk_pb(t_config *config, t_loc *stack_a, t_loc *stack_b)
{
	while (stack_a && is_chunk_nbr_here(config, stack_a))
	{
		move_at_first_place(stack_a, stack_b, config);
		if ((stack_b)->first != NULL)
			optim(stack_a, stack_b);
		command(stack_a, stack_b, "pb");
	}
	if (lstsize(stack_a) == 1)
		command(stack_a, stack_b, "pb");
}

void	move_at_first_place(t_loc *stack_a, t_loc *stack_b, t_config *config)
{
	int		i;

	i = 0;
	if (config->top_moves <= config->bot_moves)
	{
		while (stack_a && i != config->top_moves)
		{
			command(stack_a, stack_b, "ra");
			i++;
		}
	}
	else
	{
		while (stack_a && i != config->bot_moves)
		{
			command(stack_a, stack_b, "rra");
			i++;
		}
	}
}

void	optim(t_loc *stack_a, t_loc *stack_b)
{
	if (((stack_b->first->data == find_highest_nbr(stack_b))
			|| (stack_b->first->position == stack_b->last->position - 1)))
		command(stack_a, stack_b, "rb");
}

void	pa_mid_sort(t_loc *stack_src, t_loc *stack_dest)
{
	int	mid;

	while (lstsize(stack_src) != 1)
	{
		while (find_highest_nbr_position(stack_src) != 1)
		{
			if (find_highest_nbr_position(stack_src) <= mid)
				command(stack_dest, stack_src, "rb");
			else
				command(stack_dest, stack_src, "rrb");
		}
		command(stack_dest, stack_src, "pa");
		mid = find_mid(stack_src);
	}
	if (lstsize(stack_src) == 1)
		command(stack_dest, stack_src, "pa");
}
