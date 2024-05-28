/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukireyeu < ukireyeu@student.42warsaw.pl    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 18:34:06 by ukireyeu          #+#    #+#             */
/*   Updated: 2024/05/28 15:34:24 by ukireyeu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/ft_printf.h"
#include "./init.h"
#include "./push_swap.h"
#include "./stack/is_sorted.h"
#include "./stack/stack_len.h"
#include "./sort/sort_three.h"
#include "./operations/swap.h"
#include "./sort/sort_stacks.h"
#include "./stack/free_stack.h"

int	main(int argc, char **argv)
{
	t_node	*stack_a;
	t_node	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (!check_argv(argc, argv))
	{
		write(2, "Error\n", 6);
		return (1);
	}
	if (!fill_a(argc, argv, &stack_a))
	{
		write(2, "Error\n", 6);
		return (1);
	}
	if (!is_sorted(stack_a))
	{
		if (stack_len(stack_a) == 2)
			sa(&stack_a);
		else if (stack_len(stack_a) == 3)
			sort_three(&stack_a);
		else
			sort_stacks(&stack_a, &stack_b);
	}
	return (free_stack(&stack_a), 0);
}
