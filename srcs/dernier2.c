/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dernier2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzeraig <wzeraig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 17:45:26 by macos             #+#    #+#             */
/*   Updated: 2024/07/01 19:46:04 by wzeraig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	find_the_cheapest_b(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp;
	t_stack	*actuel;
	int		smallestcost;

	actuel = *stack_b;
	smallestcost = actuel->cost;
	tmp = actuel;
	while (actuel)
	{
		if (actuel->cost < smallestcost)
		{
			smallestcost = actuel->cost;
			tmp = actuel;
		}
		actuel = actuel->next;
	}
	lets_sort_same1(tmp, stack_a, stack_b);
}

void	lets_sort_a_1(t_stack *tmp, t_stack **stack_a, t_stack **stack_b)
{
	int	test;

	if (tmp->target_indice == ft_size(*stack_a))
		rra(stack_a);
	else if (tmp->target_indice > ft_size(*stack_a) / 2 + 1)
	{
		test = (ft_size(*stack_a) + 1) - tmp->target_indice;
		while (test > 0)
		{
			rra(stack_a);
			test--;
		}
	}
	else if (tmp->target_indice <= ft_size(*stack_a) / 2 + 1)
	{
		test = tmp->target_indice - 1;
		while (test > 0)
		{
			ra(stack_a);
			test--;
		}
	}
	maj1(stack_a, stack_b);
	lets_sort_b_1(tmp, stack_a, stack_b);
}

void	lets_sort_b_1(t_stack *tmp, t_stack **stack_a, t_stack **stack_b)
{
	int	test;

	(void)stack_a;
	if (tmp->indice == ft_size(*stack_b) && tmp->indice > 1)
		rrb(stack_b);
	else if (tmp->indice > ft_size(*stack_b) / 2 + 1)
	{
		test = (ft_size(*stack_b) + 1) - tmp->indice;
		while (test > 0)
		{
			rrb(stack_b);
			test--;
		}
	}
	else if (tmp->indice <= ft_size(*stack_b) / 2 + 1)
	{
		test = tmp->indice - 1;
		while (test > 0)
		{
			rb(stack_b);
			test--;
		}
	}
	pa(stack_a, stack_b);
}

void	maj1(t_stack **stack_a, t_stack **stack_b)
{
	init_indice(stack_b);
	init_indice(stack_a);
	target_biggest(stack_a, stack_b);
}

void	find_the_min(t_stack **stack)
{
	t_stack	*tmp;
	int		indice;

	tmp = *stack;
	init_indice(stack);
	indice = target_the_smallest(tmp, stack);
	while (indice != 1)
	{
		if (indice <= ft_size(*stack) / 2 + 1)
			ra(stack);
		if (indice > ft_size(*stack) / 2 + 1)
			rra(stack);
		init_indice(stack);
		indice = target_the_smallest(tmp, stack);
	}
}
