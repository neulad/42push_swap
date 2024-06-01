/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukireyeu < ukireyeu@student.42warsaw.pl    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 22:40:15 by ukireyeu          #+#    #+#             */
/*   Updated: 2024/06/01 13:21:26 by ukireyeu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/push_swap.h"
#include "../src/init.h"
#include "../src/stack/free_stack.h"
#include <stdlib.h>
#include "../src/stack/is_sorted.h"
#include "../get_next_line/get_next_line.h"
#include "../lib/libft.h"
#include "./silent_operations/push.h"
#include "./silent_operations/swap.h"
#include "./silent_operations/rev_rotate.h"
#include "./silent_operations/rotate.h"
#include "../lib/ft_printf.h"

static int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 && *s2)
	{
		if (*s1 != *s2)
			return (0);
		++s1;
		++s2;
	}
	return (1);
}

static int	run_operation(char *operation, t_node **stack_a, t_node **stack_b)
{
	if (ft_strcmp(operation, "pa"))
		silent_pa(stack_a, stack_b);
	else if (ft_strcmp(operation, "pb\n"))
		silent_pb(stack_b, stack_a);
	else if (ft_strcmp(operation, "sa\n"))
		silent_sa(stack_a);
	else if (ft_strcmp(operation, "sb\n"))
		silent_sa(stack_b);
	else if (ft_strcmp(operation, "ss\n"))
		silent_ss(stack_a, stack_b);
	else if (ft_strcmp(operation, "ra\n"))
		silent_ra(stack_a);
	else if (ft_strcmp(operation, "rb\n"))
		silent_rb(stack_b);
	else if (ft_strcmp(operation, "rr\n"))
		silent_rr(stack_a, stack_b);
	else if (ft_strcmp(operation, "rra\n"))
		silent_rra(stack_a);
	else if (ft_strcmp(operation, "rrb\n"))
		silent_rrb(stack_b);
	else if (ft_strcmp(operation, "rrr\n"))
		silent_rrr(stack_a, stack_b);
	else
		return (0);
	return (1);
}

static int	apply_operations(t_node **stack_a, t_node **stack_b)
{
	char	*s;

	while (1)
	{
		s = get_next_line(1);
		if (!s)
			break ;
		if (!s)
			return (1);
		if (!run_operation(s, stack_a, stack_b))
			return (free(s), 1);
		free(s);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_node	*stack_a;
	t_node	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (!check_argv(argc, argv))
		return (write(2, "Error\n", 6), 1);
	if (!fill_a(argc, argv, &stack_a))
		return (write(2, "Error\n", 6), 1);
	if (apply_operations(&stack_a, &stack_b))
		return (write(2, "Error\n", 6), 1);
	if (!is_sorted(stack_a) || stack_b != NULL)
		ft_printf("KO\n");
	else
		ft_printf("OK\n");
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
