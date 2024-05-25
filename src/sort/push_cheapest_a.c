/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_cheapest_a.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukireyeu < ukireyeu@student.42warsaw.pl    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 10:28:43 by ukireyeu          #+#    #+#             */
/*   Updated: 2024/05/25 11:57:31 by ukireyeu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include "../stack/stack_len.h"
#include "../operations/rev_rotate.h"
#include "../operations/rotate.h"
#include "../operations/push.h"
#include <limits.h>

static t_node	*find_cheapest(t_node *stack_a)
{
	int		min;
	t_node	*cheapest_node;

	min = INT_MAX;
	while (stack_a)
	{
		if (stack_a->push_cost < min)
		{
			cheapest_node = stack_a;
			min = stack_a->push_cost;
		}
		stack_a = stack_a->next;
	}
	return (cheapest_node);
}

static void	ra_moves(t_node **stack, t_node *node)
{
	int	i;

	i = 0;
	while (i < node->index)
	{
		ra(stack);
		++i;
	}
}

static void	rra_moves(t_node **stack, t_node *node)
{
	int	initial_len;
	int	i;
	int	n_moves;


	initial_len = stack_len(*stack);
	i = 0;
	n_moves = initial_len - node->index;
	while (i < n_moves)
	{
		rra(stack);
		++i;
	}
}

static void	rra_moves_double(t_node **stack_a, t_node **stack_b, t_node *node_a)
{
	rra_moves(stack_a, node_a);
	rra_moves(stack_b, node_a->target_node);
}

void	push_cheapest(t_node **stack_a, t_node **stack_b)
{
	t_node	*cheapest_node;

	cheapest_node = find_cheapest(*stack_a);
	if (cheapest_node->above_median)
		if (cheapest_node->target_node->above_median)
			rra_moves_double(stack_a, stack_b, cheapest_node);
		else
		{
			rra_moves(stack_a, cheapest_node);
			ra_moves(stack_b, cheapest_node->target_node);
		}
	else
		if (cheapest_node->target_node->above_median)
		{
			ra_moves(stack_a, cheapest_node);
			rra_moves(stack_b, cheapest_node->target_node);
		}
		else
		{
			ra_moves(stack_a, cheapest_node);
			ra_moves(stack_b, cheapest_node->target_node);
		}
	pb(stack_b, stack_a);
}
