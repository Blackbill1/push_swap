/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-dref <tle-dref@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 22:00:00 by tle-dref          #+#    #+#             */
/*   Updated: 2024/10/29 01:13:42 by tle-dref         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	exec_move_a(t_stack *a, t_move move)
{
	while (move.ra > 0)
	{
		ra(a);
		move.ra--;
	}
	while (move.rra > 0)
	{
		rra(a);
		move.rra--;
	}
}

void	exec_move_b(t_stack *b, t_move move)
{
	while (move.rb > 0)
	{
		rb(b);
		move.rb--;
	}
	while (move.rrb > 0)
	{
		rrb(b);
		move.rrb--;
	}
}

void	exec_move_rr(t_stack *a, t_stack *b, t_move move)
{
	while (move.rr > 0)
	{
		rr(a, b);
		move.rr--;
	}
	while (move.rrr > 0)
	{
		rrr(a, b);
		move.rrr--;
	}
}

void	exec_moves(t_stack *a, t_stack *b, t_move move)
{
	exec_move_rr(a, b, move);
	exec_move_a(a, move);
	exec_move_b(b, move);
	pb(a, b);
}

void	exec_moves_a(t_stack *a, t_stack *b, t_move move)
{
	exec_move_rr(a, b, move);
	exec_move_a(a, move);
	exec_move_b(b, move);
	pa(a, b);
}
