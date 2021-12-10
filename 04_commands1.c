/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   04_commands1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efinicke <efinicke@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 17:29:09 by efinicke          #+#    #+#             */
/*   Updated: 2021/09/13 18:26:40 by efinicke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static void	print_command(int i, char *str)
{
	if (i == 1)
	{
		ft_putstr(str);
		ft_putstr("\n");
	}
}

static int	command_annex(t_loc *stack_a, t_loc *stack_b, char *str)
{
	int	i;

	i = 0;
	if (ft_strcmp(str, "rrb") == 0)
		i = rra_rrb(stack_b);
	else if (ft_strcmp(str, "rrr") == 0)
		i = rrr(stack_a, stack_b);
	return (i);
}

void	command(t_loc *stack_a, t_loc *stack_b, char *str)
{
	int		i;

	i = 0;
	if (ft_strcmp(str, "sa") == 0)
		i = sa_sb(stack_a);
	else if (ft_strcmp(str, "sb") == 0)
		i = sa_sb(stack_b);
	else if (ft_strcmp(str, "ss") == 0)
		i = ss(stack_a, stack_b);
	else if (ft_strcmp(str, "pa") == 0)
		i = pa_pb(stack_b, stack_a);
	else if (ft_strcmp(str, "pb") == 0)
		i = pa_pb(stack_a, stack_b);
	else if (ft_strcmp(str, "ra") == 0)
		i = ra_rb(stack_a);
	else if (ft_strcmp(str, "rb") == 0)
		i = ra_rb(stack_b);
	else if (ft_strcmp(str, "rr") == 0)
		i = rr(stack_a, stack_b);
	else if (ft_strcmp(str, "rra") == 0)
		i = rra_rrb(stack_a);
	else
		i = command_annex(stack_a, stack_b, str);
	print_command(i, str);
}

int	sa_sb(t_loc *stack)
{
	t_list	*nz;
	t_list	*n1;
	t_list	*n2;
	t_list	*n3;

	if (!stack)
		return (0);
	if (stack && lstsize(stack) > 2)
	{
		nz = stack->last;
		n1 = stack->first;
		n2 = stack->first->next;
		n3 = stack->first->next->next;
		n1->next = n3;
		n1->prev = n2;
		n2->next = n1;
		n2->prev = nz;
		nz->next = n2;
		n3->prev = n1;
		stack->first = stack->first->prev;
	}
	else if (stack && (lstsize(stack) == 2))
		ra_rb(stack);
	return (1);
}

/*
 ** swap (sa_sb) en binaire : 
 **
 **void    swap(t_list **stack)
 **{
 **    if (*stack && (*stack)->next)
 **    {
 **        (*stack)->content = (*stack)->content ^ (*stack)->next->content;
 **        (*stack)->next->content = (*stack)->content ^ (*stack)->next->content;
 **        (*stack)->content = (*stack)->content ^ (*stack)->next->content;
 **    }
 **}
 */

int	ss(t_loc *stack_a, t_loc *stack_b)
{
	if (stack_a && stack_b)
	{
		if (lstsize(stack_a) >= 2 || lstsize(stack_b) >= 2 )
		{
			sa_sb(stack_a);
			sa_sb(stack_b);
			return (1);
		}
	}
	return (0);
}
