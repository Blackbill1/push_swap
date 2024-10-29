/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   return.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-dref <tle-dref@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 00:02:10 by tle-dref          #+#    #+#             */
/*   Updated: 2024/10/29 01:15:50 by tle-dref         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_min_pos(t_stack *a)
{
	t_node	*current;
	int		min;
	int		min_pos;
	int		i;

	current = a->top;
	min = 2147483647;
	min_pos = 0;
	i = 0;
	while (current)
	{
		if (current->value < min)
		{
			min = current->value;
			min_pos = i;
		}
		current = current->next;
		i++;
	}
	return (min_pos);
}

int	find_upper_pos(int value, t_stack *a, int *closest_diff)
{
	t_node	*current;
	int		pos;
	int		i;

	current = a->top;
	pos = 0;
	i = 0;
	*closest_diff = 2147483647;
	while (current)
	{
		if (value < current->value && (current->value - value < *closest_diff))
		{
			pos = i;
			*closest_diff = current->value - value;
		}
		current = current->next;
		i++;
	}
	return (pos);
}

int	find_pos_a(int value, t_stack *a)
{
	int	closest_diff;
	int	nearest_lower_pos;
	int	min_pos;

	nearest_lower_pos = find_upper_pos(value, a, &closest_diff);
	if (closest_diff == 2147483647)
		min_pos = find_min_pos(a);
	else
		min_pos = nearest_lower_pos;
	return (min_pos);
}

t_move	move_cost_a(t_stack *a, t_stack *b, int pos_a, int index)
{
	t_move	move;

	ft_memset(&move, 0, sizeof(t_move));
	if (pos_a < a->size - pos_a)
		move.ra = pos_a;
	else
		move.rra = a->size - pos_a;
	if (index < b->size - index)
		move.rb = index;
	else
		move.rrb = b->size - index;
	return (move);
}

t_move	find_return(t_stack *a, t_stack *b)
{
	int		min_cost;
	t_move	cheapest;
	t_node	*current;
	t_move	move;
	int		pos_a;

	pos_a = 0;
	min_cost = 2147483647;
	current = b->top;
	ft_memset(&cheapest, 0, sizeof(t_move));
	assign_indices(b);
	while (current)
	{
		pos_a = find_pos_a(current->value, a);
		move = move_cost_a(a, b, pos_a, current->index);
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
