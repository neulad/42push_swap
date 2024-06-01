/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukireyeu < ukireyeu@student.42warsaw.pl    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 13:15:49 by ukireyeu          #+#    #+#             */
/*   Updated: 2024/06/01 00:57:53 by ukireyeu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../src/push_swap.h"
#include "../../src/stack/find_last.h"
#include "../../lib/ft_printf.h"
#include <stdlib.h>

static void	rev_rotate(t_node **stack)
{
	t_node	*last;

	if (!*stack || !(*stack)->next)
		return ;
	last = find_last(*stack);
	last->prev->next = NULL;
	last->next = *stack;
	last->prev = NULL;
	*stack = last;
	last->next->prev = last;
}

void	silent_rra(t_node **a)
{
	rev_rotate(a);
}

void	silent_rrb(t_node **b)
{
	rev_rotate(b);
}

void	silent_rrr(t_node **a, t_node **b)
{
	rev_rotate(a);
	rev_rotate(b);
}
