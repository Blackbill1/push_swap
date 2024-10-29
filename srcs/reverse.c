/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-dref <tle-dref@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 01:53:52 by tle-dref          #+#    #+#             */
/*   Updated: 2024/10/29 01:46:06 by tle-dref         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse(t_stack *stack)
{
	t_node	*prev_last;
	t_node	*last;
	t_node	*tmp;

	tmp = stack->top;
	while (tmp->next)
		tmp = tmp->next;
	last = tmp;
	tmp = stack->top;
	while (tmp->next->next)
		tmp = tmp->next;
	prev_last = tmp;
	last->next = stack->top;
	prev_last->next = NULL;
	stack->top = last;
}

void	rra(t_stack *a)
{
	reverse(a);
	write(1, "rra\n", 4);
}

void	rrb(t_stack *b)
{
	reverse(b);
	write(1, "rrb\n", 4);
}

void	rrr(t_stack *a, t_stack *b)
{
	reverse(a);
	reverse(b);
	write(1, "rrr\n", 4);
}
