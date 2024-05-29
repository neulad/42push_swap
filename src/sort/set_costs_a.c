/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_costs_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukireyeu < ukireyeu@student.42warsaw.pl    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 17:44:56 by ukireyeu          #+#    #+#             */
/*   Updated: 2024/05/29 21:41:55 by ukireyeu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include "../stack/stack_len.h"

static void	index_stack(t_node *stack)
{
	int		i;
	int		len;

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

static int	count_regular_cost(t_node *node_a, int stack_a_len, int stack_b_len)
{
	if (node_a->above_median)
	{
		if (node_a->target_node->above_median)
			return (stack_a_len - node_a->index
				+ stack_b_len - node_a->target_node->index);
		else
			return (stack_a_len - node_a->index
				+node_a->target_node->index);
	}
	else
	{
		if (node_a->target_node->above_median)
			return (node_a->index
				+ stack_b_len - node_a->target_node->index);
		else
			return (node_a->index
				+ node_a->target_node->index);
	}
}

static void	set_cost(t_node *node_a, t_node *stack_a, t_node *stack_b)
{
	int	stack_a_len;
	int	stack_b_len;

	stack_a_len = stack_len(stack_a);
	stack_b_len = stack_len(stack_b);
	if (node_a->index == stack_a_len - 1
		&& node_a->target_node->index == stack_b_len - 1)
		node_a->push_cost = 1;
	else
		node_a->push_cost
			= count_regular_cost(node_a, stack_a_len, stack_b_len);
}

void	set_costs_a(t_node *stack_a, t_node *stack_b)
{
	t_node	*cstack_a;

	cstack_a = stack_a;
	index_stack(stack_b);
	while (stack_a)
	{
		set_cost(stack_a, cstack_a, stack_b);
		stack_a = stack_a->next;
	}
}
