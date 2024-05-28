/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukireyeu < ukireyeu@student.42warsaw.pl    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 18:49:49 by ukireyeu          #+#    #+#             */
/*   Updated: 2024/05/28 15:46:55 by ukireyeu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/libft.h"
#include "../lib/ft_printf.h"
#include "./push_swap.h"
#include "./utils/is_num.h"
#include "./stack/free_stack.h"
#include "./utils/ft_atol.h"
#include "./stack/find_last.h"
#include "./init_init.h"
#include "./utils/split_params.h"

int	check_argv(int argc, char **argv)
{
	int	len;

	len = 0;
	if (argc < 2 || !argv[1][0])
		return (0);
	while (argv[1][len])
		++len;
	if (argv[1][0] == ' ' || argv[1][len - 1] == ' ')
		return (0);
	return (1);
}

static int	is_duplicate(t_node *a, int n)
{
	if (!a)
		return (0);
	while (a)
	{
		if (a->nbr == n)
			return (1);
		a = a->next;
	}
	return (0);
}

static void	append_node(t_node **stack, int n)
{
	t_node	*node;
	t_node	*last_node;

	if (!stack)
		return ;
	node = malloc(sizeof(t_node));
	if (!node)
		return ;
	node->next = NULL;
	node->nbr = n;
	if (!(*stack))
	{
		*stack = node;
		node->prev = NULL;
	}
	else
	{
		last_node = find_last(*stack);
		last_node->next = node;
		node->prev = last_node;
	}
}

t_node	**fill_a(int argc, char **argv, t_node **stack_a)
{
	int		i;
	long	temp_nbr;
	int		flag_clean_argv;

	init_init(&i, &argc, &argv);
	if (argc == 1)
		set_argv_argc(&argc, &argv, &flag_clean_argv);
	while (i < argc)
	{
		if (!is_num(argv[i]))
			return (free_stack(stack_a), NULL);
		temp_nbr = ft_atol(argv[i]);
		if (temp_nbr > INT_MAX || temp_nbr < INT_MIN)
			return (free_stack(stack_a), NULL);
		if (is_duplicate(*stack_a, temp_nbr))
			return (free_stack(stack_a), NULL);
		append_node(stack_a, temp_nbr);
		++i;
	}
	if (flag_clean_argv)
		ft_free_words(argv);
	return (stack_a);
}
