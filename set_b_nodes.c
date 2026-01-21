/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_b_nodes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpeixoto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 19:14:39 by gpeixoto          #+#    #+#             */
/*   Updated: 2026/01/13 10:05:57 by gpeixoto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*void	current_position(t_stack_node **stack)
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
}*/

void	set_b_target(t_stack_node *a, t_stack_node *b)
{
	t_stack_node	*current_a;
	t_stack_node	*target;
	long			best_match;

	while (b)
	{
		best_match = LONG_MAX;
		current_a = a;
		while (current_a)
		{
			if (current_a->value > b->value
				&& current_a->value < best_match)
			{
				best_match = current_a->value;
				target = current_a;
			}
			current_a = current_a->next;
		}
		if (best_match == LONG_MAX)
			b->target = find_smallest(a);
		else
			b->target = target;
		b = b->next;
	}
}

/*void	push_level(t_stack_node *a, t_stack_node *b)
{
	int	a_len;
	int	b_len;

	a_len = stack_len(a);
	n_len = stack_len(b);
	while (b)
	{
		b->level = b->current_position;
		if (!(b->above_middle))
			b->level = b_len - (b->current_position);
		if (b->target->above_middle)
			b->level += b->target->current_position;
		else
			b->level += b_len - (b->target->current_position);
		b = b->next;
	}
}
*/
t_stack_node	*find_easiest(t_stack_node *stack)
{
	if (!stack)
		return (NULL);
	while (stack)
	{
		if (stack->easiest)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}

void	set_b_nodes(t_stack_node *a, t_stack_node *b)
{
	current_position(a);
	current_position(b);
	set_b_target(a, b);
}
