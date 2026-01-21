/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpeixoto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 19:05:04 by gpeixoto          #+#    #+#             */
/*   Updated: 2026/01/13 09:48:10 by gpeixoto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_stacks(t_stack_node **a,
			t_stack_node **b, t_stack_node *easiest)
{
	while (*b != easiest->target && *a != easiest)
		rr(a, b);
	current_position(*a);
	current_position(*b);
}

void	rev_stacks(t_stack_node **a,
			t_stack_node **b, t_stack_node *easiest)
{
	while (*b != easiest->target && *a != easiest)
		rrr(a, b);
	current_position(*a);
	current_position(*b);
}

void	push_to_b(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*easiest;

	easiest = find_easiest(*a);
	if (easiest->above_middle && easiest->target->above_middle)
		rotate_stacks(a, b, easiest);
	else if (!(easiest->above_middle) && !(easiest->target->above_middle))
		rev_stacks(a, b, easiest);
	set_push(a, easiest, 'a');
	set_push(b, easiest->target, 'b');
	pb(b, a);
}

void	push_to_a(t_stack_node **a, t_stack_node **b)
{
	set_push(a, (*b)->target, 'a');
	pa(a, b);
}

void	smallest_to_top(t_stack_node **a)
{
	while ((*a)->value != find_smallest(*a)->value)
	{
		if (find_smallest(*a)->above_middle)
			ra(a);
		else
			rra(a);
	}
}
/*
void	sort_stacks(t_stack_node **a, t_stack_node **b)
{
	int	a_len;

	a_len = stack_len(*a);
	if ((a_len-- > 3) && !is_sorted(*a))
		pb(b,a, false);
	if ((a_len-- > 3) && !is_sorted(*a))
		pb(b,a, false);
	while (a_len-- > 3 && !is_sorted(*a))
	{
		init_a_nodes(*a, *b);
		push_to_b(a, b);
	}
	ptit_sort(a);
	while (*b)
	{
		init_b_nodes(*a, *b);
		push_to_a(a, b);
	}
	current_position(*a);
	smallest_to_top(a);
}*/
