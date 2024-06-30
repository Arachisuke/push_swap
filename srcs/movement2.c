/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macos <macos@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 20:28:21 by macos             #+#    #+#             */
/*   Updated: 2024/06/30 20:56:59 by macos            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	pa(t_stack **stack_a, t_stack **stack_b)
{
	if (*stack_b == NULL)
		l_close("ERROR", stack_a);
	push(stack_b, stack_a);
	ft_printf("pa\n");
}
void	pb(t_stack **stack_a, t_stack **stack_b)
{
	if (*stack_a == NULL)
		return ;
	push(stack_a, stack_b);
	ft_printf("pb\n");
}
void	rotate(t_stack **stack)
{
	t_stack	*tmp;

	tmp = *stack;
	*stack = (*stack)->next;
	tmp->next = NULL;
	ft_back(stack, tmp);
}
void	ra(t_stack **stack_a)
{
	rotate(stack_a);
	ft_printf("ra\n");
}
void	rb(t_stack **stack_b)
{
	if (*stack_b == NULL)
		l_close("ERROR", stack_b) ;
	rotate(stack_b);
	ft_printf("rb\n");
}