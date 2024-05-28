/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrx_moves.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukireyeu < ukireyeu@student.42warsaw.pl    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 16:44:57 by ukireyeu          #+#    #+#             */
/*   Updated: 2024/05/28 15:58:08 by ukireyeu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include "./op_times.h"

void	a_rrx_moves(t_node **stack_a, t_node **stack_b, t_node *node)
{
	rra_moves(stack_a, node);
	rrb_moves(stack_b, node->target_node);
}

void	b_rrx_moves(t_node **stack_b, t_node **stack_a, t_node *node)
{
	rrb_moves(stack_b, node);
	rra_moves(stack_a, node->target_node);
}
