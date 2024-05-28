/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukireyeu < ukireyeu@student.42warsaw.pl    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 13:27:18 by ukireyeu          #+#    #+#             */
/*   Updated: 2024/05/28 15:54:40 by ukireyeu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include "../stack/is_sorted.h"
#include "../stack/find_max.h"
#include "../operations/rotate.h"
#include "../operations/rev_rotate.h"
#include "../stack/find_last.h"
#include "../operations/swap.h"

void	sort_three(t_node **stack_a)
{
	t_node	*max_node;

	max_node = find_max(*stack_a);
	if (*stack_a == max_node)
		ra(stack_a);
	else if ((*stack_a)->next == max_node)
		rra(stack_a);
	if ((*stack_a)->nbr > (*stack_a)->next->nbr)
		sa(stack_a);
}
