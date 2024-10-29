/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: koala-grille <koala-grille@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 00:34:21 by tle-dref          #+#    #+#             */
/*   Updated: 2024/10/28 16:31:08 by koala-grill      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "src/ft_printf.h"
#include <stdio.h>
#include <stdlib.h>

#define ERROR_VALUE 2147483648

typedef struct s_node
{
	int				value;
	struct s_node	*next;
	int 			index;
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
}					t_move;

int					ft_isdigit(int c);
long				ft_atol_scam(const char *str);
char				**ft_split(char const *s, char c);
int					one_arg(char **split, int *tab);
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

