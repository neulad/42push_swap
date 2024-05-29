/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_costs_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukireyeu < ukireyeu@student.42warsaw.pl    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 12:47:52 by ukireyeu          #+#    #+#             */
/*   Updated: 2024/05/29 21:42:04 by ukireyeu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include "../stack/stack_len.h"

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

static int	count_regular_cost(t_node *node_b, int stack_b_len, int stack_a_len)
{
	if (node_b->above_median)
	{
		if (node_b->target_node->above_median)
			return (stack_b_len - node_b->index
				+ stack_a_len - node_b->target_node->index);
		else
			return (stack_b_len - node_b->index + node_b->target_node->index);
	}
	else
	{
		if (node_b->target_node->above_median)
			return (node_b->index + stack_a_len - node_b->target_node->index);
		else
			return (node_b->index + node_b->target_node->index);
	}
}

static void	set_cost(t_node *node_b, t_node *stack_b, t_node *stack_a)
{
	int	stack_a_len;
	int	stack_b_len;

	stack_a_len = stack_len(stack_a);
	stack_b_len = stack_len(stack_b);
	if (node_b->index == stack_b_len - 1
		&& node_b->target_node->index == stack_a_len - 1)
		node_b->push_cost = 1;
	else
		node_b->push_cost
			= count_regular_cost(node_b, stack_b_len, stack_a_len);
}

void	set_costs_b(t_node *stack_b, t_node *stack_a)
{
	t_node	*cstack_b;

	cstack_b = stack_b;
	index_stack(stack_a);
	while (stack_b)
	{
		set_cost(stack_b, cstack_b, stack_a);
		stack_b = stack_b->next;
	}
}
