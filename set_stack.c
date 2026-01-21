/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_stack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpeixoto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 12:28:54 by gpeixoto          #+#    #+#             */
/*   Updated: 2026/01/16 16:47:08 by gpeixoto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static long	ft_atol(const char *str)
{
	unsigned long	nbr;
	int				sign;

	nbr = 0;
	sign = 1;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		nbr = (nbr * 10) + (*str - '0');
		str++;
	}
	if (sign == 1 && nbr > LONG_MAX)
		return (-1);
	if (sign == -1 && nbr > LONG_MAX)
		return (0);
	return (sign * nbr);
}

void	set_push(t_stack_node **stack, t_stack_node *top, char pile)
{
	while (*stack != top)
	{
		if (pile == 'a')
		{
			if (top->above_middle)
				ra(stack);
			else
				rra(stack);
		}
		else if (pile == 'b')
		{
			if (top->above_middle)
				rb(stack);
			else
				rrb(stack);
		}
	}
}

void	set_stack(t_stack_node **a, char **argv)
{
	long	nbr;
	int		i;

	i = 0;
	while (argv[i])
	{
		if (syntax(argv[i]))
			error_free(a);
		nbr = ft_atol(argv[i]);
		if (nbr > INT_MAX || nbr < INT_MIN)
			error_free(a);
		if (repetition(*a, (int)nbr))
			error_free(a);
		add_node(a, (int)nbr);
		i++;
	}
}
