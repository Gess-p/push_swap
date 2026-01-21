/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_cmd.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpeixoto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 13:13:37 by gpeixoto          #+#    #+#             */
/*   Updated: 2026/01/13 09:58:58 by gpeixoto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	reverse_rotate(t_stack_node **stack)
{
	t_stack_node	*last_node;

	if (stack == NULL || *stack == NULL || !(*stack)->next)
		return ;
	last_node = find_last_node(*stack);
	last_node->next = *stack;
	last_node->prev->next = NULL;
	last_node->next->prev = last_node;
	last_node->prev = NULL;
	*stack = last_node;
}

void	rra(t_stack_node **a)
{
	reverse_rotate(a);
	write(1, "rra\n", 4);
}

void	rrb(t_stack_node **b)
{
	reverse_rotate(b);
	write(1, "rrb\n", 4);
}

void	rrr(t_stack_node **a, t_stack_node **b)
{
	reverse_rotate(a);
	reverse_rotate(b);
	write(1, "rrr\n", 4);
}
