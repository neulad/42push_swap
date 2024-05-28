/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_cheapest_a.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukireyeu < ukireyeu@student.42warsaw.pl    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 10:28:43 by ukireyeu          #+#    #+#             */
/*   Updated: 2024/05/28 15:57:53 by ukireyeu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include "../stack/stack_len.h"
#include "../operations/push.h"
#include "../operations/rev_rotate.h"
#include "./op_times.h"
#include "../sort/rrx_moves.h"
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

void	push_cheapest_a(t_node **stack_a, t_node **stack_b)
{
	t_node	*cheapest_node;

	cheapest_node = find_cheapest(*stack_a);
	if (cheapest_node->above_median)
		if (cheapest_node->target_node->above_median)
			a_rrx_moves(stack_a, stack_b, cheapest_node);
	else
	{
		rra_moves(stack_a, cheapest_node);
		rb_moves(stack_b, cheapest_node->target_node);
	}
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
