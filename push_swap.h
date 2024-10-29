/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-dref <tle-dref@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 00:34:21 by tle-dref          #+#    #+#             */
/*   Updated: 2024/10/29 01:07:39 by tle-dref         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/ft_printf.h"
#include <stdio.h>
#include <stdlib.h>

#define ERROR_VALUE 2147483648

typedef struct s_node
{
	int				value;
	struct s_node	*next;
	int				index;
}					t_node;

typedef struct s_stack
{
	t_node			*top;
	int				size;
	int				min;
	int				max;
}					t_stack;

typedef struct s_move
{
	int				pa;
	int				pb;
	int				ra;
	int				rb;
	int				rr;
	int				sa;
	int				sb;
	int				ss;
	int				rra;
	int				rrb;
	int				rrr;
	int				cost;
	int				value;
}					t_move;

int					ft_isdigit(int c);
long				ft_atol_scam(const char *str);
char				**ft_split(char const *s, char c);
int					multi_args(int argc, char **argv, int *tab);
int					checktab(int *tab, int end);
void				swap(t_stack *stack);
void				sa(t_stack *a);
void				sb(t_stack *b);
void				ss(t_stack *a, t_stack *b);
void				push(t_stack *stack1, t_stack *stack2);
void				pa(t_stack *a, t_stack *b);
void				pb(t_stack *a, t_stack *b);
void				rotate(t_stack *stack);
void				ra(t_stack *a);
void				rb(t_stack *b);
void				rr(t_stack *a, t_stack *b);
void				reverse(t_stack *stack);
void				rra(t_stack *a);
void				rrb(t_stack *b);
void				rrr(t_stack *a, t_stack *b);
int					find_pos_b(int value, t_stack *b);
void				start(t_stack *a, t_stack *b);
t_move				efficient_move(t_move move);
t_move				move_cost(t_stack *a, t_stack *b, int pos_b, int index);
int					find_pos_b(int value, t_stack *b);
int					total_move_cost(t_move move);
t_move				find_cheapest(t_stack *a, t_stack *b);
void				exec_moves(t_stack *a, t_stack *b, t_move move);
void				exec_moves_a(t_stack *a, t_stack *b, t_move move);
void				sort_three(t_stack *a);
void				sort(t_stack *a, t_stack *b);
int					is_sorted(t_stack *a);
void				sort_back(t_stack *b, t_stack *a);
int					find_pos_a(int value, t_stack *a);
void				assign_indices(t_stack *a);
t_move				find_return(t_stack *a, t_stack *b);
t_move				move_cost_a(t_stack *a, t_stack *b, int pos_a, int index);
int					find_min_pos(t_stack *a);
void				*ft_memset(void *s, int c, size_t n);
void				ft_putendl_fd(char *s, int fd);
void				ft_putstr_fd(char *s, int fd);
