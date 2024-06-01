/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_costs_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukireyeu < ukireyeu@student.42warsaw.pl    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 17:44:56 by ukireyeu          #+#    #+#             */
/*   Updated: 2024/05/31 22:29:48 by ukireyeu         ###   ########.fr       */
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

static int	get_saved_cost(int len_to_edge_a, int len_to_edge_b)
{
	if (len_to_edge_a < len_to_edge_b)
		return (len_to_edge_a);
	else
		return (len_to_edge_b);
}

static void	set_cost(t_node *node_a, t_node *stack_a, t_node *stack_b)
{
	int	saved_cost;
	int	len_to_edge_a;
	int	len_to_edge_b;

	saved_cost = 0;
	if (node_a->above_median && node_a->target_node->above_median)
	{
		len_to_edge_a = stack_len(stack_a) - node_a->index;
		len_to_edge_b = stack_len(stack_b) - node_a->target_node->index;
		saved_cost = get_saved_cost(len_to_edge_a, len_to_edge_b);
	}
	else if (!node_a->above_median && !node_a->target_node->above_median)
	{
		len_to_edge_a = node_a->index;
		len_to_edge_b = node_a->target_node->index;
		saved_cost = get_saved_cost(len_to_edge_a, len_to_edge_b);
	}
	node_a->push_cost
		= count_regular_cost(node_a, stack_len(stack_a), stack_len(stack_b))
		- saved_cost;
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
