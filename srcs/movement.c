/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macos <macos@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 09:30:44 by wzeraig           #+#    #+#             */
/*   Updated: 2024/06/30 20:56:49 by macos            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_stack	*swap(t_stack **stack)
{
	t_stack	*tmp;

	tmp = NULL;
	if (!*stack || !(*stack)->next)
		return (NULL);
	tmp = *stack;
	*stack = (*stack)->next;
	tmp->next = (*stack)->next;
	(*stack)->next = tmp;
	return (*stack);
}
t_stack	*sa(t_stack **stack_a)
{
	if (!*stack_a)
		return (NULL);
	*stack_a = swap(stack_a);
	ft_printf("sa\n");
	if (!stack_a)
		return (NULL);
	return (*stack_a);
}
t_stack	*sb(t_stack **stack)
{
	if (*stack == NULL)
		l_close("ERROR", stack);
	if (!*stack)
		return (NULL);
	*stack = swap(stack);
	if (!stack)
		return (NULL);
	ft_printf("sb\n");
	return (*stack);
}
void	ss(t_stack **stack_a, t_stack **stack_b)
{
	if (*stack_b == NULL)
		l_close("ERROR", stack_a);
	if (!*stack_a)
		return ;
	*stack_a = swap(stack_a);
	if (!*stack_a)
		return ;
	*stack_b = swap(stack_b);
	ft_printf("ss\n");
}
t_stack	*push(t_stack **stack_1, t_stack **stack_2)
{
	t_stack	*tmp;

	if (!stack_1)
		return (NULL);
	tmp = (*stack_1);
	*stack_1 = (*stack_1)->next;
	tmp->next = *stack_2;
	*stack_2 = tmp;
	return (*stack_2);
}
