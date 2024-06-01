/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_costs_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukireyeu < ukireyeu@student.42warsaw.pl    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 12:47:52 by ukireyeu          #+#    #+#             */
/*   Updated: 2024/05/31 22:29:02 by ukireyeu         ###   ########.fr       */
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

static int	get_saved_cost(int len_to_edge_b, int len_to_edge_a)
{
	if (len_to_edge_a < len_to_edge_b)
		return (len_to_edge_a);
	else
		return (len_to_edge_b);
}

static void	set_cost(t_node *node_b, t_node *stack_b, t_node *stack_a)
{
	int	saved_cost;
	int	len_to_edge_b;
	int	len_to_edge_a;

	saved_cost = 0;
	if (node_b->above_median && node_b->target_node->above_median)
	{
		len_to_edge_b = stack_len(stack_b) - node_b->index;
		len_to_edge_a = stack_len(stack_a) - node_b->target_node->index;
		saved_cost = get_saved_cost(len_to_edge_b, len_to_edge_a);
	}
	else if (!node_b->above_median && !node_b->target_node->above_median)
	{
		len_to_edge_b = node_b->index;
		len_to_edge_a = node_b->target_node->index;
		saved_cost = get_saved_cost(len_to_edge_b, len_to_edge_a);
	}
	node_b->push_cost
		= count_regular_cost(node_b, stack_len(stack_b),
			stack_len(stack_a)) - saved_cost;
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
