/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_times.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukireyeu < ukireyeu@student.42warsaw.pl    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 16:30:35 by ukireyeu          #+#    #+#             */
/*   Updated: 2024/05/28 15:57:20 by ukireyeu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "../push_swap.h"

void	ra_moves(t_node **stack_a, t_node *node);
void	rra_moves(t_node **stack_a, t_node *node);
void	rb_moves(t_node **stack_b, t_node *node);
void	rrb_moves(t_node **stack_b, t_node *node);
