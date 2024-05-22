/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukireyeu < ukireyeu@student.42warsaw.pl    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 18:34:06 by ukireyeu          #+#    #+#             */
/*   Updated: 2024/05/22 18:51:35 by ukireyeu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/ft_printf.h"
#include "./init.h"
#include "./push_swap.h"

int	main(int argc, char **argv)
{
	t_node	*stack_a;
	t_node	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (!check_argv(argc, argv))
	{
		ft_printf("Error\n");
		return (1);
	}
	if (!fill_a(argc, argv, &stack_a))
	{
		ft_printf("Error\n");
		return (1);
	}
	return (0);
}
