/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpeixoto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 11:44:34 by gpeixoto          #+#    #+#             */
/*   Updated: 2026/01/13 10:10:07 by gpeixoto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	is_sorted(t_stack_node *stack)
{
	if (!stack)
		return (1);
	while (stack->next)
	{
		if (stack->value > stack->next->value)
			return (false);
		stack = stack->next;
	}
	return (true);
}

t_stack_node	*find_last_node(t_stack_node *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next)
		stack = stack->next;
	return (stack);
}

void	add_node(t_stack_node **stack, int nbr)
{
	t_stack_node	*node;
	t_stack_node	*last_node;

	if (!stack)
		return ;
	node = malloc(sizeof(t_stack_node));
	if (!node)
		return ;
	node->next = NULL;
	node->value = nbr;
	node->easiest = false;
	if (!(*stack))
	{
		*stack = node;
		node->prev = NULL;
	}
	else
	{
		last_node = find_last_node(*stack);
		last_node->next = node;
		node->prev = last_node;
	}
}

int	stack_len(t_stack_node *stack)
{
	int	i;

	if (!stack)
		return (0);
	i = 0;
	while (stack)
	{
		stack = stack->next;
		i++;
	}
	return (i);
}

t_stack_node	*find_smallest(t_stack_node *stack)
{
	t_stack_node	*ptit_node;
	long			ptit_value;

	if (!stack)
		return (NULL);
	ptit_value = LONG_MAX;
	while (stack)
	{
		if (stack->value < ptit_value)
		{
			ptit_value = stack->value;
			ptit_node = stack;
		}
		stack = stack->next;
	}
	return (ptit_node);
}
