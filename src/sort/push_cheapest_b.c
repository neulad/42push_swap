/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_cheapest_b.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukireyeu < ukireyeu@student.42warsaw.pl    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 13:13:49 by ukireyeu          #+#    #+#             */
/*   Updated: 2024/05/29 21:43:40 by ukireyeu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include "../stack/stack_len.h"
#include "../operations/push.h"
#include "../operations/rev_rotate.h"
#include "./op_times.h"
#include "./rrx_moves.h"
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

static int	check_rrr_b(t_node *cheapest_node, t_node *stack_b, t_node *stack_a)
{
	int	stack_a_len;
	int	stack_b_len;

	stack_a_len = stack_len(stack_a);
	stack_b_len = stack_len(stack_b);
	if (cheapest_node->index == stack_b_len - 1
		&& cheapest_node->target_node->index == stack_a_len - 1)
		return (1);
	return (0);
}

static void	b_rrb_ra_moves(t_node *cheapest_node,
	t_node **stack_b,
	t_node **stack_a)
{
	rrb_moves(stack_b, cheapest_node);
	ra_moves(stack_a, cheapest_node->target_node);
}

void	push_cheapest_b(t_node **stack_b, t_node **stack_a)
{
	t_node	*cheapest_node;

	cheapest_node = find_cheapest(*stack_b);
	if (check_rrr_b(cheapest_node, *stack_b, *stack_a))
		rrr(stack_a, stack_b);
	else if (cheapest_node->above_median)
		if (cheapest_node->target_node->above_median)
			b_rrx_moves(stack_b, stack_a, cheapest_node);
	else
		b_rrb_ra_moves(cheapest_node, stack_b, stack_a);
	else
	{
		if (cheapest_node->target_node->above_median)
		{
			rb_moves(stack_b, cheapest_node);
			rra_moves(stack_a, cheapest_node->target_node);
		}
		else
		{
			rb_moves(stack_b, cheapest_node);
			ra_moves(stack_a, cheapest_node->target_node);
		}
	}
	pa(stack_a, stack_b);
}
