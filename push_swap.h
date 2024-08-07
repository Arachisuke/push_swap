/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzeraig <wzeraig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 13:23:22 by wzeraig           #+#    #+#             */
/*   Updated: 2024/07/01 18:58:58 by wzeraig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define ERROR 1
# define RED "\033[0;31m"

# include "./GNL/get_next_line.h"
# include "./ft_printf/ft_printf.h"
# include "./libft/libft.h"
# include <stdio.h>
# include <stdlib.h>

typedef struct s_stack
{
	int				content;
	struct s_stack	*next;
	int				target_indice;
	int				previousnbr;
	int				indice;
	int				cost;
}					t_stack;

int					checkarg(int argc, char **argv);
char				**ft_split(char const *s, char c);
int					is_space(char *str);
int					checkspace(int argc, char **argv);
t_stack				*handle_one_input(t_stack **stack_a, char **argv, int j);
t_stack				*handle_input(t_stack **stack_a, char **argv);
long				ft_atoii(const char *str);
t_stack				*ft_last(t_stack *lst);
void				ft_back(t_stack **lst, t_stack *new);
t_stack				*ft_new(long value);
void				print_stack(t_stack **stack);
int					l_close(char *str, t_stack **stack);
void				compare(t_stack **stack, int nbr);
t_stack				*swap(t_stack **stack);
t_stack				*push(t_stack **stack_1, t_stack **stack_2);
void				ss(t_stack **stack_a, t_stack **stack_b);
t_stack				*sb(t_stack **stack);
t_stack				*sa(t_stack **stack_a);
void				rotate(t_stack **stack);
void				ft_front(t_stack **list, t_stack *new);
void				reverse_rotate(t_stack **stack);
void				rb(t_stack **stack_b);
void				ra(t_stack **stack_a);
void				rrb(t_stack **stack_b);
void				rra(t_stack **stack_a);
void				rrr(t_stack **stack_a, t_stack **stack_b);
void				pb(t_stack **stack_a, t_stack **stack_b);
void				pa(t_stack **stack_a, t_stack **stack_b);
void				rr(t_stack **stack_a, t_stack **stack_b);
void				init_node(t_stack **stack);

void				sort_three(t_stack **stack);
int					if_sorted(t_stack **stack);
int					ft_size(t_stack *lst);
void				choose_sort(t_stack **stack, t_stack **stack_b);
void				two_arg(t_stack **stack);
void				test1(t_stack **stack);
void				init_indice(t_stack **stack);
void				print_target_indice(t_stack **stack);
void				print_indice(t_stack **stack);

void				main_sort(t_stack **stack_a, t_stack **stack_b);
void				target_smallest(t_stack **stack_a, t_stack **stack_b);
void				target_biggest(t_stack **stack_a, t_stack **stack_b);
int					if_no_smallest(t_stack *tmp_a, t_stack **stack_b);
void				target_the_biggest(t_stack *tmp_a, t_stack **stack_b);
int					target_the_smallest(t_stack *tmp_b, t_stack **stack_a);
int					if_no_biggest(t_stack *tmp_b, t_stack **stack_a);
void				calcul_cost_same_a(t_stack *tmp, t_stack **stack_a,
						t_stack **stack_b);
void				calcul_cost_a(t_stack **stack_a, t_stack **stack_b);
void				calcul_cost_b(t_stack **stack_a, t_stack **stack_b);
void				calcul_cost_same_b(t_stack *tmp, t_stack **stack_a,
						t_stack **stack_b);

void				print_cost(t_stack **stack);
void				find_the_cheapest_a(t_stack **stack_a, t_stack **stack_b);
void				lets_sort_a(t_stack *tmp, t_stack **stack_a,
						t_stack **stack_b);
void				lets_sort_b(t_stack *tmp, t_stack **stack_a,
						t_stack **stack_b);
void				lets_sort_same(t_stack *tmp, t_stack **stack_a,
						t_stack **stack_b);
void				find_the_cheapest_b(t_stack **stack_a, t_stack **stack_b);
void				lets_sort_a_1(t_stack *tmp, t_stack **stack_a,
						t_stack **stack_b);
void				lets_sort_b_1(t_stack *tmp, t_stack **stack_a,
						t_stack **stack_b);

void				maj(t_stack **stack_a, t_stack **stack_b);
void				maj1(t_stack **stack_a, t_stack **stack_b);

void				lets_sort_same1(t_stack *tmp, t_stack **stack_a,
						t_stack **stack_b);

void				find_the_min(t_stack **stack);
void				sort_four(t_stack **stack_a, t_stack **stack_b);

void				command(t_stack **stack_a, t_stack **stack_b, char *cmd);
void				ft_free(char **strs);
void				free_stack(t_stack **stack);
void				command2(t_stack **stack_a, t_stack **stack_b, char *cmd);

#endif