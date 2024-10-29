/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-dref <tle-dref@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 17:49:01 by tle-dref          #+#    #+#             */
/*   Updated: 2024/10/29 03:04:31 by tle-dref         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*init_stack(void)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	stack->top = NULL;
	stack->size = 0;
	return (stack);
}

void	fill_stack(t_stack *stack, int value)
{
	t_node	*new_node;

	new_node = malloc(sizeof(t_node));
	if (!new_node)
		return ;
	new_node->value = value;
	new_node->next = stack->top;
	stack->top = new_node;
	stack->size++;
}

void	free_stack(t_stack *stack)
{
	t_node	*current;
	t_node	*next;

	if (stack == NULL)
		return ;
	current = stack->top;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
	free(stack);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	int		*tab;
	int		index;

	index = 0;
	tab = malloc(sizeof(int) * argc);
	if (argc == 1)
		return (free(tab), 0);
	else if (argc >= 2)
		index = multi_args(argc, argv, tab);
	if (index == 0 || !checktab(tab, index))
		return (ft_putendl_fd("Error", 2), free(tab), 0);
	a = init_stack();
	b = init_stack();
	while (index--)
		fill_stack(a, tab[index]);
	start(a, b);
	sort(a, b);
	sort_back(b, a);
	free_stack(a);
	free_stack(b);
	free(tab);
}
