/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukireyeu < ukireyeu@student.42warsaw.pl    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 18:34:16 by ukireyeu          #+#    #+#             */
/*   Updated: 2024/05/22 18:23:46 by ukireyeu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <stdbool.h>

typedef struct s_node
{
	int		index;
	int		nbr;
	int		push_cost;
	bool	above_median;
	bool	cheapest;

	struct s_node	*target_node;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;
