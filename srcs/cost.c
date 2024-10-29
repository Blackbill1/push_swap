/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-dref <tle-dref@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 17:20:22 by tle-dref          #+#    #+#             */
/*   Updated: 2024/10/28 23:55:02 by tle-dref         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_max_position(t_stack *b)
{
	t_node	*current;
	int		max;
	int		max_pos;
	int		i;

	current = b->top;
	max = -2147483648;
	max_pos = 0;
	i = 0;
	while (current)
	{
		if (current->value > max)
		{
			max = current->value;
			max_pos = i;
		}
		current = current->next;
		i++;
	}
	return (max_pos);
}

int	find_nearest_lower_pos(int value, t_stack *b, int *closest_diff)
{
	t_node	*current;
	int		pos;
	int		i;

	current = b->top;
	pos = 0;
	i = 0;
	*closest_diff = 2147483647;
	while (current)
	{
		if (value > current->value && (value - current->value < *closest_diff))
		{
			pos = i;
			*closest_diff = value - current->value;
		}
		current = current->next;
		i++;
	}
	return (pos);
}

int	find_pos_b(int value, t_stack *b)
{
	int	closest_diff;
	int	nearest_lower_pos;
	int	max_pos;

	nearest_lower_pos = find_nearest_lower_pos(value, b, &closest_diff);
	if (closest_diff == 2147483647)
		max_pos = find_max_position(b);
	else
		max_pos = nearest_lower_pos;
	return (max_pos);
}

t_move	move_cost(t_stack *a, t_stack *b, int pos_b, int index)
{
	t_move	move;

	ft_memset(&move, 0, sizeof(t_move));
	if (index < a->size - index)
		move.ra = index;
	else
		move.rra = a->size - index;
	if (pos_b < b->size - pos_b)
		move.rb = pos_b;
	else
		move.rrb = b->size - pos_b;
	return (move);
}

t_move	efficient_move(t_move move)
{
	t_move	efficient;

	ft_memset(&efficient, 0, sizeof(t_move));
	while (move.ra > 0 && move.rb > 0)
	{
		move.ra--;
		move.rb--;
		efficient.rr++;
	}
	while (move.rra > 0 && move.rrb > 0)
	{
		move.rra--;
		move.rrb--;
		efficient.rrr++;
	}
	efficient.ra = move.ra;
	efficient.rb = move.rb;
	efficient.rra = move.rra;
	efficient.rrb = move.rrb;
	return (efficient);
}
