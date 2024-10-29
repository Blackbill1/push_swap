/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-dref <tle-dref@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 00:05:35 by tle-dref          #+#    #+#             */
/*   Updated: 2024/10/29 01:15:08 by tle-dref         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack *stack1, t_stack *stack2)
{
	t_node	*tmp;

	if (!stack1->top)
		return ;
	tmp = stack2->top;
	stack2->top = stack1->top;
	stack1->top = stack1->top->next;
	stack2->top->next = tmp;
	stack1->size--;
	stack2->size++;
}

void	pa(t_stack *a, t_stack *b)
{
	push(b, a);
	write(1, "pa\n", 3);
}

void	pb(t_stack *a, t_stack *b)
{
	push(a, b);
	write(1, "pb\n", 3);
}
