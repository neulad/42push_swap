/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukireyeu < ukireyeu@student.42warsaw.pl    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 12:43:43 by ukireyeu          #+#    #+#             */
/*   Updated: 2024/05/23 14:19:36 by ukireyeu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	is_sorted(t_node *stack)
{
	int	max_nbr;

	max_nbr = stack->nbr;
	while (stack)
	{
		if (stack->nbr < max_nbr)
			return (0);
		max_nbr = stack->nbr;
		stack = stack->next;
	}
	return (1);
}
