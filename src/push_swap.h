/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukireyeu < ukireyeu@student.42warsaw.pl    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 18:34:16 by ukireyeu          #+#    #+#             */
/*   Updated: 2024/05/28 15:48:46 by ukireyeu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

typedef struct s_node
{
	int				index;
	int				nbr;
	int				push_cost;
	int				above_median;

	struct s_node	*target_node;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;
