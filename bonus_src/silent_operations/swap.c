/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukireyeu < ukireyeu@student.42warsaw.pl    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 12:58:25 by ukireyeu          #+#    #+#             */
/*   Updated: 2024/06/01 00:57:13 by ukireyeu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../src/push_swap.h"
#include "../../lib/ft_printf.h"
#include <stdlib.h>

static void	swap(t_node **head)
{
	if (!*head || !(*head)->next)
		return ;
	*head = (*head)->next;
	(*head)->prev->prev = *head;
	(*head)->prev->next = (*head)->next;
	if ((*head)->next)
		(*head)->next->prev = (*head)->prev;
	(*head)->next = (*head)->prev;
	(*head)->prev = NULL;
}

void	silent_sa(t_node **a)
{
	swap(a);
}

void	silent_sb(t_node **b)
{
	swap(b);
}

void	silent_ss(t_node **a, t_node **b)
{
	swap(a);
	swap(b);
}
