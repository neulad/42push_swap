/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrx_moves.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukireyeu < ukireyeu@student.42warsaw.pl    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 16:44:54 by ukireyeu          #+#    #+#             */
/*   Updated: 2024/05/28 13:37:10 by ukireyeu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "../push_swap.h"

void	a_rrx_moves(t_node **stack_a, t_node **stack_b, t_node *node);
void	b_rrx_moves(t_node **stack_b, t_node **stack_a, t_node *node);
