/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-dref <tle-dref@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 23:26:27 by tle-dref          #+#    #+#             */
/*   Updated: 2024/10/29 02:51:36 by tle-dref         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack *a)
{
	t_node	*max;
	t_node	*tmp;

	tmp = a->top;
	max = a->top;
	while (tmp)
	{
		if (tmp->value > max->value)
			max = tmp;
		tmp = tmp->next;
	}
	if (a->top == max)
		ra(a);
	else if (a->top->next == max)
		rra(a);
	if (a->top->value > a->top->next->value)
		sa(a);
}

void	sort(t_stack *a, t_stack *b)
{
	t_move	cheapest;

	while (a->size > 3 && !is_sorted(a))
	{
		cheapest = find_cheapest(a, b);
		exec_moves(a, b, cheapest);
	}
	if (a->size == 3)
		sort_three(a);
}

void	sort_back(t_stack *b, t_stack *a)
{
	t_move	cheapest_back;
	int		min_pos;

	while (b->size > 0)
	{
		cheapest_back = find_return(a, b);
		exec_moves_a(a, b, cheapest_back);
	}
	min_pos = find_min_pos(a);
	if (min_pos <= a->size / 2 && min_pos != 0)
	{
		while (min_pos--)
			ra(a);
	}
	else if (min_pos >= a->size / 2 && min_pos != 0)
	{
		min_pos = a->size - min_pos;
		while (min_pos--)
			rra(a);
	}
}
