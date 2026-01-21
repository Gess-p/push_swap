/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpeixoto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 14:14:44 by gpeixoto          #+#    #+#             */
/*   Updated: 2026/01/13 10:10:47 by gpeixoto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_stack_node **stack)
{
	t_stack_node	*top;
	t_stack_node	*second;

	if (!stack || !(*stack) || !(*stack)->next)
		return ;
	top = *stack;
	second = (*stack)->next;
	*stack = second;
	top->next = second->next;
	second->next = top;
	second->prev = NULL;
	top->prev = second;
	if (top->next != NULL)
		top->next->prev = top;
}

void	sa(t_stack_node **a)
{
	swap(a);
	write(1, "sa\n", 3);
}

void	sb(t_stack_node **b)
{
	swap(b);
	write(1, "sb\n", 3);
}

void	ss(t_stack_node **a, t_stack_node **b)
{
	swap(a);
	swap(b);
	write(1, "ss\n", 3);
}
