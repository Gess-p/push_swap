/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpeixoto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 17:06:11 by gpeixoto          #+#    #+#             */
/*   Updated: 2026/01/13 15:10:43 by gpeixoto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>
# include <limits.h>

typedef struct s_stack_node
{
	int					value;
	int					position;
	int					level;
	bool				above_middle;
	bool				easiest;
	struct s_stack_node	*target;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
}		t_stack_node;

void			ptit_sort(t_stack_node **stack);
void			sort_stacks(t_stack_node **a, t_stack_node **b);
void			rotate_stacks(t_stack_node **a,
					t_stack_node **b, t_stack_node *easiest);
void			rev_stacks(t_stack_node **a,
					t_stack_node **b, t_stack_node *easiest);
void			push_to_b(t_stack_node **a, t_stack_node **b);
void			push_to_a(t_stack_node **a, t_stack_node **b);
void			smallest_to_top(t_stack_node **a);
int				repetition(t_stack_node *stack, int nbr);
int				syntax(char *str);
void			free_stack(t_stack_node **stack);
void			error_free(t_stack_node **stack);
char			**ft_split(char *str, char c);
void			pa(t_stack_node **a, t_stack_node **b);
void			pb(t_stack_node **b, t_stack_node **a);
void			rra(t_stack_node **a);
void			rrb(t_stack_node **b);
void			rrr(t_stack_node **a, t_stack_node **b);
void			ra(t_stack_node **a);
void			rb(t_stack_node **b);
void			rr(t_stack_node **a, t_stack_node **b);
void			sa(t_stack_node **a);
void			sb(t_stack_node **b);
void			ss(t_stack_node **a, t_stack_node **b);
void			current_position(t_stack_node *stack);
void			set_a_target(t_stack_node *a, t_stack_node *b);
void			push_level(t_stack_node *a, t_stack_node *b);
void			set_easiest(t_stack_node *stack);
void			set_a_nodes(t_stack_node *a, t_stack_node *b);
void			set_b_target(t_stack_node *a, t_stack_node *b);
void			set_b_nodes(t_stack_node *a, t_stack_node *b);
void			set_stack(t_stack_node **a, char **argv);
bool			is_sorted(t_stack_node *stack);
t_stack_node	*find_last_node(t_stack_node *stack);
void			add_node(t_stack_node **stack, int nbr);
int				stack_len(t_stack_node *stack);
t_stack_node	*find_smallest(t_stack_node *stack);
t_stack_node	*find_biggest_node(t_stack_node *stack);
t_stack_node	*find_easiest(t_stack_node *stack);
void			set_push(t_stack_node **stack, t_stack_node *top, char pile);
void			free_split(char **argv);

#endif
