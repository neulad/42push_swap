/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukireyeu < ukireyeu@student.42warsaw.pl    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 13:23:48 by ukireyeu          #+#    #+#             */
/*   Updated: 2024/06/01 00:58:11 by ukireyeu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../src/push_swap.h"
#include "../../lib/ft_printf.h"
#include "../../src/stack/find_last.h"
#include <stdlib.h>

static void	rotate(t_node **stack)
{
	t_node	*last_node;

	if (!*stack || !(*stack)->next)
		return ;
	last_node = find_last(*stack);
	last_node->next = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	last_node->next->prev = last_node;
	last_node->next->next = NULL;
}

void	silent_ra(t_node **a)
{
	rotate(a);
}

void	silent_rb(t_node **b)
{
	rotate(b);
}

void	silent_rr(t_node **a, t_node **b)
{
	rotate(a);
	rotate(b);
}
