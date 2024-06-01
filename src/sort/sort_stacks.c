/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukireyeu < ukireyeu@student.42warsaw.pl    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 14:29:30 by ukireyeu          #+#    #+#             */
/*   Updated: 2024/05/31 22:29:58 by ukireyeu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include "../stack/stack_len.h"
#include "../operations/push.h"
#include "../stack/is_sorted.h"
#include "../../lib/ft_printf.h"
#include "./set_targets_a.h"
#include "../sort/set_targets_b.h"
#include "./set_costs_a.h"
#include "./set_costs_b.h"
#include "../sort/push_cheapest_a.h"
#include "../sort/push_cheapest_b.h"
#include "../sort/sort_three.h"
#include "../stack/find_min.h"
#include "../operations/rotate.h"
#include "../operations/rev_rotate.h"

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
			stack->above_median = i > (len / 2);
		stack = stack->next;
		++i;
	}
}

static void	wrap_up(t_node **stack_a)
{
	while ((*stack_a)->nbr != find_min(*stack_a)->nbr)
	{
		if (find_min(*stack_a)->above_median)
			rra(stack_a);
		else
			ra(stack_a);
	}
}

void	sort_stacks(t_node **stack_a, t_node **stack_b)
{
	int		i;

	i = 0;
	while (i++ < 2 && stack_len(*stack_a) > 3)
		pb(stack_b, stack_a);
	while (stack_len(*stack_a) > 3)
	{
		set_tagrets_a(*stack_a, *stack_b);
		set_costs_a(*stack_a, *stack_b);
		push_cheapest_a(stack_a, stack_b);
	}
	sort_three(stack_a);
	while (stack_len(*stack_b))
	{
		set_tagrets_b(*stack_b, *stack_a);
		set_costs_b(*stack_b, *stack_a);
		push_cheapest_b(stack_b, stack_a);
	}
	index_stack(*stack_a);
	wrap_up(stack_a);
}
