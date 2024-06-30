/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_calcul2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macos <macos@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 20:28:42 by macos             #+#    #+#             */
/*   Updated: 2024/06/30 20:53:40 by macos            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h" 

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
int	if_no_biggest(t_stack *tmp_b, t_stack **stack_a)
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
void maj(t_stack **stack_a, t_stack **stack_b)
{
    init_indice(stack_a);
    target_smallest(stack_a, stack_b);
}
void init_indice(t_stack **stack)
{
	t_stack *actuel;
	int i;

	actuel = *stack;
	i = 1;
	while(actuel)
	{
		actuel->indice = i;
		i++;
		actuel = actuel->next;
	}
}

void sort_four(t_stack **stack_a, t_stack **stack_b)
{
	pb(stack_a, stack_b);
	sort_three(stack_a);
	target_biggest(stack_a, stack_b);
	find_the_cheapest_b(stack_a, stack_b);
	find_the_min(stack_a);
}