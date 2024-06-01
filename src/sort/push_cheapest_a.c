/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_cheapest_a.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukireyeu < ukireyeu@student.42warsaw.pl    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 10:28:43 by ukireyeu          #+#    #+#             */
/*   Updated: 2024/05/31 22:33:41 by ukireyeu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include "../stack/stack_len.h"
#include "../operations/push.h"
#include "../operations/rotate.h"
#include "../operations/rev_rotate.h"
#include "./op_times.h"
#include "../sort/rrx_moves.h"
#include <limits.h>

static void	index_stack(t_node *stack)
{
	int	i;
	int	len;

	i = 0;
	len = stack_len(stack);
	while (stack)
	{
		stack->index = i;
		if (i == len / 2 && len % 2 != 0)
			stack->above_median = 0;
		else
			stack->above_median = i >= (len / 2);
		stack = stack->next;
		++i;
	}
}

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

static void	save_costs(t_node *cheapest_node,
	t_node **stack_a,
	t_node **stack_b)
{
	if (cheapest_node->above_median
		&& cheapest_node->target_node->above_median)
	{
		while (cheapest_node->index != 0
			&& cheapest_node->target_node->index != 0)
		{
			rrr(stack_a, stack_b);
			index_stack(*stack_a);
			index_stack(*stack_b);
		}
	}
	else if (!cheapest_node->above_median
		&& !cheapest_node->target_node->above_median)
	{
		while (cheapest_node->index != 0
			&& cheapest_node->target_node->index != 0)
		{
			rr(stack_a, stack_b);
			index_stack(*stack_a);
			index_stack(*stack_b);
		}
	}
}

static void	a_rra_rb_moves(t_node *cheapest_node,
	t_node **stack_a,
	t_node **stack_b)
{
	rra_moves(stack_a, cheapest_node);
	rb_moves(stack_b, cheapest_node->target_node);
}

void	push_cheapest_a(t_node **stack_a, t_node **stack_b)
{
	t_node	*cheapest_node;

	cheapest_node = find_cheapest(*stack_a);
	save_costs(cheapest_node, stack_a, stack_b);
	if (cheapest_node->above_median)
		if (cheapest_node->target_node->above_median)
			a_rrx_moves(stack_a, stack_b, cheapest_node);
	else
		a_rra_rb_moves(cheapest_node, stack_a, stack_b);
	else
	{
		if (cheapest_node->target_node->above_median)
		{
			ra_moves(stack_a, cheapest_node);
			rrb_moves(stack_b, cheapest_node->target_node);
		}
		else
		{
			ra_moves(stack_a, cheapest_node);
			rb_moves(stack_b, cheapest_node->target_node);
		}
	}
	pb(stack_b, stack_a);
}
