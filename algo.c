/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpeixoto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 14:21:11 by gpeixoto          #+#    #+#             */
/*   Updated: 2026/01/13 12:11:41 by gpeixoto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack_node	*find_biggest_node(t_stack_node *stack)
{
	long			biggest;
	t_stack_node	*big_node;

	if (!stack)
		return (NULL);
	biggest = LONG_MIN;
	while (stack)
	{
		if (stack->value > biggest)
		{
			biggest = stack->value;
			big_node = stack;
		}
		stack = stack->next;
	}
	return (big_node);
}

void	ptit_sort(t_stack_node **stack)
{
	t_stack_node	*biggest;

	biggest = find_biggest_node(*stack);
	if (*stack == biggest)
		ra(stack);
	else if ((*stack)->next == biggest)
		rra(stack);
	if ((*stack)->value > (*stack)->next->value)
		sa(stack);
}

void	sort_stacks(t_stack_node **a, t_stack_node **b)
{
	int	a_len;

	a_len = stack_len(*a);
	if (a_len-- > 3 && !is_sorted(*a))
		pb(b, a);
	if (a_len-- > 3 && !is_sorted(*a))
		pb(b, a);
	while (a_len-- > 3 && !is_sorted(*a))
	{
		set_a_nodes(*a, *b);
		push_to_b(a, b);
	}
	ptit_sort(a);
	while (*b)
	{
		set_b_nodes(*a, *b);
		push_to_a(a, b);
	}
	current_position(*a);
	smallest_to_top(a);
}
