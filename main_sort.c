/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macos <macos@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 13:46:42 by wzeraig           #+#    #+#             */
/*   Updated: 2024/06/26 20:30:40 by macos            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	main_sort(t_stack **stack_a, t_stack **stack_b)
{
	pb(stack_a, stack_b);
	pb(stack_a, stack_b); // push deux fois sans check
	init_node(stack_a);
	init_indice(stack_b); // j'init les positions
	while(ft_size(*stack_a) > 3)
	{
		maj(stack_a, stack_b);
		target_smallest(stack_a, stack_b);
		calcul_cost_a(stack_a, stack_b);
		find_the_cheapest_a(stack_a, stack_b); // il trouve le cheapest et trie
	}
	sort_three(stack_a);
	//print_stack(stack_b);
	while(ft_size(*stack_b) > 0)
	{
		maj1(stack_a, stack_b);
		//print_indice(stack_b);
		target_biggest(stack_a, stack_b); // peut etre de trp vu que je lutilise dans maj
		//print_target_indice(stack_b);
		calcul_cost_b(stack_a, stack_b);
		//print_cost(stack_b);
		find_the_cheapest_b(stack_a, stack_b);
	}
	find_the_min(stack_a);
	//print_stack(stack_a);
}
void	target_smallest(t_stack **stack_a, t_stack **stack_b)
// valider par la street
{
	t_stack *tmp_a;
	t_stack *tmp_b;
	int i;

	tmp_b = *stack_b;
	tmp_a = *stack_a;
	i = 1;
	while (tmp_a)
	{
		if (if_no_smallest(tmp_a, stack_b))
			target_the_biggest(tmp_a, stack_b);
		if ((tmp_a->content > tmp_b->content)
			&& (tmp_a->previousnbr <= tmp_b->content))
		{
			tmp_a->previousnbr = tmp_b->content;
			tmp_a->target_indice = i;
		}
		i++;
		// print_stack(stack_a);
		// print_stack(&tmp_b);
		tmp_b = tmp_b->next;
		if (!tmp_b && tmp_a)
		{
			tmp_b = *stack_b;
			tmp_a = tmp_a->next;
			i = 1;
		}
	}
}
void	target_biggest(t_stack **stack_a, t_stack **stack_b)
// valider par la street
{
	t_stack *tmp_a;
	t_stack *tmp_b;
	int i;

	tmp_b = *stack_b;
	tmp_a = *stack_a;
	i = 1;
	tmp_b->previousnbr = 2147483647;
	while (tmp_b)
	{
		if (if_no_biggest(tmp_b, stack_a))
			target_the_smallest(tmp_b, stack_a);
		if ((tmp_b->content < tmp_a->content)
			&& (tmp_b->previousnbr >= tmp_a->content))
		{
			tmp_b->previousnbr = tmp_a->content;
			tmp_b->target_indice = i;
		}
		tmp_a = tmp_a->next;
		i++;
		if (!tmp_a && tmp_b)
		{
			tmp_a = *stack_a;
			tmp_b = tmp_b->next;
			if (tmp_b)
				tmp_b->previousnbr = 2147483647;
			i = 1;
		}
	}
	//print_target_indice(stack_b);
}
int	if_no_smallest(t_stack *tmp_a, t_stack **stack_b)
{
	t_stack	*tmp_b;

	tmp_b = *stack_b;
	while (tmp_b)
	{
		if (tmp_a->content > tmp_b->content)
			return (0);
		tmp_b = tmp_b->next;
	}
	return (1);
}
void	target_the_biggest(t_stack *tmp_a, t_stack **stack_b)
// la je prend l'indice dans la chaine du plus grand
{
	t_stack *tmp_b;
	int biggestnumber;
	int i;

	tmp_b = *stack_b;
	biggestnumber = 0;
	i = 1;
	while (tmp_b)
	{
		if (tmp_b->content > biggestnumber)
		{
			biggestnumber = tmp_b->content;
			tmp_a->target_indice = i;
		}
		tmp_b = tmp_b->next;
		i++;
	}
}
int	target_the_smallest(t_stack *tmp_b, t_stack **stack_a)
{
	t_stack	*tmp_a;
	int		smallestnumber;
	int		i;

	tmp_a = *stack_a;
	smallestnumber = tmp_b->content;
	i = 1;
	while (tmp_a)
	{
		if (tmp_a->content < smallestnumber)
		{
			smallestnumber = tmp_a->content;
			tmp_b->target_indice = i;
		}
		i++;
		tmp_a = tmp_a->next;
	}
	return(tmp_b->target_indice);
}
int	if_no_biggest(t_stack *tmp_b, t_stack **stack_a) // dans la chaine a
{
	t_stack *tmp_a;

	tmp_a = *stack_a;
	while (tmp_a)
	{
		if (tmp_b->content < tmp_a->content)
			return (0);
		tmp_a = tmp_a->next;
	}
	return (1);
}
