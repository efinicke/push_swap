/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   05_stack_parsing3.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efinicke <efinicke@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 17:42:01 by efinicke          #+#    #+#             */
/*   Updated: 2021/09/13 12:51:10 by efinicke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	find_mid(t_loc *stack_a)
{
	int	mid;

	mid = (lstsize(stack_a) / 2);
	if ((lstsize(stack_a) % 2) > 0)
		mid += 1;
	return (mid);
}

void	define_position(t_loc *stack_a)
{
	t_list	*tmp_i;
	t_list	*tmp_d;
	int		position;
	int		count_d;
	int		count_i;

	tmp_d = stack_a->first;
	count_d = 0;
	while (count_d < lstsize(stack_a))
	{
		tmp_i = stack_a->first;
		count_i = 0;
		position = 1;
		while (count_i < lstsize(stack_a))
		{
			if (tmp_d->data > tmp_i->data)
				position++;
			tmp_i = tmp_i->next;
			count_i++;
		}
		count_d++;
		tmp_d->position = position;
		tmp_d = tmp_d->next;
	}
}

int	is_chunk_nbr_here(t_config *config, t_loc *stack)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	config->top_moves = -1;
	config->bot_moves = 0;
	i = find_top_moves_nbr(stack, config);
	j = find_bot_moves_nbr(stack, config);
	if (i == 0 && j == 0)
		return (0);
	return (1);
}

int	find_top_moves_nbr(t_loc *stack, t_config *config)
{
	t_list	*node;

	if (!stack || lstsize(stack) == 1)
		return (0);
	node = stack->first;
	while (node->next != stack->first)
	{
		if (node->position < config->min || node->position > config->max)
			config->top_moves++;
		else
		{
			config->top_moves++;
			return (1);
		}
		node = node->next;
	}
	if (node->position < config->min || node->position > config->max)
		return (0);
	else
	{
		config->top_moves++;
		return (1);
	}
}

int	find_bot_moves_nbr(t_loc *stack, t_config *config)
{
	t_list	*node;

	if (!stack || lstsize(stack) == 1)
		return (0);
	node = stack->last;
	while (node->prev != stack->last)
	{
		if (node->position < config->min || node->position > config->max)
			config->bot_moves++;
		else
		{
			config->bot_moves++;
			return (1);
		}
		node = node->prev;
	}
	if (node->position < config->min || node->position > config->max)
		return (0);
	else
	{
		config->bot_moves++;
		return (1);
	}
}
