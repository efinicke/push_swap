/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   03_lst_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efinicke <efinicke@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 17:24:39 by efinicke          #+#    #+#             */
/*   Updated: 2021/09/13 12:07:25 by efinicke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

/*
** autres fonctions de type lst :
*/
int	lstsize(t_loc *stack)
{
	int		i;
	t_list	*tmp;

	i = 0;
	tmp = stack->first;
	while (tmp != stack->last)
	{
		tmp = tmp->next;
		i++;
	}
	i++;
	return (i);
}

void	lstclear(t_loc *stack)
{
	t_list	*tmp;

	while (stack->first != stack->last)
	{
		tmp = stack->first;
		stack->first = tmp->next;
		free(tmp);
	}
	free(stack->first);
	tmp = NULL;
}
