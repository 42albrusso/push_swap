/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushSwap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albrusso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 11:49:35 by albrusso          #+#    #+#             */
/*   Updated: 2023/02/02 16:17:55 by albrusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include "bonus/get_next_line/get_next_line.h"

typedef struct s_stack
{
	int					content;
	int					move_b;
	int					move_a;
	int					to_push;
	int					moves_for;
	struct s_stack		*next;
}				t_stack;

typedef struct s_value
{
	int		min;
	int		max;
	int		meta;
	int		ac;
	t_stack	*lst;

}				t_value;

t_stack		*ft_lstnew(int content);

t_stack		*ft_lstlast(t_stack *lst);

t_stack		*ft_penultimate(t_stack *lst);

int			ft_isorder(t_stack **lst);

int			ft_lstsize(t_stack *lst);

int			ft_three_numbers(t_value *a, int count);

int			ft_five_numbers(t_value *a, t_value *b);

int			ft_onehundred_numbers(t_value *a, t_value *b);

int			ft_while(t_stack *temp, int current, int count);

int			ft_sorted_sequence_two(t_stack *lst_a, int ret, int count);

int			ft_sorted_sequence(t_value *a);

int			ft_set_position_two(t_value *a, t_stack *b, t_stack *lst_a,
				t_stack *lst_b);

int			ft_set_position(t_value *a, t_stack *b, int lstsize);

int			ft_lst_findposition(t_stack *lst, int n);

int			ft_find_max(t_stack *lst);

int			ft_find_min(t_stack *lst);

int			ft_check_num(int ac, char *av[]);

int			ft_check_num_two(long int *a, char *av[], int ac);

int			ft_find_lis_two(t_value *b, t_stack *lst_b, int n, int top);

int			ft_find_lis(t_value *b);

int			ft_concorde(t_stack *lst_b);

int			ft_discorde(t_stack *lst_b);

long int	ft_atoi(const char *str);

void		ft_main(t_value *a, t_value *b, char *argv[]);

void		ft_sort(t_value *a, t_value *b, int number);

void		ft_refresh(t_value *a, t_value *b);

void		ft_minus_concorde_three(t_value *a, t_value *b, t_stack *lst_b);

void		ft_plus_concorde(t_value *a, t_value *b, t_stack *lst_b);

void		ft_minus_concorde(t_value *a, t_value *b, t_stack *lst_b);

void		ft_lstprint_tofirst(t_stack *lst);

void		ft_plus_concorde_two(t_value *a, t_value *b, t_stack *lst_b);

void		ft_plus_concorde_three(t_value *a, t_value*b, t_stack *lst_b);

void		ft_minus_concorde_two(t_value *a, t_value *b, t_stack *lst_b);

void		ft_plus_a(t_value *a, t_value *b, t_stack *lst_b);

void		ft_plus_b(t_value *a, t_value *b, t_stack *lst_b);

void		ft_lstadd_front(t_stack **lst, t_stack *new);

void		ft_lstadd_back(t_stack **lst, t_stack *new);

void		ft_lstprint(t_stack *lst);

void		ft_set_foraa(t_value *a, t_value *b, int lstsize);

void		ft_set_fora(t_value *a, t_value *b);

void		ft_tofirst(t_value *b);

void		ft_set_topush(t_value *a, int number);

void		ft_add_tob(t_value *a, t_value *b);

void		ft_five_numbers_sort(t_value *a, t_value *b, int count,
				t_stack *lst_b);

void		ft_fixlst(t_value *a);

void		sa(t_value	*a, int bool);

void		sb(t_value *b, int bool);

void		ss(t_value *a, t_value *b, int bool);

void		pa(t_value *a, t_value *b, int bool);

void		pb(t_value *a, t_value *b, int bool);

void		ra(t_value *a, int bool);

void		rb(t_value *b, int bool);

void		rr(t_value *a, t_value *b, int bool);

void		rra(t_value *a, int bool);

void		rrb(t_value *b, int bool);

void		rrr(t_value *a, t_value *b, int bool);

int			ft_execute_rules(char *rules, t_value *a, t_value *b);

int			ft_strcmp(char *s1, char *s2);

void		ft_free(t_stack *lst);

int			ft_read_rules(char *rules, t_value *a, t_value *b);

void		ft_add_lst(t_value *a, t_value *b, int argc, char *argv[]);

#endif
