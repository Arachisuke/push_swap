/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_calcul.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzeraig <wzeraig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 19:23:50 by wzeraig           #+#    #+#             */
/*   Updated: 2024/07/01 19:00:38 by wzeraig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	calcul_cost_same_a(t_stack *tmp, t_stack **stack_a, t_stack **stack_b)
{
	int	test;

	test = 0;
	if (tmp->indice == 2 && tmp->target_indice == 2)
		tmp->cost = 1;
	else if (tmp->indice == ft_size(*stack_a)
		&& tmp->target_indice == ft_size(*stack_b))
		tmp->cost = 1;
	else if ((tmp->indice > ft_size(*stack_a) / 2 + 1
			&& tmp->target_indice > ft_size(*stack_b) / 2 + 1))
	{
		test = (ft_size(*stack_a) + 1) - tmp->indice;
		tmp->cost = (ft_size(*stack_b) + 1) - tmp->target_indice;
	}
	else if ((tmp->indice <= ft_size(*stack_a) / 2 + 1
			&& tmp->target_indice <= ft_size(*stack_b) / 2 + 1))
	{
		test = tmp->indice - 1;
		tmp->cost = tmp->target_indice - 1;
	}
	if (ft_size(*stack_b) == 2 && tmp->target_indice == 2
		&& tmp->indice > ft_size(*stack_a) / 2 + 1)
		tmp->cost = (ft_size(*stack_a) + 1) - tmp->indice;
	if (test > tmp->cost)
		tmp->cost = test;
}

void	calcul_cost_same_b(t_stack *tmp, t_stack **stack_a, t_stack **stack_b)
{
	int	test;

	test = 0;
	if (tmp->indice == 2 && tmp->target_indice == 2)
		tmp->cost = 1;
	else if ((tmp->indice == ft_size(*stack_b)
			&& tmp->target_indice == ft_size(*stack_a)))
		tmp->cost = 1;
	else if ((tmp->indice > ft_size(*stack_b) / 2 + 1
			&& tmp->target_indice > ft_size(*stack_a) / 2 + 1))
	{
		test = (ft_size(*stack_b) + 1) - tmp->indice;
		tmp->cost = (ft_size(*stack_a) + 1) - tmp->target_indice;
	}
	else if ((tmp->indice <= ft_size(*stack_b) / 2 + 1
			&& tmp->target_indice <= ft_size(*stack_a) / 2 + 1))
	{
		test = tmp->indice - 1;
		tmp->cost = tmp->target_indice - 1;
	}
	if (test > tmp->cost)
		tmp->cost = test;
}

void	calcul_cost_a(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp;

	tmp = *stack_a;
	while (tmp)
	{
		if (tmp->indice == 2)
			tmp->cost = 1;
		else if (tmp->indice > ft_size(*stack_a) / 2 + 1)
			tmp->cost = (ft_size(*stack_a) + 1) - tmp->indice;
		else if (tmp->indice <= ft_size(*stack_a) / 2 + 1)
			tmp->cost = tmp->indice - 1;
		if (tmp->target_indice == 2)
			tmp->cost = tmp->cost + 1;
		else if (tmp->target_indice > ft_size(*stack_b) / 2 + 1)
			tmp->cost = tmp->cost + (ft_size(*stack_b) + 1)
				- tmp->target_indice;
		else if (tmp->target_indice <= ft_size(*stack_b) / 2 + 1)
			tmp->cost = tmp->cost + tmp->target_indice - 1;
		calcul_cost_same_a(tmp, stack_a, stack_b);
		tmp = tmp->next;
	}
}

void	calcul_cost_b(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp;

	tmp = *stack_b;
	while (tmp)
	{
		if (tmp->indice == 2)
			tmp->cost = 1;
		else if (tmp->indice > ft_size(*stack_b) / 2 + 1)
			tmp->cost = (ft_size(*stack_b) + 1) - tmp->indice;
		else if (tmp->indice <= ft_size(*stack_b) / 2 + 1)
			tmp->cost = tmp->indice - 1;
		if (tmp->target_indice == 2)
			tmp->cost = tmp->cost + 1;
		else if (tmp->target_indice > ft_size(*stack_a) / 2 + 1)
			tmp->cost = tmp->cost + (ft_size(*stack_a) + 1)
				- tmp->target_indice;
		else if (tmp->target_indice <= ft_size(*stack_a) / 2 + 1)
			tmp->cost = tmp->cost + tmp->target_indice - 1;
		calcul_cost_same_b(tmp, stack_a, stack_b);
		tmp = tmp->next;
	}
}
