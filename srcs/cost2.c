/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-dref <tle-dref@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 17:20:08 by tle-dref          #+#    #+#             */
/*   Updated: 2024/10/29 01:13:19 by tle-dref         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	total_move_cost(t_move move)
{
	return (move.ra + move.rb + move.rra + move.rrb + move.rr + move.rrr);
}

void	assign_indices(t_stack *a)
{
	t_node	*current;
	int		index;

	current = a->top;
	index = 0;
	while (current)
	{
		current->index = index++;
		current = current->next;
	}
}

t_move	find_cheapest(t_stack *a, t_stack *b)
{
	int		min_cost;
	t_move	cheapest;
	t_node	*current;
	t_move	move;
	int		pos_b;

	pos_b = 0;
	min_cost = 2147483647;
	current = a->top;
	ft_memset(&cheapest, 0, sizeof(t_move));
	assign_indices(a);
	while (current)
	{
		pos_b = find_pos_b(current->value, b);
		move = efficient_move(move_cost(a, b, pos_b, current->index));
		move.cost = total_move_cost(move);
		if (move.cost < min_cost)
		{
			min_cost = move.cost;
			cheapest = move;
			cheapest.value = current->value;
		}
		current = current->next;
	}
	return (cheapest);
}
