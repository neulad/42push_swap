/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_targets_b.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukireyeu < ukireyeu@student.42warsaw.pl    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 12:30:10 by ukireyeu          #+#    #+#             */
/*   Updated: 2024/05/25 12:46:21 by ukireyeu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include "../stack/stack_len.h"
#include "../stack/find_min.h"
#include <limits.h>

static t_node	*find_closest_bigger(t_node *node_b, t_node *stack_a)
{
	t_node *min_node_a;
	long temp_nodes_diff;
	t_node *res;

	min_node_a = find_min(stack_a);
	temp_nodes_diff = LONG_MAX;
	while (stack_a)
	{
		if (node_b->nbr < stack_a->nbr && stack_a->nbr - node_b->nbr < temp_nodes_diff)
		{
			temp_nodes_diff = (long)(stack_a->nbr - node_b->nbr);
			res = stack_a;
		}
		stack_a = stack_a->next;
	}
	if (temp_nodes_diff == LONG_MAX)
		return (min_node_a);
	return (res);
}

void	set_tagrets_b(t_node *stack_b, t_node *stack_a)
{
	int	i;
	int	stack_b_len;

	i = 0;
	stack_b_len = stack_len(stack_b);
	while (stack_b)
	{
		stack_b->index = i;
		if (i == stack_b_len / 2 && stack_b_len % 2 != 0)
			stack_b->above_median = 0;
		else
			stack_b->above_median = i >= (stack_b_len / 2);
		stack_b->target_node = find_closest_bigger(stack_b, stack_a);
		stack_b = stack_b->next;
		++i;
	}
}
