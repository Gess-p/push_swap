/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_a_nodes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpeixoto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 19:14:39 by gpeixoto          #+#    #+#             */
/*   Updated: 2026/01/13 10:04:54 by gpeixoto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	current_position(t_stack_node *stack)
{
	int	i;
	int	middle;

	i = 0;
	if (!stack)
		return ;
	middle = stack_len(stack) / 2;
	while (stack)
	{
		stack->position = i;
		if (i <= middle)
			stack->above_middle = true;
		else
			stack->above_middle = false;
		stack = stack->next;
		i++;
	}
}

void	set_a_target(t_stack_node *a, t_stack_node *b)
{
	t_stack_node	*current_b;
	t_stack_node	*target;
	long			best_match;

	while (a)
	{
		best_match = LONG_MIN;
		current_b = b;
		while (current_b)
		{
			if (current_b->value < a->value
				&& current_b->value > best_match)
			{
				best_match = current_b->value;
				target = current_b;
			}
			current_b = current_b->next;
		}
		if (best_match == LONG_MIN)
			a->target = find_biggest_node(b);
		else
			a->target = target;
		a = a->next;
	}
}

void	push_level(t_stack_node *a, t_stack_node *b)
{
	int	a_len;
	int	b_len;

	a_len = stack_len(a);
	b_len = stack_len(b);
	while (a)
	{
		a->level = a->position;
		if (!(a->above_middle))
			a->level = a_len - (a->position);
		if (a->target->above_middle)
			a->level += a->target->position;
		else
			a->level += b_len - (a->target->position);
		a = a->next;
	}
}

void	set_easiest(t_stack_node *stack)
{
	t_stack_node	*easiest_node;
	long			easiest_value;

	if (!stack)
		return ;
	easiest_value = LONG_MAX;
	while (stack)
	{
		if (stack->level < easiest_value)
		{
			easiest_value = stack->level;
			easiest_node = stack;
		}
		stack = stack->next;
	}
	easiest_node->easiest = true;
}

void	set_a_nodes(t_stack_node *a, t_stack_node *b)
{
	current_position(a);
	current_position(b);
	set_a_target(a, b);
	push_level(a, b);
	set_easiest(a);
}
