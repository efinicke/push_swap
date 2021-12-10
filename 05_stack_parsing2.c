/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   05_stack_parsing2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efinicke <efinicke@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 17:39:34 by efinicke          #+#    #+#             */
/*   Updated: 2021/09/17 12:18:10 by efinicke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	define_chunks_nbr(int len)
{
	int	chunk_size;
	int	chunk_nb;
	int	nbr;

	chunk_nb = 1;
	chunk_size = len;
	nbr = 18;
	if (len > 350)
		nbr = 37;
	while (chunk_size > nbr)
	{
		chunk_nb ++;
		chunk_size = len / chunk_nb;
	}
	return (chunk_nb);
}

void	chunks_config(t_config *config, t_loc *stack_a)
{
	config->stack_sz = lstsize(stack_a);
	config->chunk_nb = define_chunks_nbr(lstsize(stack_a));
	config->chunk_sz = (config->stack_sz) / (config->chunk_nb);
	config->rest = (config->stack_sz) % (config->chunk_nb);
	config->min = 1;
	config->max = (config->rest + config->chunk_sz);
	config->top_moves = -1;
	config->bot_moves = 0;
}

void	define_chunk_limits(t_config *config, int chunk)
{
	if (chunk != config->chunk_nb)
	{
		config->max += config->chunk_sz;
		config->min = (config->max - config->chunk_sz + 1);
	}
}
