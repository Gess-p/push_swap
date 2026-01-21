/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpeixoto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 21:48:56 by gpeixoto          #+#    #+#             */
/*   Updated: 2026/01/13 09:51:35 by gpeixoto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	repetition(t_stack_node *stack, int nbr)
{
	if (!stack)
		return (0);
	while (stack)
	{
		if (stack->value == nbr)
			return (1);
		stack = stack->next;
	}
	return (0);
}

int	syntax(char *str)
{
	while (*str)
	{
		if (!(*str == '+' || *str == '-' || (*str >= '0' && *str <= '9')))
			return (1);
		if ((*str == '+' || *str == '-') && !(str[1] >= '0' && str[1] <= '9'))
			return (1);
		str++;
	}
	return (0);
}

void	free_split(char **argv)
{
	int	i;

	if (!argv)
		return ;
	i = 0;
	while (argv[i])
	{
		free(argv[i++]);
	}
	free(argv);
}

void	free_stack(t_stack_node **stack)
{
	t_stack_node	*tmp;
	t_stack_node	*current;

	if (!stack)
		return ;
	current = *stack;
	while (current)
	{
		tmp = current->next;
		current->value = 0;
		free(current);
		current = tmp;
	}
	*stack = NULL;
}

void	error_free(t_stack_node **stack)
{
	free_stack(stack);
	write(1, "Error\n", 6);
	exit(1);
}
