/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukireyeu < ukireyeu@student.42warsaw.pl    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 14:29:30 by ukireyeu          #+#    #+#             */
/*   Updated: 2024/05/24 19:07:11 by ukireyeu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include "../stack/stack_len.h"
#include "../operations/push.h"
#include "../stack/is_sorted.h"
#include "../../lib/ft_printf.h"
#include "./set_targets_a.h"
#include "./set_costs_a.h"

void	sort_stacks(t_node *stack_a, t_node *stack_b)
{
	int		i;

	i = 0;
	while (i++ < 2 && stack_len(stack_a) > 3)
		pb(&stack_b, &stack_a);
	// while (stack_len(stack_a) > 3)
	// {
	set_tagrets_a(stack_a, stack_b);
	set_costs(stack_a, stack_b);
	while (stack_a)
	{
		ft_printf("cost for %d - %d\n", stack_a->nbr, stack_a->push_cost);
		stack_a = stack_a->next;
	}
	// }
}
