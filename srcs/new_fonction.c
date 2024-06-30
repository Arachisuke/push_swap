/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_fonction.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macos <macos@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 20:40:19 by wzeraig           #+#    #+#             */
/*   Updated: 2024/06/30 20:57:16 by macos            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_size(t_stack *lst)
{
	int		i;
	t_stack	*actuel;

	actuel = lst;
	i = 0;
	while (actuel)
	{
		actuel = actuel->next;
		i++;
	}
	return (i);
}
void choose_sort(t_stack **stack, t_stack **stack_b)
{
	if (ft_size(*stack) == 2)
		two_arg(stack);
	else if  (ft_size(*stack) == 3)
		sort_three(stack);
	else if (ft_size(*stack) == 4)
		sort_four(stack, stack_b);
	else
		main_sort(stack, stack_b);
}
void two_arg(t_stack **stack)
{
	if ((*stack)->content > (*stack)->next->content)
		sa(stack);
}
void test1(t_stack **stack)
{
	while(*stack)
	{
		*stack = (*stack)->next; 
	}
}

void init_node(t_stack **stack)
{
	t_stack *actuel;
	int i;

	actuel = *stack;
	i = 1;
	while(actuel)
	{
		actuel->indice = i;
		actuel->target_indice = 0;
		actuel->previousnbr = 0;
		i++;
		actuel = actuel->next;
	}
}
