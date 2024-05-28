/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_times.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukireyeu < ukireyeu@student.42warsaw.pl    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 16:14:01 by ukireyeu          #+#    #+#             */
/*   Updated: 2024/05/25 16:53:47 by ukireyeu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include "../operations/rev_rotate.h"
#include "../operations/rotate.h"
#include "../stack/stack_len.h"

void ra_moves(t_node **stack_a, t_node *node)
{
	int i;

	i = 0;
	while (i < node->index)
	{
		ra(stack_a);
		++i;
	}
}

void rra_moves(t_node **stack_a, t_node *node)
{
	int initial_len;
	int i;
	int n_moves;

	initial_len = stack_len(*stack_a);
	i = 0;
	n_moves = initial_len - node->index;
	while (i < n_moves)
	{
		rra(stack_a);
		++i;
	}
}

void rb_moves(t_node **stack_b, t_node *node)
{
	int i;

	i = 0;
	while (i < node->index)
	{
		rb(stack_b);
		++i;
	}
}

void rrb_moves(t_node **stack_b, t_node *node)
{
	int initial_len;
	int i;
	int n_moves;

	initial_len = stack_len(*stack_b);
	i = 0;
	n_moves = initial_len - node->index;
	while (i < n_moves)
	{
		rrb(stack_b);
		++i;
	}
}
