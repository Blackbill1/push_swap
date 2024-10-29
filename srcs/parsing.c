/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-dref <tle-dref@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 20:31:05 by tle-dref          #+#    #+#             */
/*   Updated: 2024/10/29 01:14:11 by tle-dref         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack *a)
{
	t_node	*current;

	current = a->top;
	while (current && current->next)
	{
		if (current->value > current->next->value)
			return (0);
		current = current->next;
	}
	return (1);
}

void	start(t_stack *a, t_stack *b)
{
	if (a->size > 3 && !is_sorted(a))
	{
		pb(a, b);
		b->max = b->top->value;
		b->min = b->top->value;
		pb(a, b);
		if (b->max < b->top->value)
			b->max = b->top->value;
		else
			b->min = b->top->value;
	}
}

int	checktab(int *tab, int end)
{
	int	i;
	int	n;

	n = 0;
	while (n < end)
	{
		i = n + 1;
		while (i < end)
		{
			if (tab[i] == tab[n])
				return (0);
			i++;
		}
		n++;
	}
	return (1);
}

int	multi_args(int argc, char **argv, int *tab)
{
	int		i;
	long	value;

	i = 1;
	while (i < argc)
	{
		value = ft_atol_scam(argv[i]);
		if (value == ERROR_VALUE)
		{
			return (0);
		}
		tab[i - 1] = (int)value;
		i++;
	}
	return (i - 1);
}

// int	one_arg(char **split, int *tab)
// {
// 	int		i;
// 	long	value;

// 	i = 0;
// 	while (split[i])
// 	{
// 		value = ft_atol_scam(split[i]);
// 		if (value == ERROR_VALUE)
// 		{
// 			return (0);
// 		}
// 		tab[i] = (int)value;
// 		//printf("%d\n", tab[i]);
// 		i++;
// 	}
// 	return (i);
// }
