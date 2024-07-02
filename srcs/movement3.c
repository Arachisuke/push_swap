/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzeraig <wzeraig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 20:30:56 by macos             #+#    #+#             */
/*   Updated: 2024/07/01 19:23:03 by wzeraig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rr(t_stack **stack_a, t_stack **stack_b)
{
	if (*stack_b == NULL)
		l_close("ERROR", stack_a);
	rotate(stack_a);
	rotate(stack_b);
	ft_printf("rr\n");
}

void	reverse_rotate(t_stack **stack)
{
	t_stack	*tmp;

	tmp = *stack;
	while (tmp->next->next)
	{
		tmp = tmp->next;
	}
	ft_front(stack, tmp->next);
	tmp->next = NULL;
}

void	rra(t_stack **stack_a)
{
	reverse_rotate(stack_a);
	ft_printf("rra\n");
}

void	rrb(t_stack **stack_b)
{
	if (*stack_b == NULL)
		l_close("ERROR", stack_b);
	reverse_rotate(stack_b);
	ft_printf("rrb\n");
}

void	rrr(t_stack **stack_a, t_stack **stack_b)
{
	if (*stack_b == NULL)
		l_close("ERROR", stack_a);
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	ft_printf("rrr\n");
}
